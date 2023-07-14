#TME 7 Chekam__Chikbouni
import math

#Exercice 11.6
def oppose(n:int)->int:
    """Retourne l'oopose de n"""
    return -n

#Jeu de tests
assert oppose(0)==0
assert oppose(1)==-1
assert oppose(-171)==171

def double(n:int)->int:
    """Retourne le double de n"""
    return 2*n

#Jeu de tests
assert double(2)==4
assert double(0)==0

#Question 1
def fmap(f:Callable[[T],U],lst:List[T])->List[U]:
    """Retourne la liste obtenue en appliquant la transformation f aux elements de lst"""
    var:T    #variable d'iteration 
    lres:List[U]=[] #liste resultante
    for var in lst:
        lres.append(f(var))
    return lres

#Jeu de tests
assert fmap(oppose, [1,2,3,4,5])==[-1,-2,-3,-4,-5]
assert fmap(double, [1,2,3,4,5])==[2,4,6,8,10]
assert fmap(oppose,[])==[]
#assert fmap(len,["un","deux","trois","quatre","cinq"])==[2,4,5,6,4]


#Question 2
def fmap2(f:Callable[[T],U],lst:List[T])->List[U]:
    """Retourne en utilisant une comprehension la liste obtenue en appliquant la transformation f aux elements de lst"""
    return [f(e) for e in lst]

#Jeu de tests
assert fmap2(oppose, [1,2,3,4,5])==[-1,-2,-3,-4,-5]
assert fmap2(double, [1,2,3,4,5])==[2,4,6,8,10]       
assert fmap2(oppose,[])==[]
#assert fmap2(len,["un","deux","trois","quatre","cinq"])==[2,4,5,6,4]

#Question 3
def even(n:int)->bool:
    """Retourne True ssi n est pair"""
    return n%2==0
def odd(n:int)->bool:
    """Retourne True ssi n est impair"""
    return not(even(n))

def ffilter(pred:Callable[[T],bool], lst:List[T])->List[T]:
    """retourne les elements de lst qui verifient pred"""
    var:T  #variable d'iteration
    lres:List[T]=[]  #liste resultante
    for var in lst:
        if pred(var): #si l'element var de lst verifie le predicat pred, on l'ajoute a lres
            lres.append(var)
    return lres

#Jeu de tests
assert ffilter(even,[1,2,3,4,5,6,7])==[2,4,6]
assert ffilter(odd,[1,2,3,4,5,6,7])==[1,3,5,7]
assert ffilter(odd,[])==[]
assert ffilter(even,[-3,-9,0,5,4,-13])==[0,4]
assert ffilter(odd,[2,6,-4,8])==[]

#Question 4
def ffilter2(pred:Callable[[T],bool],lst:List[T])->List[T]:
    """retourne en utilisant une comprehension les elements de lst qui verifient pred"""
    return [var for var in lst if pred(var)]

#Jeu de tests
assert ffilter2(even,[1,2,3,4,5,6,7])==[2,4,6]
assert ffilter2(odd,[1,2,3,4,5,6,7])==[1,3,5,7]
assert ffilter2(odd,[])==[]
assert ffilter2(even,[-3,-9,0,5,4,-13])==[0,4]
assert ffilter2(odd,[2,6,-4,8])==[]



#Exercice 11.4


#Question 1

def f_fun(x:float)->float:
    """Calcule x^2 - a avec a=2"""
    return x**2-2

#Jeu de tests
assert f_fun(2)== 2
assert f_fun(0)== -2
assert f_fun(-1)== -1

def f_deriv(x:float)->float:
    """Calcule 2*x"""
    return 2*x

#Jeu de tests
assert f_deriv(0)==0
assert f_deriv(3)==6
assert f_deriv(-1)==-2


#Question 2
def approx_newton(f:Callable[[float],float],df:Callable[[float],float], x0:float,n:int)->float:
    """ precondition : n>=0
Calcule le n-ieme terme de l'approximation de Newton avec  x0 comme premier terme et f comme fonction"""
    x:float
    if n==0: #cas d'arrêt
        return x0
    else:
        x=approx_newton(f,df,x0,n-1) #appel recursif
        return x-f(x)/df(x)
    
#Jeu de tests
assert approx_newton(f_fun,f_deriv,1.0,2)==1.4166666666666667
assert approx_newton(f_fun,f_deriv,1.0,5)==1.4142135623730951
assert approx_newton(f_fun,f_deriv,1.0,0)==1.0


#Question 3

def approx_newton_it(f:Callable[[float],float],df:Callable[[float],float], x0:float,n:int)->float:
    """precondition: n>=0
Calcule en utilisant une boucle le n-ieme terme de l'approximation de Newton avec  x0 comme premier terme et f comme fonction"""
    y:float=x0
    i:int  #variable d'iteration
    for i in range(n):
        y=y-f(y)/df(y)
    return y

#Jeu de tests
assert approx_newton_it(f_fun,f_deriv,1.0,2)==1.4166666666666667
assert approx_newton_it(f_fun,f_deriv,1.0,5)==1.4142135623730951
assert approx_newton_it(f_fun,f_deriv,1.0,0)==1.0


#Question 4

  #definition de la fonction g(x) = cos(x)-x^3
def g_fun(x:float)->float:
    """retourne cos(x)-x^3"""
    return math.cos(x)-x**3
  #definition de la derivee de g
def g_deriv(x:float)->float:
    """retourne g'(x)"""
    return -math.sin(x)-3*x**2

  #Fonction permettant de resoudre l'equation
def resolution(n:int)->float:
    """precondition :n>=0
renvoie le n-ieme terme de l'approximation de newton pour cos(x)-x^3"""
    return approx_newton(g_fun, g_deriv, 0.5,n)
#On trouve pour n=5 la solution de l'equation   cos(x) = x^3 egale a 0.8654740331109566 et on a bien cos(0.8654740331109566) = 0.6482792584674268 et 0.8654740331109566^3 = 0.648279258495533


#Exercice 11.1

#Question 1
def fibo(n:int)->int:
    """precondition : n>=0
Renvoie le n-ieme terme de la suite de fibonacci"""
    if n==0: #cas d'arrêt
        return 0
    elif n==1: #cas d'arrêt
        return 1
    else:
        return fibo(n-2)+fibo(n-1)  #appel recursif

#Jeu de tests
assert fibo(0)==0
assert fibo(1)==1
assert fibo(3)==2
assert fibo(5)==5
assert fibo(8)==21

#Question 2
#Evaluation par reecriture de fibo(6)
# fibo(6)
# fibo(4)+fibo(5)
# fibo(2)+fibo(3)+fibo(3)+fibo(4)
# fibo(0) + fibo(1) + fibo(1) + fibo(2) + fibo(1) + fibo(2) + fibo(2) + fibo(3)
# 0 + 1 + 1 + fibo(0) + fibo(1) + 1 + fibo(0) + fibo(1) + fibo(0) + fibo(1) + fibo(1) + fibo(2)
# 0 + 1 + 1 + 0 + 1 + 1 + 0 + 1 + 0 + 1 + 1 + fibo(0) + fibo(1)
# 0 + 1 + 1 + 0 + 1 + 1 + 0 + 1 + 0 + 1 + 1 + 0 + 1
# 8

# on a besoin de 24 appels recursifs
# On remarque que 24 = 4 * 6 donc, d'après moi ,l'ordre de grandeur des appels recursifs est exponentiel

#Question 3
def fibofast(n:int, a:int,b:int)->int:
    """precondition : n>=0 and a>=0 and b>0
Calcule le n-ieme terme de la suite de fibonacci """
    if n==0: #cas d'arrêt
        return a
    else:
        return fibofast(n-1, b, a+b)  #appel recursif

#Jeu de tests
assert fibofast(3,0,1)==2
assert fibofast(5,0,1)==5
assert fibofast(8,0,1)==21    
assert fibofast(0,0,1)==0
assert fibofast(1,0,1)==1
#Question 4
#Reecriture de fibofast(6,0,1)
# fibofast(6,0,1)
# fibofast(5,1,1)
# fibofast(4,1,2)
# fibofast(3,2,3)
# fibofast(2,3,5)
# fibofast(1,5,8)
# fibofast(0,8,13)
# 8

#on a besoin de 6 appels recursifs
#Le nombre d'appels recursifs necessaires croit dans le meme ordre que n. Cet ordre de grandeur est lineaire

#Question 5
def fibit(n:int)->int:
    """precondition : n>=0
Renvoie le n-ieme terme de la suite de fibonacci en utilisant une boucle while"""
    a: int=0
    b:int =1
    n1:int=n #compteur
    fib:int=0 #variable qui contiendra le resultat
    while n1>0:
        fib=a
        a=b
        b= fib+a
        n1=n1-1
    return a
assert fibit(0)==0
assert fibit(1)==1
assert fibit(3)==2
assert fibit(5)==5
assert fibit(8)==21
assert fibit(6)==8
