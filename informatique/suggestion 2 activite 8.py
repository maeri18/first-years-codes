#Suggestion 2

#on va considere qu'une date est sous le forme AA-MM-JJ
def date_int(init:str)->Tuple[int,int,int]:
    """renvoie le triplet (jour,mois,annee)"""
    i:int=0
    while i< len(init) and init[i]!='-':
        ch=ch+init[i]
        i=i+1
    a1 = int(ch)
    i=i+1
    ch=''
    while i<len(init) and init[i]!='-':
        ch=ch+init[i]
        i=i+1
    m1=int(ch)
    i=i+1
    ch=''
    while i<len(init) and init[i]!='-':
        ch=ch+init[i]
        i=i+1
    j1=int(ch)
    return

def date_duree(init:str, fin:str)->int:
    """permet de convertir des dates en duree"""
    j1:str
    j2:str
    m1:str
    m2:str
    a1:str
    a2:str

    ch:str=''
    i:int=0
    while i< len(init) and init[i]!='-':
        ch=ch+init[i]
        i=i+1
    a1 = int(ch)
    i=i+1
    ch=''
    while i<len(init) and init[i]!='-':
        ch=ch+init[i]
        i=i+1
    m1=int(ch)
    i=i+1
    ch=''
    while i<len(init) and init[i]!='-':
        ch=ch+init[i]
        i=i+1
    j1=int(ch)
        
    
    
