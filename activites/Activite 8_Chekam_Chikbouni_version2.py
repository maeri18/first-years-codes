#Activite 8
#Partie Guidee
def ouvre_fichier(nom:str)->List[str]:
    """renvoie la liste des lignes du fichier texte ./nom.csv"""
    with open("./"+nom+".csv","r") as f:
        return f.readlines()


exemple1 : List[str] = ['"sport";"date";"participants";"vainqueur"\n', '"boxe";2021-09-18;12;"Alice"\n', '"boxe";2021-09-25;10;"Alice"\n', '"karate";2021-09-26;19;"Carole"\n', '"boxe";2021-10-02;8;"Bob"\n', '"karate";2021-10-03;20;"Carole"\n', '"tennis";2021-10-04;3;"Alice"\n', '"boxe";2021-10-09;5;"Alice"\n', '"karate";2021-10-10;20;"Damien"\n', '"boxe";2021-10-16;6;"Carole"\n', '"echecs";2021-09-17;120;"Bob"\n', '"echecs";2021-09-24;120;"Bob"\n', '"echecs";2021-10-01;120;"Carole"\n']

#Question 1
def decompose_ligne(li:str, sep:str)->List[str]:
    """precondition : len(sep)==1
renvoie le decoupage de la chaine de caracteres li selon le caractere separateur sep"""
    lres:List[str]=[]
    car:str=""
    i:str
    for i in li:
        if i!=sep:
            car = car + (i)
        else :
            lres.append(car)
            car=""

    lres.append(car[:-1])
    return lres
assert decompose_ligne(exemple1[0],";")==['"sport"','"date"','"participants"','"vainqueur"']
assert decompose_ligne(exemple1[3],";")==['"karate"','2021-09-26','19','"Carole"']
assert decompose_ligne(exemple1[3],",")==['"karate";2021-09-26;19;"Carole"']
        
#Question 2
def enleve_guillemets(s:str)->str:
    """Enleve de s les guillemets"""
    res:str=""
    i:str
    for i in s:
        if i!='"':
            res=res+i
    return res

assert enleve_guillemets('"sport"')=='sport'
assert enleve_guillemets('sport')=='sport'

#Question 3
def enleve_guillemets_ligne(li:List[str])->List[str]:
    """enleve les guillemets dans la liste li"""
    return [enleve_guillemets(k) for k in li]
assert enleve_guillemets_ligne(['"sport"','"date"','"participants"','"vainqueur"'])==['sport','date','participants','vainqueur']
assert enleve_guillemets_ligne(['"karate"','2021-09-26','19','"Carole"'])==['karate','2021-09-26','19','Carole']

#Question 4
def lignes_propres(lis:List[str],sep:str)->List[List[str]]:
    """precondition: len(sep)==1
renvoie la liste de chaines de caracteres correspondant a la decomposition de chacune des lignes de lis dans laquelle on a enleve les guillemets de chaque element"""
    return[ enleve_guillemets_ligne(decompose_ligne(k,sep)) for k in lis]

assert lignes_propres(exemple1,";")== [['sport', 'date', 'participants', 'vainqueur'],
                                       ['boxe', '2021-09-18', '12', 'Alice'],
                                       ['boxe', '2021-09-25', '10', 'Alice'],
                                       ['karate', '2021-09-26', '19', 'Carole'],
                                       ['boxe', '2021-10-02', '8', 'Bob'],
                                       ['karate', '2021-10-03', '20', 'Carole'],
                                       ['tennis', '2021-10-04', '3', 'Alice'],
                                       ['boxe', '2021-10-09', '5', 'Alice'],
                                       ['karate', '2021-10-10', '20', 'Damien'],
                                       ['boxe', '2021-10-16', '6', 'Carole'],
                                       ['echecs', '2021-09-17', '120', 'Bob'],
                                       ['echecs', '2021-09-24', '120', 'Bob'],
                                       ['echecs', '2021-10-01', '120', 'Carole']]

lignes_ex1:List[List[str]]= lignes_propres(exemple1,";")    
#Question 5
def cherche_indice(e:T, li:List[T])->Optional[int]:
    """renvoie le premier indice de li auquel apparait e si e est dans li, et None si e n'est pas dans li"""
    i:int
    for i in range(len(li)):
        if li[i]==e:
            return i
    return None

assert cherche_indice("sport",['sport','date','participants','vainqueur'])==0
assert cherche_indice("vainqueur",['sport','date','participants','vainqueur'])==3
assert cherche_indice("vie",['sport','date','participants','vainqueur'])==None

#Question 6
def dictionnaire_compte(lis:List[List[str]],clef:str)->Dict[str,int]:
    """Precondition: clef doit etre une colonne du fichier"""
    i:Optional[int]
    i=cherche_indice(clef,lis[0])
    j:List[str]
    if i==None:
        return dict()
    else:
        di_res:Dict[str,int]={lis[1][i]:1}
        for j in lis[2:]:
            if j[i] in di_res:
            
                di_res[j[i]]=di_res[j[i]] + 1
            else:
                     di_res[j[i]]=1
        return di_res
                
assert dictionnaire_compte(lignes_ex1,"vainqueur")=={'Alice': 4, 'Carole': 4, 'Bob': 3, 'Damien': 1}
assert dictionnaire_compte(lignes_ex1,"sport")=={"boxe":5,"karate":3,"tennis":1,"echecs":3}

#Question 7
def dictionnaire_somme(lis:List[List[str]], clef:str, valeur:str)->Dict[str,int]:
    """Precondition: valeur et clef doivent etre des colonnes de lis
        precondition: les donnees de valeur doivent etre des nombres (entiers)
        renvoie le dictionnaire dont les clefs sont les donnees de la colonne clef du fichier et la valeur associe a la clef k est la somme des donnees de la colonne valeur des lignes ou k apparait dans la colonne clef"""
    i:Optional[int]= cherche_indice(clef,lis[0])
    j:Optional[int]= cherche_indice(valeur,lis[0])
    k:List[str]
    if  i== None or j ==None:
        return dict()
    else:
        dico:Dict[str,int]=dict()
        for k in lis[1:]:
            if k[i] in dico:
                dico[k[i]]=dico[k[i]] + int(k[j])
            else:
                dico[k[i]]=int(k[j])
            
        return dico
assert dictionnaire_somme(lignes_ex1,"sport","participants")== {'boxe': 41, 'karate': 59, 'tennis': 3, 'echecs': 360}


#Suggestion : Courbes temporelles
#On cossiderera pour la suite qu'une date est une chaine de caractere sous la forme AAAA-MM-JJ

def date(d:str)->Tuple[int,int,int]:
    """ converti une date str en triplet (annee, mois, jour)"""
    return(int(d[:4]),int(d[5:7]),int(d[8:]))
    
def duree(d0:str, d1:str)->int:
    """Renvoie en nombre de jour la duree entre d1 et d0, en considerant que chaque mois a 30 jours, et une annee a 365 jours"""
    a1,m1,j1=date(d1)
    a0,m0,j0=date(d0)
    nb:int=(a1-a0)*365+(m1-m0)*30+j1-j0
    #if nb<0:
     #   return 0
    #else:
    return nb


def dic_valeur_duree(d:Dict[str,int])->Dict[int,int]:
    """ """
    a0:int
    m0:int
    j0:int
    c:str
    c0:str
    c1:str
    dico:Dict[int,int]=dict()
    first:bool = True
    for c in d:
        if first==True:
            c0=c
            first=False
        else:
            if duree(c0,c)<0:
                c0=c
    for c1 in d:
        dico[duree(c0,c1)]=d[c1]
    return dico

def dic_list(d:Dict[int,int])->List[Tuple[int,int]]:
    """  """
    return [(cle,val) for (cle,val) in d.items()]
def tri(L:List[Tuple[int,int]])->List[Tuple[int,int]]:
    """ """
    if L==[]:
        return []
    else:
        dur_min,val_min=L[0]
        dur:int
        i:int
        j:int=0
        for i in range(1,len (L)):
            dur,val=L[i]
            if dur<dur_min:
                dur_min=dur
                val_min=val
                j=i
        return [(dur_min,val_min)]+tri(L[:j]+L[j+1:])
    
def v_max(L:List[Tuple[int,int]])->int:
    """ """
    _,max1=L[0]
    for _,val in L:
        if val > max1:
            max1=val
    return max1
def conver_coord(L:List[Tuple[int,int]])->List[Tuple[float,float]]:
    """ """
    lres:List[Tuple[float,float]]=[]
    dur_max,_=L[-1]
    val_max:int=v_max(L)
    for dur,var in L:
        lres.append((dur*2/dur_max-1,var*2/val_max-1))
    return lres

def courbe(L:List[Tuple[float,float]])->Image:
    """ """
    x2,y2=L[1]
    x1,y1=L[0]
    i:int
    Im:Image=draw_line(x1,y1,x2,y2)
    for i in range (1,len(L)-1):
        a1,b1=L[i]
        a2,b2=L[i+1]
        Im=overlay(Im,draw_line(a1,b1,a2,b2))
    return Im
dicr:Dict[str,int]=dictionnaire_somme(lignes_ex1,"date","participants")
dicr1:Dict[int,int]=dic_valeur_duree(dicr)
L1:List[Tuple[int,int]] =  dic_list(dicr1)            
L2:List[Tuple[int,int]]=tri(L1)           
L3:List[Tuple[float,float]]=conver_coord(L2)      
I:Image = courbe(L3)
show_image(I)

        
        
        
    
    
    
    




        
        
        
        


        
           
            
    
    
    



