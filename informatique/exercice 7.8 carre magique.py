#exercice 7.8 : carres magiques
CarreMagique:List[List[int]]
CarreMagique = [[2,7,6],[9,5,1],[4,3,8]]

#question 1
def presence(n:int, lis:List[int])->bool:
    """dit si n est present dans lis"""
    i:int
    for i in lis:
        if i==n:
            return True

    return False

assert presence(5,[9,5,1])
assert not presence(4,[9,5,1])
#question 2
def mat_presence(n:int, llis:List[List[int]])->bool:
    """teste si n est present dans llis"""
    l1:List[int]
    for l1 in llis:
        if presence(n,l1):
            return True
    return False
assert mat_presence(5,[[1,2,3],[4,5,6]])==True
assert mat_presence(7,[[1,2,3],[4,5,6]])==False
assert mat_presence(7,CarreMagique)==True
assert mat_presence(10,CarreMagique)==False

#question 3
def verif_elems(n:int,ll:List[List[int]])->bool:
    """teste si tous les entiers de [1,n*n] sont dans ll"""
    i:int
    for i in range(1,n*n+1):
        if not mat_presence(i,ll):
            return False
    return True

assert verif_elems(3,CarreMagique)
assert not verif_elems(3,[[2,7,6],[8,5,1],[4,3,8]])

#quetsion 4
def somme_liste(lis:List[int])->int:
    """retourne la somme la somme des entiers de la liste lis"""
    somme:int=0
    i:int
    for i in lis:
        somme = somme+i
    return somme
assert somme_liste([2,7,6])==15
assert somme_liste([9,5,1])==15
assert somme_liste([4,3,8])==15
assert somme_liste([])==0

#Question 5
def verif_lignes(ll:List[List[int]],s:int)->bool:
    """teste si toutes les sous-listes de ll possedent la meme somme s"""
    lis:List[int]
    for lis in ll:
        if somme_liste(lis)!=s:
            return False
    return True

assert verif_lignes(CarreMagique,15)==True
assert verif_lignes(CarreMagique,16)==False
assert verif_lignes([[2,7,6],[8,5,1],[4,3,8]],15)==False

#question 6
def colonne(j:int,mat:List[List[int]])->List[int]:
    """
retourne la j-ieme colonne de mat"""
    col:List[int]=[]
    l:List[int]
    for l in mat:
        col.append(l[j])
    return col
assert colonne(0,[[2,7,6],[9,5,1],[4,3,8]])==[2,9,4]
assert colonne(1,[[2,7,6],[9,5,1],[4,3,8]])==[7,5,3]
assert colonne(2,[[2,7,6],[9,5,1],[4,3,8]])==[6,1,8]

#Question 7
def verif_colonnes(mat:List[List[int]],s:int)->bool:
    """ teste si toutes les colonnes de mat possedent la meme somme s"""
    j:int
    for j in range(len(mat)):
        if somme_liste(colonne(j,mat))!=s:
            return False
    return True
assert verif_colonnes(CarreMagique,14)==False
assert verif_colonnes(CarreMagique,15)==True
assert verif_colonnes([[2,7,6],[8,5,1],[4,3,8]],15)==False

#question 8
def diagonale_1(mat:List[List[int]])->List[int]:
    """renvoie la premiere diagonale de mat"""
    lres:List[int]=[]
    j:int
    for j in range(len(mat)):
        lres.append(mat[j][j])
    return lres
def diagonale_2(mat:List[List[int]])->List[int]:
    """renvoie la premiere diagonale de mat"""
    lres:List[int]=[]
    j:int
    for j in range(len(mat)):
        lres.append(mat[j][-1-j])
    return lres
assert diagonale_1([[2,7,6],[9,5,1],[4,3,8]])==[2,5,8]
assert diagonale_2([[2,7,6],[9,5,1],[4,3,8]])==[6,5,4]
assert diagonale_1([[4,14,15,1],[9,7,6,12],[5,11,10,8],[16,2,3,13]])==[4,7,10,13]
assert diagonale_2([[4,14,15,1],[9,7,6,12],[5,11,10,8],[16,2,3,13]])==[1,6,11,16]

#Question 9
def verif_magique(mat:List[List[int]])->bool:
    """teste si mat est un carre magique"""
    som:int=somme_liste(mat[0])
    return verif_elems(len(mat),mat) and verif_lignes(mat,som) and verif_colonnes(mat,som) and (somme_liste(diagonale_1(mat))==som) and (somme_liste(diagonale_2(mat))==som)
    
assert verif_magique(CarreMagique)==True
assert verif_magique([[2,7,6],[8,5,1],[4,3,8]])==False
    
    
    
