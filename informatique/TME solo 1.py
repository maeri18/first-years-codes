#Question diverses
def u(n:int)->int:
    """ """
    if n==1 or n==0:
        return 1
    else:
        return u(n-1)*(u(n-2)+1) + 1

#u(10)= 214027402059183994315461155
#12
#
def sch(ch:str)->List[str]:
    """ """
    i:int
    j:int=2
    res : Set[str]=set()
    ssch:str=''
    while j < len(ch):
        for i in range(len(ch)-j):
            res.add(ch[i:i+j])
        j=j+2
    return [val for val in res]
            
            
def en_chiffre(c:str)->int:
    if c==' ':
        return 0
    else:
        return ord(c)-ord('a')+1
