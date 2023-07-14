
def existence_trajet(carte:Dict[str,Set[str]], depart:str,arrivee:str)->bool:
    """ teste s'il existe un trajet entre depart et arivee dans carte"""
    if carte == dict() or depart not in carte:
        return False
    else:
        d:Dict[int,Set[str]]=dict()
        d[0]={depart}
        vues=Set[str]=set()
        i:int=0
        station:str
        setres:Set[str]=set()
        while arrivee not in setres and:
            
            for station in d[i]:
                if i+1 not in d:
                    d[i+1]=set() | carte[station]
                else:
                    d[i+1]=d[i+1] | carte[station]
            setres=setres | d[i+1]
            i=i+1
            
        
        return setres
