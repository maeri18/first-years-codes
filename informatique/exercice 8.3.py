#exercice 8.3

#Question 1
def liste_non_multiple(n:int,l:List[int])->List[int]:
    """precondition : n>0
renvoie la liste contenant les elements de l qui ne sont pas multiples de n en utilisant les comprehensions"""
    return [k for k in l if k%n!=0]
assert liste_non_multiple(2,[2,3,4,5,6,7,8,9,10])==[3,5,7,9]
assert liste_non_multiple(3,[2,3,4,5])==[2,4,5]
assert liste_non_multiple(2,[2,4,6])==[]
assert liste_non_multiple(2,[])==[]
assert liste_non_multiple(7,[2,3,4,5])==[2,3,4,5]
#Question 2
def eratosthene(n:int)->List[int]:
    """precondition:n>0
renvoie la liste des nombres premiers inferieurs ou egaux a n"""
    i:int=2
    l:List[int]=[]
    lres:List[int]=[]
    while i < n+1:
        l.append(i)
        i=i+1
    while l!=[]:
        lres.append(l[0])
        l=liste_non_multiple(l[0],l) 
    return lres
assert eratosthene(10)==[2,3,5,7]
assert eratosthene(2)==[2]
assert eratosthene(40)==[2,3,5,7,11,13,17,19,23,29,31,37]

#Question 3

def liste_facteurs_premiers(n:int)->List[int]:
    """precondition: n >=2
renvoie la liste des facteurs premiers de n"""
    return [k for k in eratosthene(n) if n%k==0]

assert liste_facteurs_premiers(2)==[2]
assert liste_facteurs_premiers(10)==[2,5]
assert liste_facteurs_premiers(2*3*7)==[2,3,7]
