#exercice 8.6
Etudiant = Tuple[str,str,int,List[int]]
BaseUPMC:List[Etudiant]
BaseUPMC = [('GARGA','Amel',20231343,[12,8,11,17,9]),('POLO','Marcello',20342241,[9,11,19,3]),('AMANGEAI','Hildegard',20244229,[15,11,7,14,12]),('DENT','Arthur',42424242,[8,4,9,4,12,5]),('ALEZE','Blaise',30012024,[17,15,20,14,18,16,20]),('D2','R2',10100101,[10,10,10,10,10,10])]

#Question 1
def mauvaise_note(etu:Etudiant)->bool:
    """teste si etu a au moins une note inferieure a la moyenne"""
    _,_,_,notes=etu
    i:int
    for i in notes:
        if i<10:
            return True
    return False

#Question 2 : note qu'ici on a demandé une expression de comprehension, mais moi je vais faire une fonction pour pouvoir tester si tout marche bien
def etu_mauvaise_note(BD:List[Etudiant])->List[Etudiant]:
    """retourne la liste des etudiants qui ont au moins une mauvaise note"""
    return [k for k in BD if mauvaise_note(k)]
assert etu_mauvaise_note(BaseUPMC)== [('GARGA','Amel',20231343,[12,8,11,17,9]),('POLO','Marcello',20342241,[9,11,19,3]),('AMANGEAI','Hildegard',20244229,[15,11,7,14,12]),('DENT','Arthur',42424242,[8,4,9,4,12,5])]

#Question 3 : meme chose qu'en haut
def nom_mauvaise_note(BD:List[Etudiant])->List[str]:
    """retourne la liste des noms des etudiants qui one eu au moins une mauvaise note"""
    return [s for s,_,_,_ in etu_mauvaise_note(BD)]

assert nom_mauvaise_note(BaseUPMC)==['GARGA','POLO','AMANGEAI','DENT']

#question 4: encore meme chose (eh oui )
def num_bonne_note(BD:List[Etudiant])->List[int]:
    """renvoie les numeros etudiants des etudiants qui n'ont que des bonnes notes"""
    l:List[Etudiant] =  [ i for i in BD if not mauvaise_note(i)]
    return [k for _,_,k,_ in l]
    #le resultat de cette fonction est [30012024, 10100101]


