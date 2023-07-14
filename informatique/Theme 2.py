import math
#************************************************************************
#Exercice 1 Variables et affectation

#Question 1 expression et types de variables....serait complique a faire sous mrpython

#Question 2
#La fonction va renvoyer une erreur car on a utilise "=" au lieu de "==" pour le test de la valeur de x

#************************************************************************
#Exercice 2: Calcul des mentions

#Question 1
def mention(x:float)->str:
    """Precondition : 0<=x<=20"""
    if x >=16:
        return "TB"
    elif x>=14:
        return "B"
    elif x>=12:
        return "AB"
    elif x>=10:
        return "Passable"
    else:
        return "Elimine"

assert mention(0) == 'Elimine'
assert mention(8) == 'Elimine'
assert mention(10) == 'Passable'
assert mention(12.5) == 'AB'

#Question 2

def mention2(x:float)->str:
    """Precondition: 0<=x<=20"""
    if x<12:
        if x>=10:
            return "Passable"
        else:
            return "Elimine"
    elif x<14:
        return "AB"
    elif x<16:
        return "B"
    else:
        return "TB"

#*********************************************************************
#Exercice 3: Couverture

#Question 1
def f(n1:float, n2:float,n3:float)->str:
    """Precondition: n1!=n2 and n2!=n3 and n3 !=n1
    retourne un cas parmi 6 selon les valeurs de n1, n2 et n3."""
    if n1<n2 and n2<n3 :
        return 'cas 1'
    elif n1<n3 and n3<n2:
        return 'cas 2'
    elif n2<n1 and n1<n3:
        return 'cas 3'
    elif n2<n3 and n3<n1:
        return 'cas 4'
    elif n3<n1 and n1<n2:
        return 'cas 5'
    else:
        return 'cas 6'

assert f(1,2,3)=='cas 1'
assert f(1,3,2)=='cas 2'
assert f(2,1,3)=='cas 3'
assert f(3,1,2)=='cas 4'
assert f(2,3,1)=='cas 5'
assert f(3,2,1)=='cas 6'

#Question 2
def f2(n1:float,n2:float,n3:float)->str:
    """Precondition: n1!=n2 and n2!=n3 and n3!=n1
    retourne un cas parmi 6 selon les valeurs de n1, n2 et n3."""
    if n1<n2:
        if n2<n3:
            return 'cas 1'
        elif n3<n1:
            return 'cas 5'
    if n1<n3:
        if n3<n2:
            return 'cas 2'
        elif n2<n1:
            return 'cas 3'
    if n2<n3:
        if n3<n1:
            return 'cas 4'
    else:
        return 'cas 6'
    
assert f2(1,2,3)=='cas 1'
assert f2(1,3,2)=='cas 2'
assert f2(2,1,3)=='cas 3'
assert f2(3,1,2)=='cas 4'
assert f2(2,3,1)=='cas 5'
assert f2(3,2,1)=='cas 6'
    
#********************************************************************************
#Exercice 2.4

#Question 1
def egal_eps(x1:float,x2:float, eps:float)->bool:
    """precondition : eps>=0"""
    return abs(x1-x2)<=eps
assert egal_eps(-1,-2,2)==True
assert egal_eps(-1.5,-1.75,0.2)==False
assert egal_eps(0,0.01,0.02)==True

#Question 2
def fiabilite(v1:float,v2:float,v3:float, eps:float)->float:
    """precondition : eps>=0"""
    if egal_eps(v1,v2,eps) and egal_eps(v2,v3,eps) and egal_eps(v1,v3,eps):
        return 1
    elif (egal_eps(v1,v2,eps) and egal_eps(v2,v3,eps)) or (egal_eps(v1,v2,eps) and egal_eps(v1,v3,eps)) or (egal_eps(v2,v3,eps) and egal_eps(v1,v3,eps)):
        return 2/3
    else:
        return 0

#*************************************************************************************
#   *********Exercice 5**********
#Question 1
def volume_tetraedre(a:float,b:float,c:float,d:float,e:float,f:float)->float:
    x:float=a**2+b**2-d**2
    y:float=b**2+c**2-e**2
    z:float=a**2+c**2-f**2
    p:float=4*a**2*b**2*c**2
    q:float=a**2*y**2+b**2*z**2+c**2*x**2
    r:float=x*y*z
    return 1/12*math.sqrt(p-q+r)
    
    
assert volume_tetraedre(1,1,1,1,1,1)==0.11785113019775792
    

#Question 2
def volume_tetraedre_regulier(n:float)->float:
    return volume_tetraedre(n,n,n,n,n,n)
assert volume_tetraedre(1,1,1,1,1,1)==volume_tetraedre_regulier(1)==0.11785113019775792
#*************************************************************************************
#       ******Exercice 6**********
#Question 1

def ou(p:bool, q:bool)->bool:
    if p==True:
        return True
    elif q==True:
        return True
    else: return False

def et(p:bool, q:bool)->bool:
    if p==False:
        return False
    elif q==False:
        return False
    else:
        return True
def non(p:bool)->bool:
    if p==True:
        return False
    else:
        return True

assert ou(True, False)==True
assert ou(et(True,False),False)==False

#Question 2
#Evalution des expressions
#ou(3==3,5//0==2) genere une erreur: division par zero
#Par contre (3==3 or 5//0==2) ne genere pas d'erreur
#pareillement, et(3==4, 5//0==2) genere une erreur contrairement a (3==4) and (5//0==2)

#Question 3
def implique(p:bool,q:bool)->bool:
    return ou(non(p),q)
def ou_exclusif(p:bool,q:bool)->bool:
    return ou(et(non(p),q),et(p,non(q)))

assert implique(False,False)==True
assert implique(True, False)==False
assert implique(True, 3==3)==True
assert ou_exclusif(True, False)==True
assert ou_exclusif(3==2,3==3)==True
assert ou_exclusif(2==2,3==3)==False


#Question 4
def equivalent(p:bool,q:bool)->bool:
    return implique(p,q) and implique(q,p)

assert equivalent(True,3==3)==True
assert equivalent(True, 3==4)==False
assert equivalent(3==2,3==8)==True


#Exercice 2.7

#Question 1
#il faut comme parametres la largeur de la base et la largeur de l'etage superieur et de la hauteur des tours et x,y les coordonnees de son coin bas gauche
#specification : def tour(base:float,etage:float)->Image:\

#Question 2
def rectangle(x:float,y:float,l:float,h:float)->Image:
    return overlay(fill_triangle(x,y,x+l,y,x,y+h),fill_triangle(x+l,y,x+l,y+h,x,y+h))

show_image(rectangle(-0.5,-0.5,1,1))

#Question 3
def tour(base:float,etage:float, h:float,x:float, y:float)->Image:
    return overlay(rectangle(x,y,base,h),rectangle(x+1/2*base-1/2*etage,y+h,etage,h))

show_image(tour(1,0.5,0.75,-0.9,-0.9))

    
