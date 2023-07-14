#THEME 3

#***************************************************************************************
#Exercice 1

#Question 1
def somme_impairs_inf(n:int)->int:
    """precondition : n>=0"""
    res:int=0
    a:int
    for a in range(n+1):
        if a%2==1:
            res=res+a
    return res

assert somme_impairs_inf(1) == 1
assert somme_impairs_inf(2) == 1
assert somme_impairs_inf(5) == 9


#Question 2
def somme_premiers_impairs(n:int)->int:
    """precondition : n>=0"""
    res:int=0
    i:int=0 # compteur de nombres impairs
    a:int=0
    while i<n:
       if a%2==1:
           res=res+a
           i=i+1
       a=a+1
    return res

#Question 3
# simulation de boucle pour somme_premiers_impairs(5):
# Tour | res | i | a |
# --------------------
#Entree| 0   | 0 | 0 |
# --------------------
# 1    | 0   | 0 | 1 |
# --------------------
# 2    | 1   | 1 | 2 |
# --------------------
# 3    | 1   | 1 | 3 |
# --------------------
# 4    | 4   | 2 | 4 |
# --------------------
# 5    | 4   | 2 | 5 |
# --------------------
# 6    | 9   | 3 | 6 |
# --------------------
# 7    | 9   | 3 | 7 |
# --------------------
# 8    | 16  | 4 | 8 |
# --------------------
# 9    | 16  | 4 | 9 |
# --------------------
#10(so)| 25  | 5 | 10|
# --------------------

#d'ou somme_premiers_impairs(5) == 25

#*********************************************************************************************
#Exercice 3.2
#Question 1
def f(x:int, y:int)->int:
    """ """
    z:int = 0
    w:int=x
    while w<=y:
        z=z+w*w
        w=w+1
    return z

#Question 2 :Simulation de boucle pour f(3,6)
#********************************************
# Tour | z | w |
# --------------
#Entree| 0 | 3 |
# --------------
#  1   | 9 | 4 | 
# --------------
#  2   |25 | 5 | 
# --------------
#  3   |50 | 6 | 
# --------------
#4(sor)|86 | 7 | 
# --------------

#Question 3
#Pour x<=y f(x,y) la boucle s'arrete pour w = y+1

#Question 4
#L'appel de la fonction f(5,3) retourne 0

#Question 5 definition plus complete de la fonction:
def somme_carres(x:int, y:int)->int:
    """precondition: x<=y
renvoie la somme des carres entre x et y"""
    compt:int = x #compteur permettant d'aller de x a y
    res:int=0 #variable qui contiendra le resultat
    while compt<=y:
        res=res+compt*compt
        compt=compt+1
    return res

#Jeu de tests
assert somme_carres(3,6)==86
assert somme_carres(0,2)==5

#*********************************************************************
#Exercice 3.3 Nombres premiers

#Question 1
def divise(n:int,p:int)->bool:
    """precondition: n>0"""
    return p%n ==0

assert divise(1,4)==True
assert divise(2,4)==True
assert divise(3,4)==False

#Question 2

#**********sortie anticipee de la fontion***************
def est_premier(n:int)->bool:
    if n<2:
        return False
    else:
        i:int
        for i in range(2,n//2):
            if divise(i,n):
                return False
        return True
#********sans sotie anticipee **************
def est_premier1(n:int)->bool:
    if n<2:
        return False
    else:
        i:int
        res:bool=True
        for i in range(2,n//2):
            if divise(i,n):
                res=False
        return res
    
assert est_premier(0) == False
assert est_premier(17)==True
assert est_premier1(0) == False
assert est_premier1(17)==True

#****************************************************************************
#Exercice 3.4 Calcul du PPCM

#Question 1
def reste(a:int,b:int)->int:
    """Precondition : a>=0 and b>0"""
    res:int=a
    while res>=b:
        res=res-b
    return res

assert reste(11,4) ==3
assert reste(21,7)==0
assert reste(0,3)==0

#Question 2
def est_divisible(a:int,b:int)->bool:
    """precondition : a>=0 and b>0"""
    return reste(a,b)==0

assert est_divisible(11,4) == False
assert est_divisible(21,7)==True
assert est_divisible(0,3)==True

#Question 3
def ppcm(a:int,b:int)->int:
    """precondition: a>0 and b>0
"""
    ma:int=max(a,b)
    x:int=ma
    
    while x<=a*b:
        if est_divisible(x,a) and est_divisible(x,b):
            return x
        x=x+ma
assert ppcm(2,3)==6
assert ppcm(6,8)==24
assert ppcm(12,15)==60

#Question 4
#Simulation de boucle pour ppcm(6,8)
#********************************************
# Tour | x |
# ----------
#Entree| 8 | 
# ----------
#  1   |16 |
# ----------
#2(sor)|24 |
# ----------

#La fonction renvoie 24

#*********************************************
#Exercice 3.5

#Question 1
def fibonacci(n:int)->int:
    """precondition: n>=0"""
    if n==0:
        return 0
    elif n==1:
        return 1
    else:
        f0:int=0
        f1:int=1
        f:int=0
        i:int=2
        while i<=n:
            f=f0+f1
            f0=f1
            f1=f
            i=i+1
        return f
assert fibonacci(0)==0
assert fibonacci(2)==1
assert fibonacci(3)==2
assert fibonacci(4)==3
assert fibonacci(5)==5
assert fibonacci(6)==8


 

            
    








