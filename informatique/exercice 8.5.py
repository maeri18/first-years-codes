#exercice 8.5 :Codage ROT13

#Question 1
def liste_caracteres(s:str)->List[str]:
    """renvoie la liste des carateres d'une chaine de caracteres passee en parametre"""
    return [ k for k in s]
assert liste_caracteres('les carottes')==['l','e','s',' ','c','a','r','o','t','t','e','s']
assert liste_caracteres('')==[]

#Question 2
def chaine_de(s:List[str])->str:
    """retourne la chaine de caracteres correspondant a la liste de caracteres passee en parametre"""
    sres:str=''
    c:str
    for c in s:
        sres=sres+c
    return sres
assert chaine_de(['s','a','l','u','t'])=='salut'
assert chaine_de([])==''
assert chaine_de(liste_caracteres('les carottes'))=='les carottes'

#Question 3
def num_car(c:str)->int:
    """precondition :  len(c)==1
    precondition: ord('a')<=ord(c)<=ord('z')
"""
    return ord(c)-ord('a')
assert num_car('a')==0
assert num_car('b')==1
assert num_car('z')==25

#Question 4
def car_num(n:int)->str:
    """precondition: 0<=n<=25
"""
    return chr(ord('a') + n)
assert car_num(0)=='a'
assert car_num(24)=='y'

#Question 5
def rot13(c:str)->str:
    """precondition : len(c)==1
"""
    
    if ord(c)<ord('a') or ord(c)>ord('z'):
        return c
    nbre:int=num_car(c)
    if nbre<=12:
        
        return car_num(nbre+13)
    else:
        return car_num(nbre-13)
assert rot13('a')=='n'
assert rot13('m')=='z'
assert rot13('b')=='o'
assert rot13('n')=='a'
assert rot13('o')=='b'
assert rot13('8')=='8'
assert rot13(' ')==' '

#Question 6
def codage_rot13(s:str)->str:
    """permet de coder en rot13 la chaine s"""
    return chaine_de([rot13(c) for c in s])
assert codage_rot13("abcdef")=="nopqrs"
assert codage_rot13("nopqrs")=="abcdef"
assert codage_rot13("les carottes sont cuites")=="yrf pnebggrf fbag phvgrf"
assert codage_rot13("yrf pnebggrf fbag phvgrf")=="les carottes sont cuites"

#question: Pour decoder le message, il suffit d'appliquer une deuxieme fois le codage ROT13
