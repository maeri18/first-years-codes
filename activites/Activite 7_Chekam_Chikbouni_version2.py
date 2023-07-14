#Activite 7
import random
#Partie Guidee
Coord = Tuple[int,int] #Alias de type pour les coordonnees
Dir=str#Alias de type pour la direction
Chemin=List[Dir]#Alias de type pour un chemin
Case = Tuple[bool,bool,bool,bool,str]
Laby=List[List[Case]]

ori : Coord=(0,0)
p1:Coord=(3,3)
p2:Coord=(0,2)

laby1 : Laby = [[(True,True,False,False,""),(False,False,True,False,"ENTREE")],[(True,False,False,True,""),(False,False,True,False,"SORTIE")]]

#Question1
def deplace(c:Coord,d:Dir)->Coord:
    """precondition : d=="N" or d=="S" or d=="E" or d=="O" or d==""
renvoie les coordonnes de la case dans laquelle on se trouve apres un deplacement dans la direction d depuis la case de coordonnes c"""
    x,y=c
    if d=="N" :
        return(x,y+1)
    elif d=="S":
        return(x,y-1)
    elif d=="E":
        return(x+1,y)
    elif d=="O":
        return(x-1,y)
    else:
        return c


assert deplace(ori,"N")==(0,1)
assert deplace(p1,"E")==(4,3)
assert deplace(deplace(p2,"N"),"S")==p2
assert deplace(deplace(p1,"O"),"E")==p1

#Question 2
def deplace_chemin(c:Coord,ch:Chemin)->Coord:
    """Renvoie la case dans laquelle on se trouve apres avoir suivi le chemin ch"""
    if ch==[]:#Cas d'arrêt
        return c
    else:
        return deplace_chemin(deplace(c,ch[0]),ch[1:])

assert deplace_chemin(ori,["N","N"])==p2
assert deplace_chemin(ori,["N","E","S","O"])==ori
assert deplace_chemin(ori,[])==ori

#Question 3
def deplace_possible(la:Laby, c:Coord, d:str)->bool:
    """
Teste si le deplacement deouis la case c dans la direction d est possible dans le labyrinthe la"""
    x,y=c
    if y> len(la) or x>len(la[0]) or y<0 or x<0:#permet de s'assure que x est dans le labyrinthe
        return False
    n,e,s,o,_=la[x][y]
    return (n and d=="N") or (e and d=="E") or (s and d=="S") or (o and d=="O")
assert deplace_possible(laby1,(0,1),"S")
assert not deplace_possible(laby1,(0,1),"N")
assert not deplace_possible(laby1,(0,1),"E")
assert not deplace_possible(laby1,(3,4),"N")


#Question 4
def chemin_possible(la:Laby, c:Coord, ch:Chemin)->bool:
    """Teste s'il est possible a partir de la case c de suivre le chemin ch dans le labyrinthe la"""
    if ch==[]:#cas d'arret
        return True
    else:
        return deplace_possible(la,c,ch[0]) and chemin_possible(la,deplace(c,ch[0]), ch[1:])

assert chemin_possible(laby1, (0,1), ["S","E","N"])
assert chemin_possible(laby1, (0,1), ["S","N","S","E","N"])
assert not chemin_possible(laby1, (0,1), ["S","O"])
assert not chemin_possible(laby1, (0,1), ["S","E","N","O"])

#Question 5
def est_solution(la:Laby, c:Coord, ch:Chemin)->bool:
    """ """
    x,y=c
    _,_,_,_,nat= la[x][y]
    if nat!="ENTREE" or not chemin_possible(la,c,ch):
        return False
    else:
        x1,y1=deplace_chemin(c, ch)
        _,_,_,_,nat1 = la[x1][y1]
        if nat1 != "SORTIE":
            return False
        else:
            return True
assert est_solution(laby1,(0,1),["S","E","N" ])
assert est_solution(laby1,(0,1),["S","E","O","E","N"])
assert not est_solution(laby1, (0,0), ["E","N"])
assert not est_solution(laby1,(0,1),["S","E"])
assert not est_solution(laby1, (0,1),["E"])
        
#Suggestion : Marche aleatoire
def marche_aleatoire(la:Laby, c:Coord, i:int)->List[str]:
    """recherche une solution au labyrinthe la en bougeant de maniere aleatoire"""
    t:int
    x,y=c
    possible:List[str]
    n,e,s,o,nat=la[x][y]
    if nat=="SORTIE":
        return ["Victory"]
    elif i<len(la) * len(la[0]) *2:
        possible=[]
        if n==True:
            possible.append("N")
        if e==True:
            possible.append("E")
        if s==True:
            possible.append("S")
        if o==True:
            possible.append("O")
        t=int(random.random()*len(possible))
        return [possible[t]] + marche_aleatoire(la, deplace(c, possible[t]), i+1)
    else:
        return["Perdu"]


#Suggestion : Main droite  

def marche_droite(la:Laby, c:Coord, i:int)->List[str]:
    """recherche une solution au labyrinthe la en bougeant vers la droite"""
    t:int
    x,y=c
    possible:List[str]
    n,e,s,o,nat=la[x][y]
    if nat=="SORTIE":
        return []
    elif i<len(la) * len(la[0]) *2:
        possible=[]
        if e==True:
            return ["E"] + marche_droite(la, deplace(c,"E"), i+1)
        elif s==True:
            return ["S"] + marche_droite(la, deplace(c,"S"), i+1)
        elif n==True:
            return ["N"] + marche_droite(la, deplace(c,"N"), i+1)
        else :
            return ["O"] + marche_droite(la, deplace(c,"O"), i+1)
    else:
        return["Perdu"]         
        
#Suggestion 5: Labyrinthes bien formés
def cases_ok(la:Laby)->bool:
    """precondition : les colonnes de la doivent avoir la meme longueur
teste si les colonnes du labyrinthe ont le meme nombre de cases"""
    i:int
    for i in range(len(la)):
        if len(la[0])!=len(la[i]):
            return False
    return True
def limits_ok(la:Laby)->bool:
    """Verifie si le labyrinthe est entouré de murs"""
    i:int=0
    d1:bool
    d2:bool
    d3:bool
    d4:bool
    while i<len(la[0]):
        _,_,_,d1,_=la[0][i]
        if d1:
            return False
        i=i+1
    i=0
    while i<len(la[len(la)-1]):
        _,d2,_,_,_=la[len(la)-1][i]
        if d2:
            return False
        i=i+1
    i=0
    while i < len(la):
        _,_,d3,_,_=la[i][0]
        d4,_,_,_,_=la[i][len(la)-1]
        if d3 or d4:
            return False
        i=i+1
    return True
def voisines_ok(la:Laby)->bool:
    """precondition : les colonnes du labyrinthes doivent avoir la meme taille
teste si le deplacement dans les cases est coherent (si on peut aller d'une case A a une case B dans une direction, alors on peut aller de B a A dans la direction opposee"""
    Coh:List[Tuple[Coord,Coord]]=[]
    c2:Coord
    i:int=0
    j:int=0
    n:bool
    e:bool
    s:bool
    o:bool
    var1:Tuple[Coord,Coord]
    var2:Tuple[Coord,Coord]
    var3:Tuple[Coord,Coord]
    var4:Tuple[Coord,Coord]
    is_in:bool=False
    while i<len(la):
        while j<len(la[i]):
            n,e,s,o,_=la[i][j]
             
            if n :
                c2=deplace((i,j),"N")
                for var1 in Coh:
                    if var1 == ((i,j), c2) or var1 == (c2,(i,j)):
                        is_in = True
                if is_in==False:
                    if not deplace_possible(la, deplace((i,j),"N"),"S"):
                        return False
                    else:
                        Coh.append(((i,j),c2))
            is_in=False
            if e :
                c2=deplace((i,j),"E")
                for var2 in Coh:
                    if var2 == ((i,j), c2) or var2 == (c2,(i,j)):
                        is_in = True
                if is_in==False:
                    if not deplace_possible(la,deplace((i,j),"E"),"O"):
                        return False
                    else:
                        Coh.append(((i,j),c2))           
            is_in=False
            if s :
                c2=deplace((i,j),"S")
                for var3 in Coh:
                    if var3 == ((i,j), c2) or var3 == (c2,(i,j)):
                        is_in = True
                if is_in==False:
                    if not deplace_possible(la,deplace((i,j),"S"),"N"):
                        return False
                    else:
                        Coh.append(((i,j),c2))           
            is_in=False
            if o :
                c2=deplace((i,j),"O")
                for var4 in Coh:
                    if var4 == ((i,j), c2) or var4 == (c2,(i,j)):
                        is_in = True
                if is_in==False:
                    if not deplace_possible(la,deplace((i,j),"O"),"E"):
                        return False
                    else:
                        Coh.append(((i,j),c2))          
        
            j=j+1
        i=i+1
    return True
def entree_sortie_ok(la:Laby)->bool:
    """teste si le labyrinthe a exactement une entree et une sortie"""
    c:Coord
    i:int=0
    j:int=0
    found:bool=False
    nbre_e:int=0
    nbre_s:int=0
    while i <len(la):
        while j <len(la[0]):
            _,_,_,_,f=la[i][j]
            if f=="ENTREE":
                nbre_e=nbre_e+1
            if f=="SORTIE":
                nbre_s=nbre_s+1
            j=j+1
        j=0
        i=i+1
    if nbre_e==1 and nbre_s==1:
        return True
    return False

def solu_exist(la:Laby)->bool:
    """Teste si depuis l'entree, un chemin qui mene a la sortie existe"""
    c:Coord
    i:int=0
    j:int=0
    found:bool=False
    while i<len(la) and found == False:
        while j <len(la[0]) and found == False:
            a,b,e,d,f=la[i][j]
            if f=="ENTREE":
                c=(i,j)
                found=True
            j=j+1
        j=0
        i=i+1
    
    return marche_droite(la, c,0)[-1] != "Perdu"
def laby_correct(la:Laby)->bool:
   """teste si un labyrinthe est bien formé"""
   return cases_ok(la) and limits_ok(la) and voisines_ok(la) and entree_sortie_ok(la) and solu_exist(la)

#Suggestion : Affichage
    
