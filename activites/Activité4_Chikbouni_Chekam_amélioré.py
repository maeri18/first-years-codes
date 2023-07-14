def identite(s:str)->str:
    """Renvoie la chaine s telle quelle"""
    return s
def identite_texte(nom : str) -> None:
    """précondition : <nom>.txt est un fichier existant
    recopie le contenu du fichier <nom>.txt dans <nom>_copie.txt"""
    with open(nom + ".txt","r") as source :
        with open (nom + "_copie.txt", "w") as destination:
            ligne:str
            for ligne in source.readlines():
                destination.write(identite(ligne))

#Partie Guidée
#Question 1
def est_minuscule(s:str)->bool:
    """précondition: len(s)==1
    teste si s est une lettre minuscule """
    if ord("a")<=ord(s)<=ord("z"): #condition qui permet de savoir si s est une lettre minuscule
        return True
    else:
        return False

def est_majuscule(s:str)->bool:
    """précondition: len(s)==1
    teste si s est une lettre majuscule """
    if ord("A")<=ord(s)<=ord("Z"):#condition qui permet de savoir si s est une lettre majuscule
        return True
    else:
        return False
assert est_minuscule ("a")
assert est_minuscule ("g")
assert not est_minuscule ("P")
assert est_majuscule ("R")
assert est_minuscule ("c")


#Q2;
def caractere_decale(c:str,n:int)->str:
    """precondition: len(c)==1 and -26<=n<=26
    renvoie le caractere decalé de n"""
    if n>=0:
        if est_majuscule(c):
            if ord(c)+n<=ord("Z"): #condition qui permet de ne pas sortir de l'ensemble des lettres de l'alphabet
                return chr(ord(c)+n)
            else:#cas où il est possible de déborder l'ensemble des lettres pour aller vers d'autres caractères
                return chr(n-(ord("Z")-ord(c))-1+ord("A"))
        elif est_minuscule(c):
            if ord(c)+n<=ord("z"):#condition qui permet de ne pas sortir de l'ensemble des lettres de l'alphabet
                return chr(ord(c)+n)
            else:#cas où il est possible de déborder l'ensemble des lettres pour aller vers d'autres caractères
                return chr(n-(ord("z")-ord(c))-1+ord("a"))
        else:
            return c
    else:
        if est_majuscule(c):
            if ord(c)+n>=ord("A"):#condition qui permet de ne pas sortir de l'ensemble des lettres de l'alphabet
                return chr(ord(c)+n)
            else:#cas où il est possible de déborder l'ensemble des lettres pour aller vers d'autres caractères
                return chr(n+(ord(c)-ord("A"))+1+ord("Z"))
        elif est_minuscule(c):
            if ord(c)+n>=ord("a"):#condition qui permet de ne pas sortir de l'ensemble des lettres de l'alphabet
                return chr(ord(c)+n)
            else:#cas où il est possible de déborder l'ensemble des lettres pour aller vers d'autres caractères
                return chr(n+(ord(c)-ord("a"))+1+ord("z"))
        else:
            return c
            

assert caractere_decale("A",3)== "D"
assert caractere_decale("a",3)== "d"
assert caractere_decale(" ", 9)== " "
assert caractere_decale("4", 9)== "4"
assert caractere_decale("D",-3)=="A"
assert caractere_decale("d",-3)=="a"
        

#Q3
def ligne_chiffre_cesar(s:str,n:int)->str:
    """precondition: 0<=n<=26
renvoie la chaine obtenue en appliquant le chiffrement de césar"""
    l:str#variable pour la boucle for
    res:str=""
    for l in s:
        res=res+caractere_decale(l,n)
    return res
assert ligne_chiffre_cesar ("Bonjour LU1IN011",3)=="Erqmrxu OX1LQ011"
assert ligne_chiffre_cesar ("Bonjour LU1IN011",0)=="Bonjour LU1IN011"
    
#Q4
def ligne_dechiffre_cesar(s:str,n:int)->str:
    """precondition: 0<=n<=26
renvoie la chaine obtenue en appliquant le chiffrement de césar"""
    l:str
    res:str=""
    for l in s:
        res=res+caractere_decale(l,-n)
    return res
assert ligne_dechiffre_cesar ("Erqmrxu OX1LQ011",3)=="Bonjour LU1IN011"
assert ligne_dechiffre_cesar ("Bonjour LU1IN011",0)=="Bonjour LU1IN011"
beaute1:str="Je suis belle, o mortels! comme un reve de pierre"
assert ligne_dechiffre_cesar(ligne_chiffre_cesar(beaute1,12),12)==beaute1
#Q4

def chiffre_fichier_cesar(nom:str, n:int)->None:
    """precondition :  0<=n<=26
chiffre le texte du fichier nom.txt et renvoie le resultat dans nom_cesar.txt"""
    with open(nom + ".txt","r") as source :
        with open (nom + "_chiffré.txt", "w") as destination:
            ligne:str
            for ligne in source.readlines():
                destination.write(ligne_chiffre_cesar(ligne,n))

def dechiffe_fichier_cesar(nom:str, n:int)->None:
    """precondition : 0<=n<=26
chiffre le texte du fichier nom.txt et renvoie le resultat dans nom_cesar.txt"""
    with open(nom + ".txt","r") as source :
        with open (nom + "_dechiffré.txt", "w") as destination:
            ligne:str
            for ligne in source.readlines():
                destination.write(ligne_dechiffre_cesar(ligne,n))
    

#Suggestion : Attaque
def attaque_cesar(nom:str)->None:
    """Essaie de dechiffre un texte crypte avec un chiffre de Cesar"""
    with open(nom + ".txt","r") as source:
        with open(nom + "_attaqué.txt","w") as destination:
            texte:List[str]=source.readlines()
            i:int 
            k:int
           
            for k in range(0,26):
                destination.write("\n_______________________\n")
                destination.write("Decalage de : "+str(k)+"\n")
                destination.write("_______________________\n")
                i=12
                while i<=17:
                    destination.write(ligne_dechiffre_cesar(texte[i],k))
                    i=i+1
               
#attaque_cesar("tochiffre_chiffré")
                    
#Suggestion : chiffre affine
def ligne_chiffre_affine(ligne:str,a:int,b:int)->str:
    """renvoieeee"""
    a1 : int = a
    b1:int = b
    if a1%2 == 0 or a1%13==0:
       while a1%2==0 or a1%13==0:
          a1 = a1 + 1
          
    c:str
    res:str=''
    position_c:int
    new_position:int
    for c in ligne:
        
        if est_minuscule(c):
            position_c = ord(c)-ord('a')
            new_position = (a1*position_c + b1)%26
            res = res + chr(ord('a') + new_position)
        elif est_majuscule(c):
            position_c = ord(c)-ord('A')
            new_position = (a1*position_c + b1)%26
            res = res + chr(ord('A') + new_position)
        else:
            res = res + c
    return res

assert ligne_chiffre_affine("Bonjour LU1IN011!",3,7) == "Kxuixpg OP1FU011!"
assert ligne_chiffre_affine("Bonjour LU1IN011!",2,7) == "Kxuixpg OP1FU011!"
assert ligne_chiffre_affine("Bonjour LU1IN011!",14,47) == "Kxiaxjq EJ1LI011!"


def Euclide_etendu(a:int,n:int)->int:
    """renvoie l'inverse modulo n de a"""
    r :int=a
    u :int=1
    r1:int=n
    u1:int=0
    q:int
    rs:int
    us:int
    while r1!=0:
        q=r//r1
        rs=r
        us=u
        r=r1
        u=u1
        r1=rs-q*r1
        u1=us-q*u1
           
    return u
assert Euclide_etendu(3,26)==9
assert Euclide_etendu(26,3)==-1
        
def ligne_dechiffre_affine(ligne:str,a:int,b:int)->str:
    """renvoie le le resultat du dechiffrement affine du parametre ligne avec les cles a et b"""
    a1 : int = a
    b1:int = b
    a_inverse:int
    if a1%2 == 0 or a1%13==0:
       while a1%2==0 or a1%13==0:
          a1 = a1 + 1
    a_inverse=Euclide_etendu(a1,26)     
    c:str
    res:str=''
    position_c:int
    new_position:int
    
    for c in ligne:
        
        if est_minuscule(c):
            position_c = ord(c)-ord('a')
            new_position = ((position_c-b1)*a_inverse)%26
            res = res + chr(ord('a') + new_position)
        elif est_majuscule(c):
            position_c = ord(c)-ord('A')
            new_position = ((position_c-b1)*a_inverse)%26
            res = res + chr(ord('A') + new_position)
        else:
            res = res + c
    return res

assert ligne_dechiffre_affine("Kxuixpg OP1FU011!",3,7) == "Bonjour LU1IN011!"
assert ligne_dechiffre_affine("Kxuixpg OP1FU011!",2,7) == "Bonjour LU1IN011!"
assert ligne_dechiffre_affine("Kxiaxjq EJ1LI011!",14,47) == "Bonjour LU1IN011!"    
    
            
def chiffre_fichier_affine(nom:str, a:int,b:int)->None:
    """
chiffre le texte du fichier nom.txt avec le chiffrement affine et renvoie le resultat dans nom_affine.txt"""
    with open(nom + ".txt","r") as source :
        with open (nom + "_chiffré_affine.txt", "w") as destination:
            ligne:str
            for ligne in source.readlines():
                destination.write(ligne_chiffre_affine(ligne,a,b))

def dechiffe_fichier_affine(nom:str, a:int,b:int)->None:
    """
chiffre le texte du fichier nom.txt et renvoie le resultat dans nom_cesar.txt"""
    with open(nom + ".txt","r") as source :
        with open (nom + "_dechiffré_affine.txt", "w") as destination:
            ligne:str
            for ligne in source.readlines():
                destination.write(ligne_dechiffre_affine(ligne,a,b))
            

#suggestion : Chiffre de Vigenere:
#implementation du chiffre de Vigenere
def ligne_chiffre_vigenere(ligne:str,cle:str)->str:
    """renvoie le resultat du chiffrement du parametre ligne avec le chiffre de Vigenere"""
    l:str
    c:str=cle[0]
    position_c:int
    res:str=''
    i:int=0

    for l in ligne:
        if i==len(cle):
            i=0
        c=cle[i]
        if est_minuscule(l):
            if est_minuscule(c) :
                position_c = ord(c)-ord('a')
                res = res + caractere_decale(l,position_c)
                i=i+1
            elif est_majuscule(c):
                position_c = ord(c)-ord('A')
                res = res + caractere_decale(l,position_c)
                i=i+1
        elif est_majuscule(l):
            if est_minuscule(c) :
                position_c = ord(c)-ord('a')
                res = res + caractere_decale(l,position_c)
                i=i+1
            elif est_majuscule(c):
                position_c = ord(c)-ord('A')
                res = res + caractere_decale(l,position_c)
                i=i+1
        else:
            res=res+l
    return res

def ligne_dechiffre_vigenere(ligne:str,cle:str)->str:
    """renvoie le resultat du dechiffrement du parametre ligne avec le chiffre de Vigenere"""
    l:str
    c:str=cle[0]
    position_c:int
    res:str=''
    i:int=0

    for l in ligne:
        if i==len(cle):
            i=0
        c=cle[i]
        if est_minuscule(l):
            if est_minuscule(c) :
                position_c = ord(c)-ord('a')
                res = res + caractere_decale(l,-position_c)
                i=i+1
            elif est_majuscule(c):
                position_c = ord(c)-ord('A')
                res = res + caractere_decale(l,-position_c)
                i=i+1
        elif est_majuscule(l):
            if est_minuscule(c) :
                position_c = ord(c)-ord('a')
                res = res + caractere_decale(l,-position_c)
                i=i+1
            elif est_majuscule(c):
                position_c = ord(c)-ord('A')
                res = res + caractere_decale(l,-position_c)
                i=i+1
        else:
            res=res+l
    return res
assert ligne_chiffre_vigenere("Bonjour LU1IN011!","AAA") == "Bonjour LU1IN011!"

assert ligne_chiffre_vigenere("Bonjour LU1IN011!","Maths") == "Nogqggr EB1AZ011!" #erreur :SM1IG011!, il ont plutot decale vers l'arriere"
assert ligne_chiffre_vigenere("Bonjour LU1IN011!","c")==ligne_chiffre_cesar("Bonjour LU1IN011!",2)
assert ligne_dechiffre_vigenere(ligne_chiffre_vigenere(beaute1,"beaute"),"beaute") == beaute1


                                
        

    
    
