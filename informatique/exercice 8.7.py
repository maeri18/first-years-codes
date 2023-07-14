#exercice 8.7
#Question 1
def triplets(n:int)->List[Tuple[int,int,int]]:
    """renvoie la liste des triplets (i,j,k) sur l'intervalle [1;n]"""
    return [(i,j,k) for i in range(1,n+1)
                        for j in range (1,n+1)
                            for k in range(1,n+1)]
assert triplets(0)==[]
assert triplets(1)==[(1,1,1)]
assert triplets(2)==[(1,1,1),(1,1,2),(1,2,1),(1,2,2),(2,1,1),(2,1,2),(2,2,1),(2,2,2)]   

#Question 2
def decomposition(n:int)->List[Tuple[int,int,int]]:
    """renvoie la liste des decompositions sur [1;n], c'est a dire les triplets (i,j,k) de [1;n] tels que i+j=k"""
    return [(i,j,k) for i,j,k in triplets(n) if j+i==k]
assert decomposition(0)==[]
assert decomposition(1)==[]
assert decomposition(2)==[(1,1,2)]
assert decomposition(3)==[(1,1,2),(1,2,3),(2,1,3)]
assert decomposition(4)==[(1,1,2),(1,2,3),(1,3,4),(2,1,3),(2,2,4),(3,1,4)]

#Question 3
def encadrements_1(n:int)->List[Tuple[int,int,int]]:
    """renvoie la liste des encadrements sur [1;n], c'est a dire les triplets (i,j,k) de [1;n] tels que i<=j<=k avec une methode donnee (1)"""
    return [(i,j,k) for i,j,k in triplets(n) if i<=j<=k]

def encadrements_2(n:int)->List[Tuple[int,int,int]]:
    """renvoie la liste des encadrements sur [1;n], c'est a dire les triplets (i,j,k) de [1;n] tels que i<=j<=k avec une methode donnee (2)"""
    return [(i,j,k) for i in range(1,n+1)
                        for j in range(i,n+1)
                            for k in range(j,n+1)]

assert encadrements_1(0)==[]
assert encadrements_1(1)==[(1,1,1)]
assert encadrements_1(2)==[(1,1,1),(1,1,2),(1,2,2),(2,2,2)]

assert encadrements_2(0)==[]
assert encadrements_2(1)==[(1,1,1)]
assert encadrements_2(2)==[(1,1,1),(1,1,2),(1,2,2),(2,2,2)]
