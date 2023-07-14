import random
# activité 1


#Question 1

def sujet(nbre : int)-> str:
    """précondition : (nbre>=1) and (nbre<=6)
        

    """
    if nbre == 1 :
        return "Miranda"
    elif nbre == 2 :
        return "Armin"
    elif nbre == 3 :
        return "Dagobert"
    elif nbre == 4 :
        return "Eren"
    elif nbre == 5 :
        return "Annie"
    elif nbre == 6 :
        return "Mikasa"


assert sujet(3) == "Dagobert"
assert sujet(5) == "Annie"


#Question 2

def verbe (nbre : int) -> str :
    """précondition : (nbre>=1) and (nbre<=6)"""
    if nbre == 1 :
        return "mange"
    elif nbre == 2 :
        return "fait"
    elif nbre == 3 :
        return "casse"
    elif nbre == 4 :
        return "capture"
    elif nbre == 5 :
        return "detruit"
    elif nbre == 6 :
        return "donne"


assert verbe(1) == "mange"
assert verbe(5) == "detruit"

def cod (nbre : int) -> str :
     """précondition : (nbre>=1) and (nbre<=6)"""
     if nbre == 1 :
        return "du chocolat"
     elif nbre == 2 :
        return "ses devoirs"
     elif nbre == 3 :
        return "la télé"
     elif nbre == 4 :
        return "des escargots"
     elif nbre == 5 :
        return "la route"
     elif nbre == 6 :
        return "du pain"


assert cod(1) == "du chocolat"
assert cod(4) == "des escargots"

def lieu (nbre : int ) -> str :
    """précondition : (nbre>=1) and (nbre<=6)"""
    if nbre == 1 :
        return "dans sa chambre"
    elif nbre == 2 :
        return "dans la foret"
    elif nbre == 3 :
        return "dans la boutique"
    elif nbre == 4 :
        return "dans la ville"
    elif nbre == 5 :
        return "pres de chez moi"
    elif nbre == 6 :
        return "a Paris"


assert lieu(2) == "dans la foret"
assert lieu(6) == "a Paris"

#Question 3

def phrase(a:int, b:int, c:int, d:int) -> str :
    """précondition : (a>=1) and (a<=6)
       précondition : (b>=1) and (b<=6)
       précondition : (c>=1) and (c<=6)
       précondition : (d>=1) and (d<=6)
    """
    return sujet(a) +" "+ verbe(b) + " " + cod (c)+ " " + lieu(d)+"."

assert phrase (3,1,1,2) == "Dagobert mange du chocolat dans la foret."
     
#Question 4
def de6 () -> int:
    """ de6 fournit de maniere aleatoire un entier compris entre 1 et 6"""
    i : float
    j : int
    i = random.random()
    i = 6 * i + 1
    j = int(i)
    return j

#Question 5
def phrase_aleatoire() -> str :
    """ Renvoie une chaine de caractere aleatoire """
    a : int; b : int; c : int; d : int
    a = de6()
    b = de6()
    c = de6()
    d = de6()
    return phrase(a,b,c,d)


# Cadavre exquis conditionnés
import random

def sujet2(nbre : int)-> str:
    """précondition : (nbre>=1) and (nbre<=6)
        

    """
    if nbre == 1 :
        return "Miranda"
    elif nbre == 2 :
        return "Armin"
    elif nbre == 3 :
        return "Dagobert"
    elif nbre == 4 :
        return "Eren"
    elif nbre == 5 :
        return "Annie"
    elif nbre == 6 :
        return "Mikasa"


assert sujet2(3) == "Dagobert"
assert sujet2(5) == "Annie"


def verbe2 (nbre : int) -> str :
    """précondition : (nbre>=1) and (nbre<=6)"""
    if nbre == 1 :
        return "mange"
    elif nbre == 2 :
        return "ment"
    elif nbre == 3 :
        return "casse"
    elif nbre == 4 :
        return "parle"
    elif nbre == 5 :
        return "detruit"
    elif nbre == 6 :
        return "accede"


assert verbe2(1) == "mange"
assert verbe2(5) == "detruit"

def cod2 (nbre : int) -> str :
     """précondition : (nbre>=1) and (nbre<=6)"""
     if nbre == 1 :
        return "du chocolat"
     elif nbre == 2 :
        return "a ses devoirs"
     elif nbre == 3 :
        return "la télé"
     elif nbre == 4 :
        return "a mon ami"
     elif nbre == 5 :
        return "la prune"
     elif nbre == 6 :
        return "a la fete"


assert cod2(1) == "du chocolat"
assert cod2(4) == "a mon ami"

def lieu2 (nbre : int ) -> str :
    """précondition : (nbre>=1) and (nbre<=6)"""
    if nbre == 1 :
        return "dans sa chambre"
    elif nbre == 2 :
        return "dans la foret"
    elif nbre == 3 :
        return "dans la boutique"
    elif nbre == 4 :
        return "dans la ville"
    elif nbre == 5 :
        return "pres de chez moi"
    elif nbre == 6 :
        return "a Paris"


assert lieu2(2) == "dans la foret"
assert lieu2(6) == "a Paris"



def phrase2(a:int, b:int, c:int, d:int) -> str :
    """précondition : (a>=1) and (a<=6)
       précondition : (b>=1) and (b<=6)
       précondition : (c>=1) and (c<=6)
       précondition : (d>=1) and (d<=6)
    """
    return sujet(a) +" "+ verbe(b) + " " + cod (c)+ " " + lieu(d)+"."

assert phrase2(3,1,1,2) == "Dagobert mange du chocolat dans la foret."
     

def phrase_aleatoire2() -> str :
    """ Renvoie une chaine de caractere aleatoire """
    a : int; b : int; c : int; d : int
    a = de6()
    b = de6()
    c = de6()
    d = de6()
    if (b%2 == 1):
        if(c%2 == 1):
            return phrase2(a,b,c,d)
        else:
            if c==6:
                return phrase2(a,b,c-1,d)
            else:
                return phrase2(a,b,c+1,d)
    else:
        if(c%2==0):
            return phrase2(a,b,c,d)
        else:
            if c==1:
                return phrase2(a,b,c+1,d)
            else:
                return phrase2(a,b,c-1,d)



    
