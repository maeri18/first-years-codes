#Partie Guidée:
def divise(k:int,n:int)->bool:
    """précondition: k>0 and n>=0
    decide si k divise n"""
    return n%k==0
    
def est_parfait(n:int)->bool:
    """précondition: n>=1 decide si n est un nombre parfait"""
    s : int = 0
    i:int=1
    while i!=n:
        if divise(i,n):
            s=s+i
        i=i+1
    return n==s

#jeu de tests de la fonction divise
assert divise(1,0) == True
assert divise(15,0) == True
assert divise(1,15) == True
assert divise(1,1) == True
assert divise(1,2) == True
assert divise(3,2) == False
assert divise(4,5) == False
assert divise(25,100) == True

#jeu de tests de la fonction est_parfait
assert est_parfait(1)== False
assert est_parfait(2)== False
assert est_parfait(6)== True
assert est_parfait(9)== False
assert est_parfait(28)== True

#question 2

def est_parfait_simulee(n:int)->bool:
    """précondition: n>=1
    decide si n est un nombre parfait"""
    s : int = 0 #variable qui contiendra la somme des diviseurs de n
    i:int=1
    tr : int = 1 # variable qui permet de compter les tours de boucle
    print("debut de boucle, s = ",s,"\ndebut de boucle, i = ",i)
    while i!=n:
        if divise(i,n):#test pour savoir si i divise n
            s=s+i#ajout d'un diviseur à la somme
        i=i+1
        print("fin du tour",tr," s = ",s,"\nfin du tour",tr,"  i = ",i)
        tr = tr+1
    print("sortie de boucle s = ",s,"et n = ",n)
    return n==s

#jeu de tests
assert est_parfait_simulee(1)== False
assert est_parfait_simulee(2)== False
assert est_parfait_simulee(6)== True
assert est_parfait_simulee(9)== False
assert est_parfait_simulee(28)== True
    
#suggestion1 : Test

def test_parfait(n:int) ->bool:
    """n<=137438691328
    verifie si pour k dans [1,n] les resultats de est_parfait(k) sont vrais"""
    test_k:bool 
    test_fonct:bool
    result:bool 
    k:int=1
    while k!=n:
        test_k = False
        if k==6 or k==28 or k==496 or k==8128 or k==8589869056 or k==137438691328:
            test_k = True
            test_fonct = est_parfait(k)
            if test_k != test_fonct:
                print("Erreur de est_parfait pour k =",k)
        k = k + 1
        result = test_k
    return result

#jeu de tests
assert test_parfait(3) == False
assert test_parfait(6) == True
assert test_parfait(1) == False
assert test_parfait(1) == True

#suggestion : Invariant

#Question 1
# l'invariant ici est "s est égal somme des diviseurs de n inférieurs ou égaux à i-1"
# à l'entrée de la boucle, s=0, et i-1 =0, donc il n y a  aucun les diviseur de n inférieur ou égal à i-1. La somme des diviseurs de n inférieurs ou égaux à i-1 = 0 est bel et bien 0
# Supposons à un tour j, (j>=0) que s est égal somme des diviseurs de n inférieurs ou égaux à i-1, et montrons qu'au tour j+1 on a encore s est égal somme des diviseurs de n inférieurs ou égaux à i-1. en effet, au tour j, s = somme des diviseurs de n inferieurs ou égaux à i-1, puis,


#Question 2
def invariant(i:int,n:int,s:int)->bool:
    """précondition : n>=1 and s>=0 and i>=1
"""
    s1:int = 0 #va contenir la somme des diviseurs de n inférieurs ou égaux i-1
    j :int = 1
    while j<=i-1:
        if divise(j,n):
            s1 = s1 + j
        j=j+1
    return s1==s

#jeu de tests
assert invariant(2,2,1) == True
assert invariant(5,6,6) == True
assert invariant(7,9,3) == False


#question 3
def est_parfait_invariant(n:int)->bool:
    """précondition: n>=1
    """
    s : int = 0
    i:int=1
    if invariant(i, n, s)==True:
        print("invariant vrai")
    else :
        print("invariant faux")
    while i!=n:
        if divise(i,n):
            s=s+i
        i=i+1
        if invariant(i, n, s)==True:
            print("invariant vrai")
        else :
            print("invariant faux")
    return n==s

#jeu de tests
assert est_parfait_invariant(1)== False
assert est_parfait_invariant(2)== False
assert est_parfait_invariant(6)== True
assert est_parfait_invariant(9)== False
assert est_parfait(28)== True




