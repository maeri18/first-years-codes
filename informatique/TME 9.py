#exercice1:
def melements_list (l:List[T]) -> Set[T] :
    ''' '''
    return  { a for a in l }
assert melements_list(['a', 'a', 'b', 'b', 'b', 'b', 'c', 'c', 'c']) == {'a', 'b', 'c'}

def melements_dict (dico:Dict [T, int])-> Set [T] :
    ''' '''
    return {a for a in dico}
assert melements_dict({'a':2, 'b':4, 'c':3}) == {'a', 'b', 'c'}

#question 2:
def mdict_de_mlist (l:List[T]) ->Dict [T, int]:
    """ """
    a:T
    dico: Dict [T, int] = dict()
    for a in l :
        if a in dico :
            dico [a] = dico [a] +1
        else :
            dico [a] = 1
    return dico

assert mdict_de_mlist(['a', 'b', 'c', 'c', 'a', 'b', 'c', 'b', 'b' ])=={'b': 4, 'c': 3, 'a': 2}




# question 3:
def  mlist_de_mdict (dico:Dict [T, int])-> List [T] :
    cle:T
    l:List[T]=[]
    i: int
    for cle in dico :
        for i in range (dico[cle]):
            l.append(cle)

    return l
assert mlist_de_mdict ({'b': 4, 'c': 3, 'a': 2})==['b', 'b', 'b', 'b', 'c', 'c', 'c', 'a', 'a' ]


def mlist_de_mdict2 (dico:Dict [T, int])-> List [T] :
    return [a  for (a,b) in dico.items() for j in range (b) ]

assert mlist_de_mdict2 ({'b': 4, 'c': 3, 'a': 2})==['b', 'b', 'b', 'b', 'c', 'c', 'c', 'a', 'a' ]





#question 4:
def minter_dict (m1:Dict [T, int] , m2:Dict [T, int] ) -> Dict [T, int] :
    """ """
    d:Dict [T, int] = dict()
    
    for cle1 in m1:
        if cle1 in m2 :
            d[cle1] = min(m1[cle1],m2[cle1])
    return d
            
assert minter_dict({'a':2, 'b':4, 'c':3}, dict()) == {}
assert minter_dict({'a':2, 'b':4, 'c':3},{'f':1, 'a':1, 'b':3}) == {'b': 3, 'a': 1}

#question 5:

def minter_list ( l1:List[T] , l2:List[T] ) -> List[T] :
    """ """
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

assert minter_list(['a', 'a', 'b', 'b', 'b', 'b', 'c', 'c', 'c'],['f', 'a', 'b', 'b', 'b'])== ['a', 'b', 'b', 'b']


def minter_list_ ( l1:List[T] , l2:List[T] ) -> List[T] :
    """ """
    l1d:Dict [T, int] =mdict_de_mlist (l1)
    l2d:Dict [T, int] =mdict_de_mlist (l2)
    return mlist_de_mdict(minter_dict(l1d,l2d))
    
assert minter_list_(['a', 'a', 'b', 'b', 'b', 'b', 'c', 'c', 'c'],['f', 'a', 'b', 'b', 'b'])== ['a', 'b', 'b', 'b']

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

        
        
