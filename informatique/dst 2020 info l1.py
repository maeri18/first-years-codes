#dst 2020

#                  *************Exercice1**************

#Question 1

def est_bissextile(a:int)->bool:
    """precondition : a>=0"""
    if a%4==0 and a%100!=0:
        return True
    elif a%400==0:
        return True
    else:
        return False
assert est_bissextile(1900)==False
assert est_bissextile(2000)
assert not est_bissextile(2011)
assert est_bissextile(2012)
assert not est_bissextile(2013)
assert est_bissextile(2016)

#Question 2
def nb_anniversaire_fete(a:int,b:int)->int:
    """precondition : a>=0 and b>=0
precondition : a<= b
"""
    i:int=a
    nb_anniv:int=0
    while i <=b:
        if est_bissextile(i):
            nb_anniv = nb_anniv + 1
        i=i+1
    return nb_anniv
assert nb_anniversaire_fete(1880, 1900)==5
assert nb_anniversaire_fete(1881, 1900)==4
assert nb_anniversaire_fete(1881, 1899)==4
assert nb_anniversaire_fete(2011, 2012)==1
assert nb_anniversaire_fete(2012, 2012)==1
assert nb_anniversaire_fete(2012, 2013)==1
assert nb_anniversaire_fete(2012, 2016)==2

#Question 3
def nb_annees(annee_debut:int, n:int)->int:
    """precondition : annee_debut>=0 and n>=0

"""
    n1:int=n
    nb_annee:int=-1
    first_year:int=annee_debut
    while n1>0:
        if est_bissextile(first_year):
            n1=n1-1
        first_year=first_year+1
        nb_annee=nb_annee+1
    return nb_annee
assert nb_annees(2012, 1)==0
assert nb_annees(2011, 1)==1
assert nb_annees(2012, 2)==4

#       *****************Exercice 2*****************
Budget = List[float]
b1 : Budget = [-200, 1800, -1200, -200, -500, 1800, -500]
b2 : Budget = [10, 10, -10, 10]

#Question 1
def situations_intermediaires(s0:float, b:Budget)->List[float]:
    """aucune precondition"""
    lres:List[float]=[]
    var:float
    situ:float=s0
    for var in b:
        situ=situ+var
        lres.append(situ)
    return lres
assert situations_intermediaires(100, b2)==[110, 120, 110, 120]
assert situations_intermediaires(0, b1)==[-200, 1600, 400, 200, -300, 1500, 1000]
assert situations_intermediaires(20000, b1)==[19800, 21600, 20400, 20200, 19700, 21500, 21000]
assert situations_intermediaires(0, [])==[]


#Question 2
def passe_sous_seuil(s0:float,b:Budget,seuil:float)->bool:
    """pas de precondition"""
    b1:List[float] = situations_intermediaires(s0,b)
    var:float
    if s0<seuil:
        return True
    for var in b1:
        if var<seuil:
            return True
    return False
assert passe_sous_seuil(0, b1, 0)==True # sous le seuil a la 1ere operation
assert passe_sous_seuil(250, b1, 0)==True # sous le seuil a la 5eme operation
assert passe_sous_seuil(20000, b1, 10000)==False
assert passe_sous_seuil(0, b2, 0)==False
assert passe_sous_seuil(-5,b2,0) == True

#Question 3
def recettes_depenses(b:Budget)->Tuple[Budget,Budget]:
    """aucune precondition"""
    return([var for var in b if var>0],[var for var in b if var<0])
assert recettes_depenses(b1)==([1800, 1800], [-200, -1200, -200, -500, -500])
assert recettes_depenses(b2)==([10, 10, 10], [-10])
assert recettes_depenses([0, 100, 0, -100])==([100], [-100])
assert recettes_depenses([-100, 0, -100, -200])==([], [-100, -100, -200])

#Question 4
b3 : List[Tuple[str, float]] = [("Nourriture", -200),
("Salaire", 1800),
("Loyer", -1200),
("Nourriture", -200),
("Loisir", -500),
("Salaire", 1800),
("Loisir", -500)]

def f(x1:List[Tuple[str,float]], x2:str)->float:
    """Calcule la somme totale depensee ou gagnee pour une variable x2"""
    x3:float = 0.0
    x4:int = 0
    while x4 != len(x1):
        x5, x6 = x1[x4]
        if x5 == x2:
            x3 = x3 + x6
        x4 = x4 + 1
    return x3
assert f(b3,"Salaire")==3600
assert f(b3,"Transport")==0
assert f(b3,"Loisir")==-1000

#            **************Exercice 3****************

#Question 1
def reparenthese(ouv:str, fer:str,s:str)->str:
    """precondition : len(ouv)==len(fer)==1
"""
    c:str
    res:str=''
    for c in s:
        if c=='(':
            res=res + ouv
        elif c==')':
            res=res + fer

        else:
            res=res+c
    return res
assert reparenthese('[', ']', '(()())')=='[[][]]'
assert reparenthese('[', ']', '((a)(b))')=='[[a][b]]'
assert reparenthese('[', ']', '[[][]]')=='[[][]]'
assert reparenthese('(', ')', '(()())')=='(()())'
assert reparenthese('[', ']', '')==''
        
#Question 2
def niveau_paren(s:str)->int:
    """renvoie le niveau de parenthese de la chaine s"""
    nbre:int=0
    c:str
    for c in s:
        if c=='(':
            nbre=nbre+1
        elif c==')':
            nbre=nbre-1
    return nbre
assert niveau_paren(')(a(b(c')==2
assert niveau_paren('(abc)))')==-2
assert niveau_paren('(a)b))(')==-1
assert niveau_paren('((ab)cd())')==0
assert niveau_paren('(((acbd)))')==0
assert niveau_paren(')))(((')==0
assert niveau_paren('')==0

#Question 3
def bon_parenthesage(s:str)->bool:
    """Teste si le parenthesage de s est correct"""
    if niveau_paren(s)!=0:
        return False
    else:
        
        nbre_ouv:int=1
        nbre_fer:int=1
        c1:int=0
        c2:int=0
        l:List[str]=[var for var in s if var=='(' or var==')']
        print(l)
        while c1<len(l):
            if l[c1]=='(':
                while l[c2]=='(' and c2<len(l):
                    nbre_ouv=nbre_ouv+1
                    c2=c2+1
                while l[c2]==')' and c2<len(l):
                    nbre_fer=nbre_fer+1
                    c2=c2+1
            else:
                while l[c2]==')' and c2<len(l):
                    nbre_fer=nbre_fer+1
                    c2=c2+1
                while l[c2]=='(' and c2<len(l):
                    nbre_ouv=nbre_ouv+1
                    c2=c2+1    
            if nbre_fer>nbre_ouv:
                return False
            else:
                nbre_ouv=1
                nbre_fer=1
                c1=c2
    print("et on sort")
    return True
     
                
def bon_parenthesage2(s : str) -> bool:
    """"""
# niveau de parenthésage
    niv : int = 0
    c : str
    for c in s:
        if c == '(':
            niv = niv + 1
        if c == ')':
            niv = niv - 1
        if niv < 0:
# trop de fermantes
            return False
    return niv == 0           

assert bon_parenthesage2('((()))')==True
assert bon_parenthesage2('(a(b(c)d)e)')==True
assert bon_parenthesage2('(()())')==True            
            
                
            
            
            
                
            
