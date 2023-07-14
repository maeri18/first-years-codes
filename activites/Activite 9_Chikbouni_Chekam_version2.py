#Activite 9
ponctuation : Set[str]={" ", ",", ";", "'", "(", ")", ".", "!","?",":"}
# Partie Guidee

def ouvre_fichier(nom:str)->List[str]:
    """renvoie la liste des lignes du fihier texte ./nom.txt"""
    with open("./"+nom+".txt","r",encoding = "utf-8") as f:
        return f.readlines()

exemple1:List[str]=ouvre_fichier("beaute")
#Question 1
def decompose_ligne(li:str, sep:Set[str])->List[str]:
    """Renvoie une liste de chaines de caracteres correspondant au decoupage de li selon le caractere sep"""
    c:str
    mot:str=''
    lres:List[str]=[]
    for c in li:
        if c not in sep and c!="\n":
            mot=mot+c
        elif mot!='':
                lres.append(mot)
                mot=''
    return lres



assert decompose_ligne(exemple1[0],ponctuation)==['Je','suis','belle', 'ô','mortels','comme','un','rêve','de','pierre']
assert decompose_ligne(exemple1[4], ponctuation)==[]
assert decompose_ligne(exemple1[8],ponctuation)==['Et','jamais','je','ne','pleure','et','jamais','je','ne','ris']


#Question 2
def minusculise(m:str)->str:
    """ """
    c:str
    res:str=''
    for c in m:
        if ord('A')<=ord(c) and ord(c)<=ord('Z'):
            res=res+chr(((ord(c)-ord('A'))+ord('a')))
        else:
            res=res+c
    return res
assert minusculise("bonjour")=="bonjour"
assert minusculise("BONJOUR")=="bonjour"
assert minusculise("Bonjour")=="bonjour"

#Question 3
def mots(lis:List[str], sep:Set[str])->List[str]:
    """ renvoie la liste des mots de lis (en minuscule)"""
    return [minusculise(a) for l in lis
                                for a in decompose_ligne(l,sep)]
assert mots(exemple1,ponctuation)[:15]==['je', 'suis', 'belle', 'ô', 'mortels', 'comme', 'un', 'rêve', 'de', 'pierre', 'et', 'mon', 'sein', 'où', 'chacun']

#Question 4
def dictionnaire_occ_mots(ms:List[str])->Dict[str,int]:
    """ construit le dictionnaire dont les cles sont les mots de ms, et les valeurs sont les occurences des mots de ms"""
    c:str
    dico:Dict[str,int]=dict()
    for c in ms:
        if c in dico:
            dico[c]=dico[c]+1
        else:
            dico[c]=1
    return dico

dico1:Dict[str,int]=dictionnaire_occ_mots(mots(exemple1,ponctuation))
assert dico1['je']==5
assert dico1['belle']==1
assert dico1['jamais']==2

#Question 5
def hapax(d:Dict[str,int])->Set[str]:
    """ Renvoie l'ensemble des happax de d"""
    return {a for a in d if d[a]==1}
assert len(hapax(dico1))==67
assert ("sphinx" in hapax(dico1)) == True
assert ("Jamais" in hapax(dico1)) == False
            
#Question 6
def max_list(L:List[int])->int:
    """precondition:len(L)>0
Fonction qui envoie le maximum d'une liste non vide d'entiers"""
    max:int=L[0]
    c:int
    for c in L:
        if c> max:
            max=c
    return max

def plus_frequent(d:Dict[str,int])->str:
    """ precondition : d!=dict()"""
    L_val : List[int]=[val for (cle,val) in d.items()]
    val:str
    val1:str
    for val1 in d:
        if  d[val1]== max_list(L_val):
            return val1
assert plus_frequent(dico1)=='je'

#Suggestion : Comparaison de frequences

#Question 1
def dictionnaire_freqs_mots(ms:List[str])->Dict[str,float]:
    """precondition:len(ms)>0
renvoie le dictionnaire de frequences des mots de ms"""
    c:str
    dico:Dict[str,float]= dictionnaire_occ_mots(ms)
    for c in ms:
        dico[c]=dico[c]/len(ms)
    return dico

dico2:Dict[str,float]=dictionnaire_freqs_mots(mots(exemple1,ponctuation))
assert dico2["belle"] == 0.008130081300813009
            
#Question 2

def distance_freq(d1:Dict[str,float],d2:Dict[str,float])->float:
    """calcule la distance de d1 a d1"""
    score:float=100
    c:str
    for c in d2:
        if c in d1:
            score=score-100*abs(d1[c]-d2[c])
        else:
            score=score-100*d2[c]
    return score

#Suggestion : Auteur d'un texte

#Question 1
def jointure_dict_freq(d1:Dict[str,float],d2:Dict[str,float],l1:int,l2:int)->Dict[str,float]:
    """precondition: (l1 + l2)>0 """
    d:Dict[str,float]=dict()
    m1:str
    m2:str
    for m1 in d1:
        if m1 in d2:
            d[m1]=(d1[m1]*l1 + d2[m1]*l2 )/(l1+l2)
        else:
            d[m1]= d1[m1]*l1/(l1+l2)
    for m2 in d2:
        if m2 not in d:
            d[m2] = d2[m2]*l2/(l1+l2)
    return d

assert jointure_dict_freq({"je":(3/17),"une":(2/17),"tu":(8/17),"ananas":(4/17)},{"une":(2/10),"ananas":(8/10)},17,10)=={"je":(3/27),"une":(4/27),"tu":(8/27),"ananas":(12/27)}


#Question 2
def dict_auteur(li:List[str])->Dict[str,float]:
    """precondition: li doit etre une liste de noms de fichiers existants"""
    sep : Set[str]={" ", ",", ";", "'", "(", ")", ".", "!","?",":"}
    dico:Dict[str,float]=dict()
    name:str
    l1:int=0
    d2:Dict[str,float]=dict()
    l2:int=0
    for name in li:
        d2=dictionnaire_freqs_mots(mots(ouvre_fichier(name),sep))
        l2=len(mots(ouvre_fichier(name),sep))
        dico=jointure_dict_freq(dico,d2,l1,l2)
        l1=len(dico)
    return dico
baudelaire: Dict[str,float] = dict_auteur(["beaute","spleen","albatros"])


