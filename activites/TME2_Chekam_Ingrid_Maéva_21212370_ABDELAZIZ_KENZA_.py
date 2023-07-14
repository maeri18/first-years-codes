import math  

#exercice 2.3
def f(n1 : float, n2 : float, n3 : float) -> str:
    """Précondition : n1 != n2 and n2 != n3 and n3 != n1
    retourne un cas parmi 6 selon les valeurs de n1, n2 et n3.
    """
    if n1 < n2 and n2 < n3:
        return 'cas 1'
    elif n1 < n3 and n3 < n2:
        return 'cas 2'
    elif n2 < n1 and n1 < n3:
        return 'cas 3'
    elif n2 < n3 and n3 < n1:
        return 'cas 4'
    elif n3 < n1 and n1 < n2:
        return 'cas 5'
    else:
        return 'cas 6'

    #jeu de test couvrant tous les cas possibles:
assert f(1.0,2.0,3.0) == "cas 1"
assert f(1.0,6.0,5.0) == "cas 2"
assert f(3.0,1.0,5.0) == "cas 3"
assert f(15.0,4.0,7.0) == "cas 4"
assert f(3.0,5.0,1.0) == "cas 5"
assert f(10.0,5.0,2.0) == "cas 6"

#Question 2

def f2(n1 : float, n2 : float, n3 : float) -> str:
    """ Précondition : n1 != n2 and n2 != n3 and n3 != n1
    Retourne un cas parmi 6 selon les valeurs de n1, n2 et n3 en utilisant uniquement des alternatives"""
    if n1<n2 :
        if n2<n3:
            return 'cas 1'
        elif n1<n3:
            return 'cas 2'
        else:
            return 'cas 5'
            
           
    else :
        if n1<n3:
            return 'cas 3'
        elif n2<n3:
            return 'cas 4'
        else:
            return 'cas 6'

assert f2(1.0,2.0,3.0) == "cas 1"
assert f2(1.0,6.0,5.0) == "cas 2"
assert f2(3.0,1.0,5.0) == "cas 3"
assert f2(15.0,4.0,7.0) == "cas 4"
assert f2(3.0,5.0,1.0) == "cas 5"
assert f2(10.0,5.0,2.0) == "cas 6"

#exercice 2.4
#queston1

def egal_eps (x1 : float, x2:float, epsilon:float) -> bool :
    """précondition : epsilon > 0.
    Teste l'égalité de deux flottants en comparant la valeur absolue de leur différence à epsilon"""
    if abs(x1-x2) < epsilon:
        return True
    else:
        return False

assert egal_eps(1.0,2.0,0.2) == False
assert egal_eps(-1.0,-1.1,0.2) == True
assert egal_eps(1.0,1.05,0.15) == True 
assert egal_eps(-1.0,0.0,0.11) == False
assert egal_eps(-7.6,-6.0,0.5) == False
assert egal_eps(0.08,-0.95,0.2) == False
assert egal_eps(4.0,3.958,0.2) == True

def fiabilité(v1 : float, v2 : float, v3:float, epsilon : float) ->float:
    
    """ Précondition : epsilon > 0
    calcule le taux de fiabilité de v1, v2 et v3 à epsilon près"""
    if egal_eps(v1, v2, epsilon) and egal_eps(v2,v3,epsilon) and egal_eps(v1,v3,epsilon):
        return 1
    else :
        if egal_eps(v1, v2, epsilon) and egal_eps(v2,v3,epsilon):
            return 2/3
        if egal_eps(v2,v3,epsilon) and egal_eps(v1,v3,epsilon):
            return 2/3
        if egal_eps(v1, v2, epsilon) and egal_eps(v1,v3,epsilon):
            return 2/3
    return 0

assert fiabilité (1,0.5,0.7,2)== 1
assert fiabilité (-1,2.0,0.0,0.2)== 0
assert fiabilité (-3.5,-3.4,-3.3,0.2)== 2/3

#exercice 2.5
#question 1


def volume_tetraedre (a :float , b:float , c:float , d:float , e:float , f:float ) ->float:
    """ precondition """
    x : float =a**2+b**2-d**2
    y : float =b**2+c**2-e**2
    z : float =a**2+c**2-f**2
    p : float =(4*a**2)*(b**2)*(c**2)
    q : float =(a**2)*(y**2)+(b**2)*(z**2)+(c**2)*(x**2)
    r : float =x*y*z

    return 1/12*math.sqrt(p-q+r)

assert volume_tetraedre (1,1,1,1,1,1)==0.11785113019775792

#question 2
def volume_tetraedre_regulier(n: int) -> float:
    """ """
    return (math.sqrt(2)/12) * (n * n * n)

assert volume_tetraedre_regulier(3) == 3.1819805153394642

  """ un tétraèdre non-régulier dans le volume est calculable 

( a=5 , b=1 ,c=3 , d=2.1 ,e=1.5 ,f=2.4 )"""

    
  

    
    

        
