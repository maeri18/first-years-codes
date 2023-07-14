#DST 2021 
#Exercice 1
import math

Point = Tuple[float,float]
Vecteur = Tuple[Point,Point]

ori : Point = (0.0,0.0)

p1:Point = (0.0,1.0)
p2:Point = (1.0,3.0)
p3:Point = (-0.5,0.0)
p4:Point = (4.5,0.0)
p5:Point = (-3.0,0.0)

nul : Vecteur = (ori,ori)
v1:Vecteur=(p1,p2)
v2:Vecteur=(p2,p3)
v3:Vecteur=(ori,p4)

#Question 1.1:

def distance(pa:Point, pb:Point)->float:
    """Renvoie la distance entre pa et pb"""
    x1,y1=pa
    x2,y2=pb
    return math.sqrt((x2-x1)**2+(y2-y1)**2)

assert distance(ori,p1) == 1.0
assert distance(p1,p1)==0.0
assert distance(p4,p5)==7.5
assert abs(distance(ori,(1.0,1.0))-math.sqrt(2))<10**-12

#Question 1.2
def longueur(lis:List[Point])->float:
    """Renvoie la longueur de la ligne composee de segment reliant dans l'ordre les points de la liste"""
    long:float=0
    i:int
    for i in range(len(lis)-1):
        long=long+distance(lis[i],lis[i+1])
    return long
assert longueur([ori,p1,ori,p5]) == 5.0
assert longueur([])==0.0
assert longueur([p1,p2])==distance(p1,p2)

#Question 1.3
def translate(p:Point,v:Vecteur)->Point:
    """renvoie le translate de p par rapport a v"""
    x,y=p
    ((x1,y1),(x2,y2)) = v
        
    return (x+x2-x1,y+y2-y1)
assert translate(ori,v3)==p4
assert translate(ori,(p3,p3))==ori
assert translate(p4,v1)==(5.5,2.0)

#Question 1.4

def liste_translatee(l1:List[Point],v:Vecteur)->List[Point]:
    """Renvoie la liste des translates des points de l1 par rapport a v"""
    return [translate(var, v) for var in l1]

assert liste_translatee([p1,p2,p3],v1)==[(1.0,3.0),(2.0,5.0),(0.5,2.0)]
assert liste_translatee([p1,p2,p3],nul) == [p1,p2,p3]

#Question 1.5
def norme(v:Vecteur)->float:
    """renvoie la norme du vecteur v"""
    a,b=v
    return distance(a,b)

assert norme((ori,ori))==0.0
assert norme(v3)==4.5
assert abs(norme(v1)-math.sqrt(5))<10**-12


#Question 1.6
def non_nuls(li:List[Vecteur])->List[Vecteur]:
    """renvoie la liste des vecteurs de li differents du vecteur nul"""
    return [var for var in li if norme(var)!=0]
assert non_nuls([v1,v2,v3])==[v1,v2,v3]
assert non_nuls([v2,nul,v1,(p1,p1)])==[v2,v1]

#Exercice 2 :codage de Gavy

#Question 2.1
def inverse_char(c:str)->str:
    """precondition: c=='0' or c=='1'
renvoie le caractere inverse de c"""
    if c=='0':
        return '1'
    else:
        return'0'
assert inverse_char('0')=='1'
assert inverse_char('1')=='0'
#Question 2.2
def nb_un(s:str)->int:
    """Renvoie le nombre d'occurences de '1' dans s"""
    occ:int=0
    c:str
    for c in s:
        if c=='1':
            occ=occ+1
    return occ
assert nb_un('')==0
assert nb_un('000')==0
assert nb_un('001')==1
assert nb_un('111')==3
assert nb_un('abc')==0

s1:str="c"
#Question 2.3
def invc_avant_dernier_un(s:str)->str:
    """precondition : s ne contient que des '1' et des '0'
"""
    i:int=-1
    res:str= ''
    p:int=-1
    change:bool=False
    if len(s)==1 or len(s)==0:
       return s
    else:
        while s[i]!='1' and i>-len(s):
            i=i-1
        p=i
        if i== -len(s):
            return s
        else:
            i=-1
            while i>=-len(s):
                if i == p-1:
                    res= inverse_char(s[i]) + res
                else:
                    res=s[i]+res
                i=i-1
                
            return res
        

assert invc_avant_dernier_un('')==''
assert invc_avant_dernier_un('1')=='1'
assert invc_avant_dernier_un('0')=='0'
assert invc_avant_dernier_un('01')=='11'
assert invc_avant_dernier_un('10')=='10'
assert invc_avant_dernier_un('1001')=='1011'
assert invc_avant_dernier_un('0011')=='0001'

#Question 2.4
assert invc_avant_dernier_un('0000')=='0000'
assert invc_avant_dernier_un('1000')=='1000'

def invc_avant_dernier_un2(s:str)->str:
    """precondition : s ne contient que des '1' et des '0'
"""
    i:int=-1
    found:bool=False
    tochange:bool=False
    res:str=''
    while i>-len(s)-1:
        if s[i]=='1' and found==False:
            res = s[i]+res
            tochange=True
            found=True
            
        elif tochange==True:
            res=inverse_char(s[i]) + res
            tochange=False
            
        elif (found==True and tochange==False) or( tochange==False and found==False) :
            res=s[i]+res
    
        i=i-1
    return res
        
assert invc_avant_dernier_un2('')==''
assert invc_avant_dernier_un2('1')=='1'
assert invc_avant_dernier_un2('0')=='0'
assert invc_avant_dernier_un2('01')=='11'
assert invc_avant_dernier_un2('10')=='10'
assert invc_avant_dernier_un2('1001')=='1011'
assert invc_avant_dernier_un2('0011')=='0001'
assert invc_avant_dernier_un2('0000')=='0000'
assert invc_avant_dernier_un2('1000')=='1000'

#question 2.4
def suivante_gray(s:str)->str:
    """precondition:len(s)>0
precondition: s doit etre une chaine binaire
"""
    occ_1:int=0
    c:str
    for c in s:
        if c=='1':
            occ_1=occ_1+1
    if occ_1%2==0:
        return s[:-1] + inverse_char(s[-1])
    else:
        return invc_avant_dernier_un2(s)

assert suivante_gray('000')=='001'
assert suivante_gray('001')=='011'
assert suivante_gray('011')=='010'
assert suivante_gray('010')=='110'
assert suivante_gray('110')=='111'
assert suivante_gray('111')=='101'
assert suivante_gray('101')=='100'
assert suivante_gray('100')=='100'

#Question 2.5
def est_ordonnee(L:List[str])->bool:
    """precondition : L ne contient que des chaines bianires
Teste si dans L, toute chaine est suivie des sa chaine suivante de Gray"""
    i:int
    for i in range(len(L)-1):
        if L[i+1]!=suivante_gray(L[i]):
            return False
    return True

assert est_ordonnee([])==True
assert est_ordonnee(["1"])==True
assert est_ordonnee(["0","1"])==True
assert est_ordonnee(['000','001','011','010','110','111','101','100'])==True
assert est_ordonnee(['000','001','010'])==False

#Question 2.6
def miroir_pref(L:List[str])->List[str]:
    """renvoie.................."""
    return ['0'+var for var in L]+['1'+var for var in L[::-1]]

assert miroir_pref([])==[]
assert miroir_pref(["0","1"])==['00','01','11','10']
assert miroir_pref(["a","b"])==['0a','0b','1b','1a']

#Question 2.7
def liste_n(n:int)->List[str]:
    """precondition:n>0
renvoie la liste comportant les elements de Ln
"""
    if n==1:
        return ['0','1']
    else:
        return miroir_pref(liste_n(n-1))

assert liste_n(1)==['0','1']
assert liste_n(2)==['00','01','11','10']
assert liste_n(3)==['000','001','011','010','110','111','101','100']






    

