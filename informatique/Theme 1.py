import math
#******************************************************************************
#                       ***Exercice 1***

#Question 1
def moyenne_trois_nb(a:float,b:float,c:float)->float:
    """Calcule la moyenne arithmetique de 3 nombres"""
    return (a+b+c)/3

#Question 2
def moyenne_ponderee(a:float,b:float,c:float,pa:float,pb:float,pc:float)->float:
    """Calcule la moyenne avec ponderation"""
    return (a*pa+b*pb+c*pc)/3

#******************************************************************************
#                       ****Exercice 2****
#Question 1
def prix_ttc(HT:float,TVA:float)->float:
    """Calcul du prix toutes taxes comprises"""
    return HT + HT*TVA/100

#Question 2
def prix_ht(TTC:float, TVA:float)->float:
    """calcul du prix hors taxes"""
    return TTC * 1/(1+TVA/100)

#******************************************************************************
#                       ***Exercice 3***

#Question 1
def polynomiale(a:float,b:float,c:float,d:float,x:float)->float:
    """Evalue le polynome ax^3 + bx^2 + c^x + d"""
    return a*x**3 + b*x**2 + c*x + d

#Question 2
def polynomiale_carre(a:float,b:float,c:float,x:float)->float:
    """Evalue le polynome ax^4+bx^2+c"""
    return a*x**4 + b*x**2 + c

#******************************************************************************
#                      ***Exercice 4 ***

#Question 1
def aire_disque(r:float)->float:
    """Evalue l'aire du disque de rayon r"""
    return math.pi * r**2

#Question 2

def aire_couronne(r1:float,r2:float)->float:
    """Evalue l'aire de la couronne entre r1 et r2"""
    return math.pi*abs(r1**2 - r2**2)

#******************************************************************************
#          ***Exercice 5***

#Question 1
def fahrenheit_vers_celsius(t:float)->float:
    """effectue la convertion fahrenheit --> celsius"""
    return (t-32)*5/9

#Question 2
def celsius_vers_fahrenheit(t:float)->float:
    """effectue la convertion celsius --> fahrenheit"""
    return 9/5 * t + 32

#******************************************************************************
#         ***Exercice 6***

def fermat(n:int)->float:
    """ calcule le n-ieme terme de la suite de fermat"""
    return 2**2**n + 1

#Question 2
# Expression permettant de verifier aue F5 est divisible par 641:
# fermat(5)//641 == 0
# Renvoie True si F5 est divisible par 641, et False sinon

#******************************************************************************
#       ***Exercice 7***

#Question 1
def excursion(nb_pers:int)->int:
    # je rajoute 1 pour eviter la division par la division par 0
    return nb_pers//60*1200 +nb_pers//18*300 + 1200*math.ceil((nb_pers%60)/(1+nb_pers)) + 300*math.ceil((nb_pers%18)/(1+nb_pers))

assert excursion(0)==0
assert excursion(1)==1500
assert excursion(18)==1500
assert excursion(60)==2400
assert excursion(61)==3600
assert excursion(150)==6300

#Question 2
def excursion2(nb_adu:int, nb_enf:int)->int:
    # je rajoute 1 pour eviter la division par la division par 0
    nb_pers :int =nb_adu + nb_enf
    return nb_pers//60*1200 +nb_adu//18*300 + nb_enf//8*250 + 1200*math.ceil((nb_pers%60)/(1+nb_pers)) + 300*math.ceil((nb_adu%18)/(1+nb_adu)) + 250*math.ceil((nb_enf%8)/(1+nb_enf))

assert excursion2(0,0) == 0
assert excursion2(1,0) == 1500
assert excursion2(0,1) ==1450
assert excursion2(18,0) == 1500
assert excursion2(0,8) == 1450
assert excursion2(18,8) == 1750
assert excursion2(36,14) == 2300
assert excursion2(150,120) == 12450

#*****************************************************************************
#     ****Exercice 9 ******

#Question 1
show_image(draw_line(-0.5,0.2,0.7,-0.5))

#Question 2
def dessine_carre(x:float,y:float,c:float)->Image:
    """precondition : -1<=x<=1 and -1<=y<=1
precondition : c>=0
    precondition: x+c <= 1 and y+c <= 1
"""
    
    return overlay(draw_line(x,y,x+c,y),draw_line(x,y,x,y+c),draw_line(x,y+c,x+c,y+c),draw_line(x+c,y,x+c,y+c))
show_image(dessine_carre(-0.5,-0.5,1))

#Question 3
#Affichage des figures

#Image 1
show_image(dessine_carre(-0.5,-0.5,1))

#Image 2
show_image(overlay(dessine_carre(-0.5,-0.5,1),draw_line(-0.5,0,0.5,0)))
#Image 3
show_image(overlay(draw_triangle(-0.5,-0.5,0.5,-0.5,0.5,0.5),fill_triangle(-0.5,-0.5,-0.5,0.5,0.5,0.5)))

#Image 4
show_image(overlay(fill_triangle(-0.5,0.5,0,0,-0.5,-0.5),dessine_carre(-0.5,-0.5,1)))

#Image 5
show_image(overlay(fill_triangle(0.5,0.5,0,0,0.5,-0.5),dessine_carre(-0.5,-0.5,1)))

#Image 6
show_image(overlay(dessine_carre(-0.5,-0.5,1),draw_ellipse(-0.5,-0.5,0.5,0.5)))

#Image 7
show_image(overlay(dessine_carre(-0.5,-0.5,1),fill_ellipse(-0.5,-0.5,0.5,0.5)))

#Image 8
show_image(overlay(fill_triangle(-0.5,0.5,0,0,-0.5,-0.5),dessine_carre(-0.5,-0.5,1),fill_triangle(0.5,0.5,0,0,0.5,-0.5)))

#Image 9
show_image(underlay(dessine_carre(-1,-1,2),fill_ellipse(0,-1,2,1),fill_ellipse(-2,-1,0,1)))

    
