#Activité  5
#Partie guidée
#question 1
def degre (p:List[int])->int:
    """renvoie le dégré du polynome représenté par la liste p"""
    i:int
    degre : int = 0
    for i in range (len(p)):
        if p[i]!=0:
            degre=i
    return degre
assert degre([3, 0, 2])==2
assert degre([])==0
assert degre([3,4,5,100,0, 0])==3
assert degre([0,0,0, 0])==0

#question2:
def somme(p:List[int], q:List[int])->List[int]:
    """effectue la sp """
    d:List[int]=[]
    i:int
    j:int
    if len(p)<len(q):
        for i in range (len(p)):
            d.append(p[i]+q[i])
        d=d+q[len(p):len(q)]
    else:
        for j in range (len(q)):
            d.append(p[j]+q[j])
        d=d+p[len(q):len(p)]
    return d
assert somme([3, 0, 2],[])==[3, 0, 2]
assert somme([3, 0, 2],[4,5,0,2])==[7,5,2,2]
assert somme([0, 0, 0],[])==[0,0,0]
assert somme([3, 0, 2],[2,-5,0])==[5,-5,2]

#question 3
def normalise(p:List[int])->List[int]:
    """ renvoie la forme normalisée de p"""
    if p==[] or (p[0]== 0 and degre(p)==0) :
        return []
    return p[:degre(p)+1]
                         
assert normalise([2,3,5,0,0,0])==[2,3,5]
assert normalise([2,3,0,0,4,0])==[2,3,0,0,4]
assert normalise([0,0,5,0,0,0])==[0,0,5]
assert normalise([1,3,8,2])==[1,3,8,2]
assert normalise([0,0,0,0])==[]
assert normalise([1,0,0])==[1]
assert normalise([])==[]

#question 4

def produit(p:List[int], q:List[int])->List[int]:
    """renvoie le produit des polynomes p et q"""
    q1:List[int] = q[:]
    p1:List[int] = p[:]
    j:int
    i:int
    k1:int
    k2:int
    lres : List[int]=[]
    coef : int =0
    for k1 in range(degre(p1)+degre(q1)-len(p1)+1):
        p1.append(0)
    for k2 in range(degre(p1)+degre(q1)-len(q1)+1):
        q1.append(0)
    for i in range(degre(q1)+degre(p1)+1):
        for j in range(i+1):
            coef = coef + p1[j]*q1[i-j]
        lres.append(coef)
        coef = 0
    
    return normalise(lres)
assert produit([3,0,2],[1,-1,1,-1,0])== [3,-3,5,-5,2,-2]
assert produit([3,0,2],[27])== [27*3,0,27*2]
assert produit([3,0,2],[3,0,2])==[9,0,12,0,4]
assert produit([1,1],[1,0,1])==[1,1,1,1]
assert produit([0,0],[2,3,4])==[]

#Suggestion : Autres operations
#multiplication par un entier
def multi(p:List[int],n:int)->List[int]:
    """renvoie le resultat de la multiplication du polynome p par l'entier n"""
    lres : List[int]=[]
    i:int
    for i in p:
        lres.append(i*n)
    return normalise(lres)

assert multi([3,0,2],2)== [2*3,0,2*2]
assert multi([3,0,2],0)==[]
assert multi([],23)==[]
#puissance entiere d'un polynome
def puissance(p:List[int],n:int)->List[int]:
    """renvoie la polynome obtenu en elevant p a la puissance n"""
    i:int
    lres:List[int]=p
    if n==0:
        return[1]
    elif n==1:
        return normalise(p)
    else:
        for i in range(1,n):
            lres = produit(lres,p)
        return normalise(lres)

assert puissance([3,0,0,2],2)== [9,0,0,12,0,0,4]
assert puissance([0,0],23)==[]
assert puissance([],23)==[]
assert puissance([2,3,4,5,0,8,0,8,7],0)==[1]
assert puissance([3,4,5],1)==[3,4,5]

#derivation d'un polynome
def derivee_poly(p:List[int])->List[int]:
    """renvoie la derivee du polynome p"""
    lres:List[int]=[]
    i:int
    for i in range(len(p)):
        lres.append(p[i]*i)
    return normalise(lres[1:])
assert derivee_poly([3,0,2])== [0,4]
assert derivee_poly([2,2,0,1])==[2,0,3]
assert derivee_poly([0,4,3,0])== [4,6]
assert derivee_poly([])==[]
assert derivee_poly([0,0])==[]


