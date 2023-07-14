#dst 2019 infol1
#Exercice 1
Trousseau=List[int]

#Question 1
def num_cle(L:Trousseau, i:int)->int:
    """precondition: 1<=i<=len(L)
"""
    return L[i-1]

#Question 2
def num_casier(L:Trousseau,j:int)->int:
    """precondition: 1<=j<=len(L)
"""
    i:int
    for i in L:
        if L[i]==j:
            return i

#Question 3
def tous_bons(L:int)->bool:
    """ """
    i:int
    for i in range(1,len(L)+1):
        if L[i-1]==i:
            return False
    return True

#Question 4
def tous_differents(L:List[int])->bool:
    """ """
    i:int
    j:int
    for i in range(len(L)):
        for j in range(0,i):
            if L[j]==L[i]:
                return False
    return True

#Question 5
def est_bon_trousseau(L:List[int])->bool:
    """ """
    i:int
    n:int=len(L)
    for i in L:
        if i>n or i<1:
            return False
    return tous_differents(L) and tous_bons(L)

#Exercice 2

#Question 1
def tirage_plusieurs_des(n:int)->int:
    """precondition :n>0"""
    s:somme=0
    i:int
    for i in range(n):
        somme = somme + lancer_de6()
    return somme

#Question 2
def nb_tirages_score(n:int, s:int)->int:
    """precondition :n>0"""
    score:int=0
    nb:int=1
    while score<s:
        score=score+tirage_plusieurs_des(n)
        nb=nb+1
    return nb

#Question 3
def nb_pour_doubles(n:int)->int:
    """precondition :n>0"""
    score1:int=tirage_plusieurs_des(n)
    score2:int=0
    nb:int=1
    while score1!=score2:
        score2=score1
        scores1=tirage_plusieurs_des(n)
        nb=nb+1
    return nb

#Exercice 3

#Question 1
mot_binaire = str
def inversion_binaire(s:str)->str:
    """ """
    c:str
    res:str=''
    for c in s:
        if c=='1':
            res=res+'0'
        else:
            res=res+'1'
    return res

#Question 2
def indice_dernier_un(m:str)->str:
    """ """
    i:int = len(m)-1
    while i>=0 and m[i]!='1':
        i=i-1
    if i >=0:
        return 1
    else:
        return -1
    
        
#Question 3
def oppose(m:str)->str:
    """ """
    i:int=len(m)-1
    while i>=0 and m[i]!='1':
        i=i-1
    if i>0:
        return inversion_binaire(m[:i]) + '1' + m[i+1:]
    else:
        return m

#Question 4
def valeur_base2(mot:str)->int:
    
    """hscgucshuj """
    val:int=0
    i:int=0
    while i<len(mot):
        if mot[i]=='1':
            val=val+int(mot[i])*2**i
        i=i+1
        
    return val 
        
    
#Exercice 4

def f(a:str,b:str)->str:
    """ """
    c:str=''
    d:int=0
    e:bool=True
    while e and d!=len(a) and d!=len(b):
        if a[d]!=b[d]:
            e=not e
        else :
            c=c+a[d]
            d=d+1
    return c
        

        
