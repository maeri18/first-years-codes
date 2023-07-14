#Partie Guidee
CaseT = str
# Les elements de CaseT sont soit " " soit "O" soit "X"
PlateauT = List[List[CaseT]]
# Les elements de PlateauT sont des matrices 3x3


#Question 1
def plateau_vide()->PlateauT:
    """renvoie un plateau vide"""
    Pla:PlateauT=[]
    i:int
    j:int
    for i in range(3):
        Pla.append([])
        for j in range(3):
            Pla[i].append(" ")
    return Pla
pla1: PlateauT = plateau_vide()
assert plateau_vide()== [[' ', ' ', ' '], [' ', ' ', ' '], [' ', ' ', ' ']]
assert pla1[1][1]==" "
assert pla1[0][2]==" "

#Question 2
def videt(pla:PlateauT, i:int, j:int)->bool:
    """precondition: 0<=i<=2 and 0<=j<=2
teste si la case de coordonnees i j du plateau pla est vide"""
    return pla[i][j]==" "

assert videt(pla1, 1,1) == True
assert videt(pla1,0,2)==True

#Question 3
def jouex(pla:PlateauT, i:int, j:int)->None:
    """***Procédure***
    precondition : 0<=i<=2 and 0<=j<=2
    Inscrit un "X" dans la case de coordonnees (i,j) de pla"""
    pla[i][j]="X"
    
def joueo(pla:PlateauT, i:int, j:int)->None:
    """***Procédure***
    precondition : 0<=i<=2 and 0<=j<=2
    Inscrit un "O" dans la case de coordonnees (i,j) de pla"""
    pla[i][j]="O"

assert videt(pla1,1,0)==True
assert videt(pla1,2,0)==True
assert jouex(pla1,1,1)==None
assert joueo(pla1,0,2)==None
assert videt(pla1,1,1)==False
assert videt(pla1,0,2)==False
#Question 4
def dessine_plateaut(pla:PlateauT)->str:
    """***Procedure***"""
    c1:str=''
    c2:str=''
    c3:str=''
    res:str=''
    res=res+'/---\\\n'
    i:List[str]
    for i in pla:
        c1=c1+i[-1]
        c2=c2+i[-2]
        c3=c3+i[-3]
    res=res +'|' + c1 + '|\n' + '|' + c2 + '|\n' + '|' + c3 + '|\n' +'\\---/'
    
    return res
#assert dessine_plateaut(pla1) == "0 \n X \n   \n"   
#assert dessine_plateaut(pla1)=='0  \n X  \n   \n'    
print(dessine_plateaut(pla1))




#Question 5
def gagnet(pla:PlateauT, c:str)->bool:
    """Teste si le plateau pla est plein"""
    c_li:List[str]
    c_co1:str=''
    c_co2:str=''
    c_co3:str=''
    c_di1:str=''
    c_di2:str=''
    win : bool=False
    i:int=0
    prec:str=pla[0][0]
    for c_li in pla:
        if (c_li[0]==c_li[1] and c_li[1]==c_li[2] and c_li[0]==c): 
            return True
        c_co1= c_co1 + c_li[-1]
        c_co2 = c_co2 + c_li[-2]
        c_co3 = c_co3 + c_li[-3]
        c_di1 = c_di1 + c_li[i]
        c_di2 = c_di2 + c_li[2-i]
        i=i+1
    if c=="X": 
        return c_co1 =="XXX" or c_co2 =="XXX" or c_co3 =="XXX" or c_di1 == "XXX" or c_di2 == "XXX"
    elif c=="O":
        return c_co1 =="OOO" or c_co2 =="OOO" or c_co3 =="OOO" or c_di1 == "OOO" or c_di2 == "OOO"

assert gagnet([["O"," ","X"],["O","X"," "],["X"," ", " "]],"X")==True

#Question 6
def pleint(pla:PlateauT)->bool:
    i:str
    c:List[str]
    for c in pla:
        for i in c:
            if i==" ":
                return False

    return True

assert pleint([["O"," ","X"],["O","X"," "],["X"," ", " "]])==False
assert pleint([["O","X","X"],["O","X","O"],["X","O", "X"]])==True

#Question 7

def tourt(pla:PlateauT, i:int, j:int)->None:
    """***Procedure***"""
    if videt(pla,i,j):
        jouex(pla,i,j)
        if gagnet(pla,"X") and gagnet(pla,"O"):
            print("egalite")
            return None
        elif gagnet(pla,"X") and not gagnet(pla,"O"):
            print("L'ordinateur gagne")
        else:
            i:int
            j:int
            for i in range(3):
                for j in range(3):
                    if videt(pla,i,j):
                     
            
                
            






            
            
    
            
            
            
            
            
        
