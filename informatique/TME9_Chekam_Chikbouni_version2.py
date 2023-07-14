#Exercice 10.4

#Question 1

def melements_list(L:List[T])->Set[T]:
    """precondition: T doit etre hashable """
    return {a for a in L}

def melements_dict(dico:Dict[T,int])->Set[T]:
    """ precondition : T doit etre hashable"""
    return {a for a in dico}

#Jeu de tests
assert melements_list(['a','a','b','b','b','c','c','c'])=={'a','b','c'}
assert melements_list(['a','b','c','c','a','b','c','b','b'])=={'a','b','c'}
assert melements_dict({'a':2,'b':4,'c':3})=={'a','b','c'}
assert melements_list([])==set()
assert melements_dict(dict())==set()

#Question 2
def mdict_de_mlist(l:List[T])->Dict[T,int]:
    """precondition: T doit etre hashable"""
    c:T #variable d'iteration
    dico:Dict[T,int]=dict() #dictionnaire resultat
    for c in l:
        if c in dico:
            dico[c]=dico[c]+1
        else:
            dico[c]=1
    return dico

#Jeu de tests
assert mdict_de_mlist(['a','a','b','b','b','b','c','c','c'])=={'b':4,'c':3,'a':2}
assert mdict_de_mlist(['a','b','a','b','b','b'])=={'b':4,'a':2}
assert mdict_de_mlist(['a'])=={'a':1}
assert mdict_de_mlist([])==dict()

#Ce n'est pas possible de construire cette fonction par comprehension car on ne peut pas incrementer les valeurs d'un dictionnaire(compter les occurences) en ne passant que par comprehension

#Question 3
#      ****************version sans comprehension********************
def mlist_de_mdict(dico:Dict[T,int])->List[T]:
    """ precondition: T doit etre une type hashable
    renvoie la representation d'un multi-ensemble sous forme de liste a partir de sa representation sous forme de dictionnaire """
    c:T #Variqble d'iteration sur les cles du dictionnaire
    i:int
    lres:List[T]=[] #Liste resultat
    for c in dico:
        for i in range(0,dico[c]):
            lres.append(c)
    return lres

#Jeu de tests
assert mlist_de_mdict({'b':4,'c':3,'a':2})==['b','b','b','b','c','c','c','a','a']
assert mlist_de_mdict({'b':4,'a':2})==['b','b','b','b','a','a']
assert mlist_de_mdict(dict())==[]

#  ***********************version avec comprehension************************
def mlist_de_mdict_comprehen(dico:Dict[T,int])->List[T]:
    """precondition: T doit etre une type hashable
"""
    return [a for a in dico
                for i in range(dico[a])]

#Jeu de tests
assert mlist_de_mdict_comprehen({'b':4,'c':3,'a':2})==['b','b','b','b','c','c','c','a','a']
assert mlist_de_mdict_comprehen({'b':4,'a':2})==['b','b','b','b','a','a']
assert mlist_de_mdict_comprehen(dict())==[]

#Question 4

def minter_dict(m1:Dict[T,int], m2:Dict[T,int])->Dict[T,int]:
    """ precondition : T doit etre un type hashable"""
    res:Dict[T,int]=dict() #variable resultat
    a:T #variable d'iteration
    for a in m1:
        if a in m2:
            res[a]=min(m1[a],m2[a])
    return res

#Jeu de tests
assert minter_dict({'a':2,'b':4,'c':3},{'f':1,'a':1,'b':3})=={'b':3,'a':1}
assert minter_dict(dict(),dict())==dict()
assert minter_dict(dict(),{'f':1,'a':1,'b':3})==dict()
assert minter_dict({'a':2,'d':3},{'s':4,'t':3,'o':1})==dict()
assert minter_dict({'a':2,'b':4,'c':3},dict())==dict()

#Question 5

def minter_list ( l1:List[T] , l2:List[T] ) -> List[T] :
    """realise l'intersection de multi-ensembles" """
    s:Set[T] =set()
    lres:List[T] =[]
    a :T
    b:T
    for a in l1 :
        s.add(a)
    for b in l2 :
        if b in s:
            lres.append (b)
    return lres

#Jeu de tests
assert minter_list(['a', 'a', 'b', 'b', 'b', 'b', 'c', 'c', 'c'],['f', 'a', 'b', 'b', 'b'])== ['a', 'b', 'b', 'b']
assert minter_list([],['a', 'b', 'b', 'b'])==[]
assert minter_list([],[])==[]
assert minter_list(['a', 'a', 'b', 'b', 'b', 'b', 'c', 'c', 'c'],[])==[]
assert minter_list(['a', 'b', 'b', 'c'],['a', 'b', 'b', 'c'])==['a', 'b', 'b', 'c']


# En utilisant les fonctions precedentes

def minter_list_(l1:List[T],l2:List[T])->List[T]:
    """ realise l'intersection de multi-ensembles"""
    d1:Dict[T,int]=mdict_de_mlist(l1)
    d2:Dict[T,int]=mdict_de_mlist(l2)
    return mlist_de_mdict(minter_dict(d1,d2))

#Jeu de test
assert minter_list_(['a','a','b','b','b','b','c','c','c'],['f','a','b','b','b'])==['a','b','b','b']

#Question 6

def munion_list(l1:List[T],l2:List[T])->List[T]:
    """ realise l'union de multi ensembles"""
    return l1+l2

#Jeu de tests
assert munion_list(['a','a','b','b','b','b','c','c','c'],['f','a','b','b','b'])==['a','a','b','b','b','b','c','c','c','f','a','b','b','b']
assert munion_list([],['a','a','b','b','b','b','c','c','c'])==['a','a','b','b','b','b','c','c','c']
assert munion_list(['a','a','b','b','b','b','c','c','c'],[])==['a','a','b','b','b','b','c','c','c']
assert munion_list([],[])==[]

def munion_dict(d1:Dict[T,int],d2:Dict[T,int])->Dict[T,int]:
    """ precondition: T doit etre un type hashable"""
    l1:List[T] = mlist_de_mdict(d1)
    l2:List[T] = mlist_de_mdict(d2)
    return mdict_de_mlist(munion_list(l1,l2))

#Jeu de tests
assert munion_dict({'a':3,'b':2},{'w':4,'a':1})=={'a':4,'b':2,'w':4}
assert munion_dict(dict(),{'w':4,'a':1})=={'w':4,'a':1}
assert munion_dict(dict(),dict())==dict()
assert munion_dict({'a':3,'b':2},{'r':2,'t':5,'e':7})=={'a':3,'b':2,'r':2,'t':5,'e':7}

#on peut en effet ecrire la fonction sous forme de comprehension, en faisant par exemple:
 # {cle:d1[cle]+d2[cle] for cle in d1 if cle in d2}+{cle1:d1[cle] for cle1 in d1 if cle1 not in d2} + {cle2:d2[cle] for cle2 in d2 if cle2 not in d1}



#Exercice 10.5

Cart:Dict[str,Set[str]]
Grandes_Lignes : Dict[str, Set[str]]
Grandes_Lignes = {'Paris': {'Strasbourg', 'Dijon', 'Toulouse',
'Lille', 'Lyon', 'Bordeaux'},
'Strasbourg':{'Paris', 'Dijon', 'München'},
'München': {'Strasbourg'},
'Dijon': {'Paris', 'Strasbourg', 'Lyon', 'Toulouse'},
'Lyon':{'Paris', 'Dijon', 'Toulouse'},
'Toulouse': {'Paris', 'Lyon', 'Dijon', 'Bordeaux'},
'Bordeaux': {'Nantes', 'Paris'},
'Nantes': {'Paris', 'Bordeaux','Quimper'},
'Quimper':{'Nantes'}, 'Ajaccio': {'Bastia'},
'Bastia': {'Ajaccio'}, 'Lille': {'Paris'}}

#Question 1
def trajet_direct(carte:Dict[str,Set[str]],st1:str,st2:str)->bool:
    """teste si il existe un trajet direct entre les stations st1 et st2 """
    if st1 in carte and st2 in carte[st1]:
        return True        
    else:
        return False
    
#Jeu de tests
    
assert trajet_direct(Grandes_Lignes, 'Paris','Bordeaux')==True
assert trajet_direct(Grandes_Lignes, 'Paris','Ajaccio')==False
assert trajet_direct(Grandes_Lignes, 'Limoges','Marseille')==False

#Question 2

def ajout_station(station:str, correspondances:Set[str], carte:Dict[str,Set[str]])->Dict[str,Set[str]]:
    """ ajoute une station dans la carte"""
    
    carte1:Dict[str,Set[str]]={cle:{val for val in carte[cle]} for cle in carte}
    
    if station not in carte1:
        carte1[station]=correspondances
        c:str
        for c in correspondances:
            
            if c in carte1:
                carte1[c].add(station)
            else:
                carte1[c]={station}
    return carte1

Nouvelles_Lignes:Dict[str,Set[str]]
Nouvelles_Lignes=ajout_station('Limoges',{'Paris','Toulouse','Bordeaux'},Grandes_Lignes)

#Jeu de tests
assert trajet_direct(Nouvelles_Lignes,'Limoges','Paris')==True

assert ajout_station('Limoges',{'Paris','Toulouse','Bordeaux'},Grandes_Lignes)=={'Paris': {'Strasbourg', 'Dijon', 'Toulouse','Lille', 'Lyon', 'Bordeaux','Limoges'},'Strasbourg':{'Paris', 'Dijon', 'München'},'München': {'Strasbourg'},'Dijon': {'Paris', 'Strasbourg', 'Lyon', 'Toulouse'},'Lyon':{'Paris', 'Dijon', 'Toulouse'},'Toulouse': {'Paris', 'Lyon', 'Dijon', 'Bordeaux','Limoges'},'Bordeaux': {'Nantes', 'Paris','Limoges'},'Nantes': {'Paris', 'Bordeaux','Quimper'},'Quimper':{'Nantes'}, 'Ajaccio': {'Bastia'},'Bastia': {'Ajaccio'}, 'Lille': {'Paris'},'Limoges':  {'Paris','Toulouse','Bordeaux'}}

#Question 3
def stations_atteignables(carte:Dict[str,Set[str]],depart:str, k:int)->Set[str]:
    """precondition: k>=0"""
    d:Dict[int,Set[str]]=dict()
    if depart not in carte:
        return set()
    elif k==0:
        return{depart}
    else:
        d[0]={depart}
        i:int=0
        station:str
        setres:Set[str]=set()
        while i<k:
            
            for station in d[i]:
                if i+1 not in d:
                    d[i+1]=set() | carte[station]
                else:
                    d[i+1]=d[i+1] | carte[station]
            setres=setres | d[i+1]
            i=i+1
            
        
        return setres
    
#Jeu de tests    
assert stations_atteignables(Grandes_Lignes,'Paris',0)=={'Paris'}
assert stations_atteignables(Grandes_Lignes,'Paris',1)=={'Strasbourg', 'Dijon', 'Toulouse', 'Lyon', 'Bordeaux', 'Lille'} #Should i really remove paris here?
assert stations_atteignables(Grandes_Lignes,'Paris',2)=={'Strasbourg', 'Paris', 'München', 'Dijon', 'Toulouse', 'Lyon', 'Bordeaux', 'Lille', 'Nantes'}


#Question 4
def compteur_changement(carte:Dict[str,Set[str]], depart:str,arrivee:str)->int:
    """precondition: carte !=dict()
precondition: Il existe une correspondance entre les stations 'depart' et 'arrivee' dans 'carte' """
    i:int=0
    if depart not in carte:
        return -1
    else:
        atteignables : Set[str]=set()
        while arrivee not in atteignables:
            atteignables = stations_atteignables(carte,depart,i)
            i=i+1
        return i-1

#Jeu de tests
assert compteur_changement(Grandes_Lignes,'Paris','Paris')==0
assert compteur_changement(Grandes_Lignes,'Paris','Dijon')==1
assert compteur_changement(Grandes_Lignes,'Paris','Quimper')==3

#Question 5
def existence_trajet(carte:Dict[str,Set[str]],depart:str,arrivee:str)->bool:
    """ """
    prec:Set[str]=set()
    atteign:Set[str]={depart}
    i:int=1
    while prec != atteign: #permet de s'arreter lorsqu'on ne rencontre pas de nouvelle station
        if arrivee in atteign:
            return True
        else:
            prec = prec | atteign
            atteign = atteign | stations_atteignables(carte, depart, i)
            i=i+1
    return False
        
assert existence_trajet(Grandes_Lignes, 'Paris','München')==True
assert existence_trajet(Grandes_Lignes, 'Ajaccio','Bordeaux')==False


        
