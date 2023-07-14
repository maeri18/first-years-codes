#exercice5.6:
#q1
def base_comp(B:str)->str:
    """precondition: len(B)==1
    precondition: B=="A" or B=="G" or B=="T" or B=="C"
    renvoie la base azotee complementaire a une base B donnee"""
    
    if B=="A":
        return "T"
    elif B=="G":
        return "C"
    elif B=="T":
        return "A"
    else:
        return "G"
#JEU DE TESTS
assert base_comp("A")=="T"
assert base_comp("C")=="G"
assert base_comp("T")=="A"
assert base_comp("G")=="C"

#Q2
def brin_comp(brin:str)->str:
    """renvoie le brin complémentaire """
    s :str = ""
    i :int #variable d'iteration de la boucle for
    for i in range(len(brin)):
        s = base_comp(brin[i]) + s 
    return s
#JEU DE TESTS
assert brin_comp("ATCG") == "CGAT"
assert brin_comp("ATTGCCGTATGTATTGCGCT")=="AGCGCAATACATACGGCAAT"
        
#Q3
def test_comp(b1 : str, b2:str) -> bool :
    """teste si deux brins sont complementaires
"""
    if len(b1)==len(b2):#La premiere condition pour que deux brins soient complementaires est qu'ils aient la meme longueur
        if b1==brin_comp(b2):
            return True
        else :
            return False
    else:
        return False
#JEU DE TESTS
assert test_comp('','')==True
assert test_comp('','ATCG')==False
assert test_comp('ATCG','')==False
assert test_comp('ATCG','CGAT')==True
assert test_comp('ATCG','TAAG')==False
        
#Q4:
def test_sous_sequence(sch : str, ch:str) -> bool:
    """Teste si sch est une sous sequence de ch
"""
    
    i : int#variable d'iteration
    if len(sch)<=len(ch):#la premiere condition pour que sch soit une sous sequence de ch est que la longueur de sch est inferieure a celle de ch
        for i in range(0, len(ch)+1-len(sch)):
            if ch[i:len(sch)+i] == sch :
                return True
        return False
    else:
        return False
#JEU DE TESTS   
assert test_sous_sequence('','')== True
assert test_sous_sequence('','ATCG')== True
assert test_sous_sequence('ATCG','')== False
assert test_sous_sequence('GC','TAGC')== True
assert test_sous_sequence('GC','TAAG')== False

    
#question 5
def recherche_sous_sequence(sch : str, ch:str)-> Optional[int]:
    """ renvoie l'indice de la premiere fois où la séquence sch apparait dans ch"""
    i : int#variable d'iteration
    for i in range(0, len(ch)+1-len(sch)):
        if ch[i:len(sch)+i] == sch :
            return i
    return None
#JEU DE TESTS
assert recherche_sous_sequence('','') == 0
assert recherche_sous_sequence('','ATCG') == 0
assert recherche_sous_sequence('ATCG','') == None
assert recherche_sous_sequence('GC','TAGC') == 2
assert recherche_sous_sequence('GC','TAAC') == None

#exercice 5.7

#question1
def chiffre(c:str)->int:
    """précondition : len(c) == 1
précondition : '0' <= c<='9'
"""
    return ord(c)-ord('0') 
#JEU DE TESTS
assert chiffre('5')==5
assert chiffre('0')==0
assert chiffre('7')==7
assert chiffre('1')==1

#question2
def entier(s:str)->int:
    """ retourne l'entier represente par la chaine s"""
    c : str#variable d'iteration
    somme : int = 0#contiendra en fin de boucle l'entier representé par la chaine de caractere c
    for c in s :
        somme = chiffre(c) + (somme) * 10 
    return somme
#JEU DE TESTS
assert entier('9') == 9
assert entier('42')== 42
assert entier('122') == 122

#question3
# specification pour chr : def chr(n : int) -> str:
# """ renvoie le caaractere de code unicode n"""
 #fonction caractere
def caractere(n:int)->str:
    """précondition : 0 <= n<= 9
Renvoie le caractere correspondant au chiffre passé en paramètre"""
    return chr(ord('0')+n)
#JEU DE TESTS
assert caractere(4) == '4'
assert caractere(1) == '1'
assert caractere(9) == '9'
assert caractere(7) == '7'

#question 4
def chaine(n:int)->str:
    """precondition : 0<=n
renvoie la chaine de caractère correspondant au nombre entier entré""" 
    nbre:int=n
    i:int
    j:int=1
    compteur :int=0
    res:str=''
    if nbre==0:
        return '0'
    while nbre!=0:
        compteur=0
        i=1
        while i!=10 and (nbre%10**j)!=0 :
            if (nbre%10**j)!=0:
                nbre = nbre - 1*10**(j-1)
                compteur = compteur +1
            i=i+1
        j=j+1
        res = caractere(compteur) + res
    return res
#JEU DE TESTS        
assert chaine(9)=='9'
assert chaine(0)=='0'
assert chaine(122)=='122'
assert entier(chaine(122)) == 122


#exercice 5.8

#algorithme permettant de reconnaitre si un caractere est une chiffre
def est_chiffre(c:str)->bool:
    """precondition: len(c)==1
Retourne True si et seulement si c est un chiffre"""
    return ('0'<=c) and (c<='9')
#jeu de tests
assert est_chiffre('4') == True
assert est_chiffre('9') == True
assert est_chiffre('x') == False

#question 1
def decompression(s:str)->str:
    """remplace toute sous-chaine de s de la forme nc ou n est un entier naturel et c un caractere, en n fois le caractere c"""
    c:str
    nbre:str='0'
    res:str=''
    chiffre:bool = False
    for c in s:
        if chiffre==True:
            res = res + c*int(nbre)
            chiffre=False
        elif est_chiffre(c):
            nbre=c
            chiffre = True
        else:
            res=res+c
    return res

#jeu de tests
assert decompression("ab3cd") == "abcccd"
assert decompression("ab3c2d4efgh") == "abcccddeeeefgh"
assert decompression("abcdefg") == "abcdefg"
assert decompression("")==""


#question 2
def compression(s:str)->str:
    """remplace de toute repetition d'un caractere c de la chaine s par une sous-chaine nc où n est le nombre de fois que le caractere c se repete consecutivement"""
    res:str=''
    nbre:int=1
    i:int=0
    j:int=i
    while i <len(s):
        print(i)
        j=i
        while j<len(s)-1 and s[j]==s[j+1] :
            nbre = nbre + 1
            j=j+1
        i=j
        if nbre==1:
            res = res + s[i]
            
        elif nbre!=1:
            res = res + str(nbre)+ s[i]    
            nbre = 1
        i=i+1
       
    return res
#JEU DE TESTS
assert compression("abcccd") == "ab3cd"
assert compression("abcccddeeeefgh") == "ab3c2d4efgh"
assert compression("abcdefg") == "abcdefg"
assert compression("")==""
assert compression("abcccddeeee")=="ab3c2d4e"
assert compression("cccddeg")=="3c2deg"
            
        
        
        
        
   


        
            
        
        
        
    

