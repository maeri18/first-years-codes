#exercice 7.1
Complexe=Tuple[float,float]
#question 1
#partie reelle
def partie_reelle(z:Complexe)->float:
    """retourne   """
    R:float
    R,_=z
    return R
#partie imaginaire
def partie_imaginaire(z:Complexe)->float:
    """retourne   """
    I:float
    _,I=z
    return I
assert partie_reelle((2.0,3.0)) == 2.0
assert partie_imaginaire((2.0,3.0)) == 3.0
assert partie_reelle((0.0,1.0)) == 0.0

#question 2
def addition_complexe(z1:Complexe,z2:Complexe)->Complexe:
    """additionne z1 et z2"""
    return (partie_reelle(z1)+partie_reelle(z2),partie_imaginaire(z1)+partie_imaginaire(z2))
assert addition_complexe((1.0,0.0),(0.0,1.0))==(1.0,1.0)
assert addition_complexe((2.0,3.0),(0.0,1.0))==(2.0,4.0)

#Question 3
def produit_complexe(z1:Complexe,z2:Complexe)->Complexe:
    """renvoie le produit des complexes"""
    return(partie_reelle(z1)*partie_reelle(z2)-partie_imaginaire(z1)*partie_imaginaire(z2),partie_reelle(z1)*partie_imaginaire(z2)+partie_reelle(z2)*partie_imaginaire(z1))
assert produit_complexe((0.0,0.0),(1.0,1.0))==(0.0,0.0)
assert produit_complexe((0.0,1.0),(0.0,1.0))==(-1.0,0.0)
assert produit_complexe((2.0,3.0),(0.0,1.0))==(-3.0,2.0)


#exercice 7.5

Point=Tuple[int,int]
#question 1
def vecteur(p1:Point,p2:Point)->Point:
    """Renvoie les coordonees du vecteur forme par p1 et p2"""
    a,b=p1
    c,d=p2
    return(c-a,d-b)
assert vecteur((2,4),(0,0))==(-2,-4)
assert vecteur((0,0),(3,7))==(3,7)
assert vecteur((2,3),(7,7))==(5,4)

#question 2
def alignes(p1:Point,p2:Point,p3:Point)->bool:
    """teste si p1 p2 et p3 sont alignes"""
    v1:Point=vecteur(p1,p2)
    v2:Point=vecteur(p2,p3)
    x1,y1=v1
    x2,y2=v2
    if v1==(0,0) or v2==(0,0):
        return True
    elif (x2//x1)==(y2//y1):
        return True
    else:
        return False
assert alignes((0,0),(1,1),(5,5))==True
assert alignes((0,0),(1,1),(1,2))==False

#question 3
def alignement(lst:List[Point])->bool:
    """precondition: len(lst)>=3
teste si les points de la liste lst sont alignes"""
    i:int
    for i in range(3,len(lst)):
        if not alignes(lst[0],lst[1],lst[i]):
            return False
    return True
assert alignement([(0,0),(1,1),(5,5)])
assert not alignement([(0,0),(1,1),(5,5),(1,0)])

#exercice 7.6
Etudiant = Tuple[str,str,int,List[int]]
BaseUPMC : List[Etudiant]
BaseUPMC=[('GARGA','Amel',20231343,[12,8,11,17,9]),('POLO','Marcello',20342241,[9,11,19,3]),('AMANGEAI','Hildegard',20244229,[15,11,7,14,12]),('DENT','Arthur',42424242,[8,4,9,4,12,5]),('ALEZE','Blaise',30012024,[17,15,20,14,18,16,20]),('D2','R2',10100101,[10,10,10,10,10,10])]

#question 1
def note_moyenne(lst:List[int])->float:
    """Retoune la moyenne d'une liste de notes"""
    if len(lst)==0:
        return 0.0
    else:
        somme:int=0
        i:int
        for i in lst:
            somme=somme+i
        return somme/len(lst)
assert note_moyenne([12,8,14,6,5,15])==10.0
assert note_moyenne([])==0.0

#question 2
def moyenne_generale(B:List[Etudiant])->float:
    """retourne la moyenne des moyennes des etudiant"""
    if len(B) == 0 :
        return 0
    else:
        somme_moyenne:float=0 
        moyenne_etudiant:float=0
        etudiant:Etudiant
        ll:List[int]
        for etudiant in B:
            _,_,_,ll=etudiant
            somme_moyenne = somme_moyenne + note_moyenne(ll)
        return(somme_moyenne/len(B))
        
assert moyenne_generale([])== 0.0
assert moyenne_generale(BaseUPMC) == 11.307142857142857

#question 3
def top_etudiant(bd:List[Etudiant])->Tuple[str,str]:
    """Precondition : len(bd) > 0
retourne un etudiant de la base bd avec la meilleure moyenne. Si des etudiants sont ex-aequo alors on retourne le premier dans l'ordre sequentiel de la liste."""
    _,_,_,lst=bd[0]
    max_moy:float=note_moyenne(lst)
    etu:Etudiant
    nom:str
    prenom:str
    ll:List[int]
    for etu in bd:
        _,_,_,ll= etu
        if note_moyenne(ll)>max_moy:
            nom,prenom,_,_=etu
    
    return(nom,prenom) 
assert top_etudiant(BaseUPMC)== ('ALEZE', 'Blaise')    

#Question 4
def recherche_moyenne(rnum:int,bd:List[Etudiant])->Optional[float]:
    """Retourne la moyenne de l'etudiant de numero d'etudiant rnum s'il existe"""
    etu:Etudiant
    lst:List[int]
    num:int
    for etu in bd:
        _,_,num,lst=etu
        if num==rnum:
            return(note_moyenne(lst))
    return None
assert recherche_moyenne(20244229,BaseUPMC)==11.8
assert recherche_moyenne(20342241,BaseUPMC)==10.5
assert recherche_moyenne(2024129111,BaseUPMC)==None


