#exercice 8.1

#Question 1
def repetition_comp(x:T,k:int)->List[T]:
    """renvoie en utilisant une comprehension la liste contenant k occurences de x"""
    return [x for i in range(k)]
assert repetition_comp("er",3)==["er","er","er"]

#Question 2
def liste_div_comp(a:int)->List[int]:
    """precondition : a>0
Renvoie la liste des diviseurs de a en utilisant une comprehension de liste"""
    return [k for k in range(1,a+1)  if a%k==0]
assert liste_div_comp(18)==[1,2,3,6,9,18]

#Question 3
def liste_div_impairs_comp(a:int)->List[int]:
    """precondition: a>0
Renvoie la liste des diviseurs impairs de a utilisant une comprehension de liste"""
    return [k for k in range(1,a+1) if a%k==0 and k%2==1]
assert liste_div_impairs_comp(24)==[1,3]


#exercice 8.2

#Question 1
def alphabet()->List[str]:
    """constitue les lettres de l'alphabet a l'aide d'une comprehension"""
    return [ chr(k) for k in range(97,123)]
print(alphabet())

#question 2
def est_voyelle(c:str)->bool:
    """precondition: len(c)==1
teste si c est une voyelle de l'alphabet des 26 lettres"""
    return c=="a" or c=="e" or c=="i" or c=="o" or c=="u" 

assert est_voyelle('e')
assert not est_voyelle('b')

#question 3
#expression de comprehension permettant d'obtenir la liste des voyelles de l'aphabet
#[k for k in alphabet() if est_voyelle(k)]
def list_voyelle()->List[str]:
    """renvoie la liste des voyelles de l'aphabet"""
    return [k for k in alphabet() if est_voyelle(k)]
print("Les voyelles sont: ",list_voyelle())

#question 4
#expression de comprehension permettant d'obtenir la liste des consonnes de l'aphabet
#[k for k in alphabet() if nor est_voyelle(k)]
def list_conson()->List[str]:
    """renvoie la liste des consonnes de l'aphabet"""
    return [k for k in alphabet() if not est_voyelle(k)]
print("Les consonnes sont: ",list_conson())
