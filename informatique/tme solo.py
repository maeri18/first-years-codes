#1.
#1.[506, 522, 529, 551, 552, 575, 580, 598, 609, 621, 638, 644, 667, 690, 696, 713, 725, 736, 754, 759, 782, 783, 805, 812, 828, 841, 851, 870, 874, 897, 899, 920, 928, 943, 957, 966, 986, 989]

#2.
def u(n:int)->int:
    if n==0:
        return 1
    elif n==1:
        return 1
    else:
        return u(n-2)*u(n-3)+1

#u(10)= 953476947989903  

#3. 22

#Probleme
Permutation = List[int]

#1.
def applique(L:List[int], p:Permutation)->List[int]:
    """precondition: len(L)==len(p)
precondition: p est une permutation de [1,len(L)]

"""
    lres:List[int]=[]
    i:int
    for i in range(len(L)):
        lres.append(L[p[i]-1])
    return lres
    
#2.
def a_un_pt_fixe(p:Permutation)->bool:
    """
teste si p a un point fixe"""
    if p==[]:
        return False
    else:
        i:int
        for i in range(len(p)):
            if p[i]==i+1:
                return True
        return False
#3.
def est_permutation(L:List[int])->bool:
    """teste si L est une permutation de [1,len(L)]"""
    i:int
    j:int
    in_:bool= False
    for j in range(1,len(L)+1):
        for i in range(len(L)):
       
            if L[i]==j:
                in_=True
        if in_==True:
            in_=False
        else:
            return False
    return True

#4.
def permut(L:List[int],i:int,j:int)->List[int]:
    """ precondition: i<=j<len(L)"""
    lres:List[int]=[]
    return L[:i]+[L[j]]+L[i+1:j]+[L[i]]+L[j+1:]

def permutation(n:int)->List[List[int]]:
    """precondition:n>=2
renvoie l liste de toutes les permutations de [1,n]"""
    L:List[List[int]]=[]
    lis:List[int]=[]
    i:int=1
    j:int
    temp:int
    while i <=n:
        lis.append(i)
        i=i+1
    i=1
    L.append(lis)
    lis=permut(lis,0,1)
    while lis!=L[0]:
        L.append(lis)
        if i%2==0:
            lis=permut(lis,0,1)
        else:
            lis=permut(lis,0,n-1)
        i=i+1
          
    return L
            
            
        
        
            
        
        
