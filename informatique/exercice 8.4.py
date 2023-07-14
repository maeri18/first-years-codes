#exercice 8.4


#question 1
def moyenne(lis:List[float])->float:
    """precondition : len(lis)>0
renvoie la moyenne de la liste lis"""
    i:float
    somme:float=0
    for i in lis:
        somme = somme + i
    return somme/len(lis)
assert moyenne([10,10,10])==10

#question 2
def ecart_nombre(l:List[float],x:float)->List[float]:
    """renvoie la liste obtenue en effectuant la valeur absolue de la difference entre les elements de l et x"""
    return [abs(k-x) for k in l]
assert ecart_nombre([10,10,10],10)==[0,0,0]
assert ecart_nombre([0,10,20],10)==[10,0,10]

#question 3
def liste_carre(l:List[float])->List[float]:
    """retourne la liste obtenue en elevant les elements de l au carre"""
    return [k**2 for k in l]
assert liste_carre([0,0,0])==[0,0,0]
assert liste_carre([10,0,10])==[100,0,100]


#question 4
def variance(l:List[float])->float:
    """ precondition : l!=[]
renvoie la variance de la liste l"""
    return moyenne(liste_carre(ecart_nombre(l,moyenne(l))))
assert variance([10,10,10])==0.0
assert variance([1,2]) == 0.25

#question 5
def variance_opt(l:List[float])->float:
    """version optimisee de la fonction"""
    m:float=moyenne(l)
    return moyenne([(abs(k-m))**2 for k in l])
assert variance_opt([10,10,10])==0.0
assert variance_opt([1,2]) == 0.25


