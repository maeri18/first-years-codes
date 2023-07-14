#**********************************************************************************************************************************
#               ****Exercice 12.1****

#Question 1
def censurer(l:List[str],interdits:Set[str])->None:
    """***Procedure***"""
    c:int
    for c in range(len(l)):
        if l[c]in interdits:
            l[c]='***CENSURE***'
t0:List[str]=["le","loup","est","un","loup","pour","l'","homme"]
print(t0)
assert censurer(t0,{"loup","homme"})==None
print(t0)


#Question 2
def decaler(l:List[T], k:int)->None:
    """***Procedure***"""
    i:int
    d:int=len(l)
    j:int
    temp:T
    j1:int
    for i in range(int(abs(k))):     
        if k>0:
            temp=l[d-1]
            for j in range(d):
                l[d-j-1]=l[d-j-2]
            l[0]=temp
        else:
            temp=l[0]
            for j1 in range(d-1):
                l[j1]=l[j1+1]
            l[d-1]=temp
            
        
        
l1:List[int]=[1,2,3,4,5,6]
print("\nl1:\n",l1)
assert decaler(l1,2)==None
print(l1)
l2:List[int]=[1,2,3,4,5,6]
print("\nl2:\n",l2)
assert decaler(l2,-2)==None
print(l2)
l3:List[int]=[1,2,3,4,5,6]
print("\nl3:\n",l3)
assert decaler(l3,50)==None
print(l3)
l4:List[int]=[1,2,3,4,5,6]
print("\nl4:\n",l4)
assert decaler(l4,0)==None
print(l4)
l5:List[int]=[1,2,3,4,5,6]
print("\nl5:\n",l5)
assert decaler(l5,5)==None
print(l5)

#**********************************************************************************************************************************
#                                 ****Exercice 12.2 : Rotation de 180****        


Matrice=List[List[int]]

def inverser(l:List[T])->None:
    """***Procedure***
    Renverser la liste l en place"""
    k:int
    for k in range(0,len(l)//2):
        temp:T=l[k]
        l[k]=l[len(l)-k-1]
        l[len(l)-k-1]=temp

#Question 1
def inverser_lignes(m:Matrice)->None:
    """***Procedure***"""
    inverser(m)

#Question 2
def inverser_colonnes(m:Matrice)->None:
    """***Procedure***"""
    a:List[int]
    for a in m:
        inverser(a)

#Question 3
def demitour(m:Matrice)->None:
    """***Procedure***"""
    inverser_lignes(m)
    inverser_colonnes(m)

m3:Matrice= [[1,2,3],[4,5,6],[7,8,9]]
print(m3)
assert demitour(m3)==None
print(m3)

#************************************************************************************************************************
#               *****Exercice 12.3 :Rotation de 90 degres en place******

#Question 1

def tourner_sous_matrice(m:Matrice, x:int, y:int, k:int)->None:
    """***Procedure***
   
    precondition : m une matrice carree"""
    i:int=x
    j:int=y
    temp:int
    mil:int=k//2
    while i<mil+x:
        j=y
        while j<mil+y:
            #premiere inversion (rotation du premier cadrant
            temp=m[i][j]
            m[i][j]=m[i][j+mil]
            m[i][j+mil]=temp
            #rotation du deuxieme cadrant
            temp=m[i+mil][j+mil]
            m[i+mil][j+mil]=m[i][j]
            m[i][j]=temp
            #rotation des deux derniers cadrants
            temp=m[i+mil][j]
            m[i+mil][j]=m[i][j]
            m[i][j]=temp
            j=j+1
        i=i+1
   

def printm(m:Matrice)->None:
    """print une matrice"""
    a:List[int]
    for a in m:
        print(a)
    print('\n\n')
    
m10:Matrice=[[0,0,0,0],[0,1,2,0],[0,3,4,0],[0,0,0,0]]
assert printm(m10)==None
assert tourner_sous_matrice(m10,1,1,2)==None
assert printm(m10)==None

m11:Matrice=[[1,2,3,4,0,0,0,0],[5,6,7,8,0,0,0,0],[9,10,11,12,0,0,0,0],[13,14,15,16,0,0,0,0],[0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0]]

assert printm(m11)==None
assert tourner_sous_matrice(m11,0,0,4)==None
assert printm(m11)==None

    
#Question 2
def tourner_matrice(m:Matrice,k:int)->None:
    """***Procedure***
    precondition : M une matrice carree
    precondition : len(m)%k==0"""

    i:int
    j:int
    for i in range(0,len(m),k):
        for j in range(0,len(m),k):
            tourner_sous_matrice(m,i,j,k)

m12:Matrice=[[0,0,0,0],[0,1,2,0],[0,3,4,0],[0,0,0,0]]
assert printm(m12)==None
assert tourner_matrice(m12,2)==None
assert printm(m12)==None

m13:Matrice=[[0,0,0,0],[0,1,2,0],[0,3,4,0],[0,0,0,0]]
assert printm(m13)==None
assert tourner_matrice(m13,1)==None
assert printm(m13)==None

m14:Matrice=[[0,0,0,0],[0,1,2,0],[0,3,4,0],[0,0,0,0]]
assert printm(m14)==None
assert tourner_matrice(m14,4)==None
assert printm(m14)==None
            
    
#Question 3
def tourner(m:Matrice)->None:
    """***Procedure***
    precondition : M une matrice de dimension 2^n
    """
    i:int
    for i in range(2,len(m)+1):
        if len(m)%i==0:
            tourner_matrice(m,i)
        

m5:Matrice=[[l for l in range(2**3*k, 2**3*(k+1))]for k in range(2**3)]
assert printm(m5)==None
assert tourner(m5)==None
assert printm(m5)==None

#**********************************************************************************************************************************
#               ****Exercice 12.4****

#Question 1
def trier_bulles(L:List[T])->None:
    """***Procedure***"""
    i:int
    j:int
    temp:T
    for i in range(len(L)):
        for j in range(len(L)-i-1):
            if L[j]>L[j+1]:
                temp=L[j+1]
                L[j+1]=L[j]
                L[j]=temp
            

l0:List[int]=[6,1,3,2,4,5]
print(l0)
assert trier_bulles(l0)==None
print(l0,"\n\n")

l11:List[int]=[1,0,0,1,0,1,1]
print(l11)
assert trier_bulles(l11)==None
print(l11,"\n\n")

#Question 2
def trier_bulles_optim(L:List[T])->None:
    """***Procedure***"""
    i:int=0
    j:int=0
    temp:T
    exchange:bool=True 
    while i <len(L) and exchange == True:
        j=0
        exchange= False
        while j<len(L)-i-1:
            
            if L[j]>L[j+1]:
                temp=L[j+1]
                L[j+1]=L[j]
                L[j]=temp
                exchange = True
            j=j+1
        i=i+1

ll0:List[int]=[6,1,3,2,4,5]

print(ll0)
assert trier_bulles_optim(ll0)==None
print(ll0)

#**************************************************************************************************************************************
#                   ****Exercice 12.5****

#Question 1
def partitionner(L:List[T])->int:
    """***Procedure***"""
    pivot:int=0
    i:int
    j:int=0
    temp:T
    for i in range(len(L)):
        if L[i]<L[pivot]:
            j=i
            while j>pivot:
                temp=L[j-1]
                L[j-1]=L[j]
                L[j]=temp
                j=j-1
            pivot=pivot+1
    return pivot

                     
ll3:List[int]=[2,1,4,0,3]
print(ll3)
assert partitionner(ll3)==2
print(ll3)

#Question 2
def partitionner_s1(L:List[T],i:int,j:int)->int:
    """***Procedure***
    precondition : 0<=i<=j<=len(L)"""
    pivot:int=i
    a:int
    b:int=0
    temp:T
    for a in range(i,j):
        if L[a]<L[pivot]:
            b=a
            while b>pivot:
                temp=L[b-1]
                L[b-1]=L[b]
                L[b]=temp
                b=b-1
            pivot=pivot+1
    return pivot

L1:List[int]=[8,5,2,1,3,0,4,6,7]
print(L1)
assert partitionner_s1(L1,2,7)==4
print(L1)

#Question 3
def trier_rapide_s1(l:List[T],i:int,j:int)->None:
    """***Procedure***
       Precondition : 0<=i<=j<=len(l)
       Trie la sous-liste de l allant de i (inclus) a j (exclus)
    """
    ip:int #indice du pivot
    if i!=j:
        ip = partitionner_s1(l,i,j)
        trier_rapide_s1(l,i,ip)
        trier_rapide_s1(l,ip+1,j)

ll4:List[int] = [8,5,2,1,3,0,4,6,7]
assert trier_rapide_s1(ll4,2,7)==None
assert ll4 == [8,5,0,1,2,3,4,6,7]

ll5:List[int] =[8,5,2,1,3,0,4,6,7]
assert trier_rapide_s1(ll5,0,3)==None
assert ll5 == [2,5,8,1,3,0,4,6,7]

ll6 : List[int] = [8,5,2,1,3,0,4,6,7]
assert trier_rapide_s1(ll6,0,9)==None
assert ll6 == [0,1,2,3,4,5,6,7,8]
    
                            ####**************************####
def trier_rapide(L:List[T])->None:
    """***Procedure***
    """
    trier_rapide_s1(L,0,len(L))
        
ll7:List[int] = [4,2,1,5,3,6]
print(ll7)
assert trier_rapide(ll7)==None
print(ll7)
    
  
    
