#exercice 1.1

#question 1 :
#  *****définition de la fonction moyenne_trois_nb 

def moyenne_trois_nb(a:float,b:float,c:float)->float:
    """Calcule la moyenne de trois nombres a,b et c"""
    return (a + b + c)/3.0

#  *****Jeu de tests
assert moyenne_trois_nb(3,6,-3) == 2
assert moyenne_trois_nb(-3,0,3) == 0
assert moyenne_trois_nb(1.5,2.5,1.0) == 5/3
assert moyenne_trois_nb(9,2,1) == 4

#question 2 :
#   *****définition de la fonction moyenne_ponderée
def moyenne_ponderee(a:float, b:float, c:float, pa:float, pb:float, pc:float)-> float :
    """précondition : 5(pa+pb+pc =! 0 )
       Calcule la moyenne ponderée de a, b et c affectés respectivement des coefficients pa,         pb et pc"""
    return (pa * a + pb * b + pc * c) / (pa + pb + pc)

#  *****Jeu de tests
assert moyenne_ponderee(1.0,2.0,3.0,0.5,1.0,0.75)==4.75/2.25
assert moyenne_ponderee(2.5,3.0,0.25,1.0,5.0,2.0)==2.25
assert moyenne_ponderee(1.0,2.0,7.5,3.75,5.0,3.0)==36.25/11.75


#exercice 1.2
#question 1 :
#********definition de la fonction prix_ttc

def prix_ttc (HT :float, TVA:float) ->float :
    """ précondition : (HT >= 0)
        précondition : (TVA >=0)  and (TVA <=100)
        Calcule le prix toutes taxes comprises à partir d'un prix hors taxes pour un taux de          TVA donné """
    return HT+(HT*TVA)/100.0

#  *****Jeu de tests
assert prix_ttc(10.0,20.0) == 12.0
assert prix_ttc(130.0,10.0) == 143.0
assert prix_ttc(100.0,20.0) == 120.0
assert prix_ttc(0,20.0) == 0.0

#question 2 :
#********definition de la fonction prix_ht

def prix_ht(TTC:float, TVA:float) ->float :
    """ précondition : (TTC >=0)
        précondition : (TVA <= 100)  and (TVA >=0)
        Calcule le prix hors taxes à partir du prix toutes taxes comprises et de la TVA"""
    return (TTC)/(1.0 + (TVA /100.0))

assert prix_ht(12.0,20.0) == 10.0
assert prix_ht(143.0,10.0) == 130.0
assert prix_ht(120.0,20.0) == 100.0
assert prix_ht(0.0,20.0) == 0.0


#exercice 1.8

#question 1
# l'évaluation de 42 est 42. c'est une expresion atomique
# l'évaluation de type(42) est <class 'int'> . Python donne le type de l'expression 42
# l'évamuation de 2.3 est 2.3. C'est une expression atomique
# l'évaluation de True est True.
# l'evaluation de type(True) donne <class 'bool'>. Python donne le type de True
# l'evaluation de "chaine de caracteres" est 'chaine de caracteres'. On note que les guillemets doubles ont étés remplacés par des guillemets simples. Ceci est dû à la façon dont python evalue les chaines de caracteres.
# l'evaluation de type(chaine de caracteres) donne <class 'str'>. Ce aui veut dire que "chaine de caracteres est de type str
# l'evaluation de 3+2 donne 5. Ici, python evalue les expressions atomiques 2 et 3, et fait leur somme (+) avant de renvoyer le resultat 5.
# l'evaluation de 6*2 donne 12. L'interprete python evalue les expressiosn atomiques 6 et 2 puis fait leur produit et renvoie le résultat 12
# l'evaluation de 6**2 donne 36. L'interprete python evalue 6 , 2 puis fait le calcul 6 puissance 2 et renvoie le resultat 36.
# l'evaluation de 10 > 23 donne false. L'interprete python evalue la valeur de verite de l'expression composee 10>23 puis renvoie le resultat sous forme d'un objet de type Bool : False.


#question2
# l'evaluation de "essai" == "essai" donne True. L'interprète python compare les chaines de caractères situées de part et d'autre de ==, trouve qu'elles sont équivalentes et renvoie un objet de type Bool correspondant à la valeur de vérité de la comparaison, c'est à dire True.

# l'evaluation de "essai" == "essai "donne False. L'interprète python compare les chaines de caracteres "essai" et "essai " et trouve qu'elles ne sont pas équivalentes à cause du caractère d'espacement à la fin de la deuxième chaine. Il renvoie alors False, un objet de type Bool correspondant à la valeur de vérité trouvée après la comparaison des chaines.

# l'evaluation de "3" == 3 donne False, car "3" est un objet de type str et 3 est un objet de type int.

# l'evaluation de 4 == 5 donne False, l'interprete python evalue 4 et 5 comme des objets de types int (des entiers) et algébriquement 4 est different de 5. Donc on obtient False.

# l'evaluation de 4 == 4 donne True. L'interprete python evalue 4 et 4 comme des objets de types int (des entiers) et algébriquement 4 est égal 5. Donc on obtient True.

# l'evaluation de 4 == 2*2 donne True. L'interprète python evalue 







