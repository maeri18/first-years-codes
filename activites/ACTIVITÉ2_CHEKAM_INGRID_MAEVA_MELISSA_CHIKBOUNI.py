import math
#Activité 2

#partie Guidée
#Question 1

def terme_leibniz(n : int) -> float :
    """ précondition : n>=0"""
    return ((-1)**n)/(2*n+1)
#jeu de tests
assert terme_leibniz (0) == 1
assert terme_leibniz (1) == -1/3
assert terme_leibniz (10) == 1/21

#QUESTION 2
def somme_leibniz (n : int ) -> float :
    """ précondition : n >= 0 """
    i : int = 0 #variable d'itération
    somme : float = 0.0#variable qui va contenir la somme_leibniz
    while i <=n :
        somme = somme + terme_leibniz(i)
        i = i+1
    return somme
#jeu de tests
assert somme_leibniz(0)==1
assert somme_leibniz(1)==1- 1/3
assert somme_leibniz(2)==1- 1/3 + 1/5
assert somme_leibniz(3)==1- 1/3 + 1/5 -1/7
assert somme_leibniz(4)==1- 1/3 + 1/5 -1/7+1/9

#Question 3
def approx_leibniz(n:int) ->float:
    """  précondition : n >= 0 """
    return 4 * somme_leibniz(n)
#jeu de tests
assert approx_leibniz(10) == 3.232315809405594
assert approx_leibniz(100) == 3.1514934010709914

#Question 4
def approx_leibniz_2(k:int) -> int :
    """Donne l'entier n à partir duquel l'approximation de pi est inférieure à 10^(k)"""
    i : int = 0
    while abs ( approx_leibniz (i) -math.pi ) >= 10**(k):
        i = i+1
    n : int = i
    return n
#jeu des tests
assert approx_leibniz_2(-1) == 9
assert approx_leibniz_2(-4) == 9999
#assert approx_leibniz_2(-5) == 99999


#suggestion : Aleatoire




    




