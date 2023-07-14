CaseT = str
PlateauT = List[List[CaseT ]]


def plateaut_vide()->PlateauT :
    """ """
    x:PlateauT=[[" " , " " , " ",],[" " , " " , " ",],[" " , " " , " ",]]
    return x
assert plateaut_vide() == [[" " , " " , " ",],[" " , " " , " ",],[" " , " " , " ",]]
pla1 : PlateauT = plateaut_vide ()
assert pla1 [1][1] == " "
assert pla1 [0][2] == " "

def videt (p:PlateauT , i:int , j:int ) -> bool :
    """  0<=i<=2 and 0<=j<=2  """
    if p[i][j] == " ":
        return True
    else:
        return False
assert videt (pla1,0,2)== True
assert videt(pla1 , 1, 1) == True
assert videt(pla1 , 0, 2) == True


#q3:
def jouex(pla : PlateauT , i:int , j:int ) -> None :
    pla[i][j]="X"


def joueo(pla : PlateauT , i:int , j:int ) -> None :
    pla[i][j]="o"

assert videt(pla1 , 0, 2) == True
assert jouex(pla1 , 1, 1) == None
assert joueo(pla1 , 0, 2) == None
assert videt(pla1 , 0, 2) == False

#q4:
def dessine_plateaut (p:PlateauT)-> str :
    s:str="/---\\\n"
    m:str=''
    a:List[str]
    c1:str=''
    c2:str=''
    c3:str=''
    for a in p:
        c1=c1+a[2]
        c2=c2+a[1]
        
        c3=c3+a[0]
        #s=s+"|"+ c1+ c2 + c3 + "|" +"\n"
    #s=s + "\\---/"
    return s + "|"+ c1 +'|' +"\n"+'|' + c2 + '|' +"\n"+'|'+c3 + "|"+'\n'+"\\---/"

assert dessine_plateaut (pla1) ==  '/---\\\n|o  |\n| X |\n|   |\n\\---/'
print(dessine_plateaut(pla1))

def gagnet (pla: PlateauT, s:str ) -> bool :
    """ """
    a:List[str]
    i:int
    for a in pla:
        if a == [s,s,s] :
            return True
    for i in range (2) :
        if [pla[0][i],pla[1][i],pla[2][i]] == [s,s,s] :
            return True
    if pla[0][0]== s and pla[1][1]== s and pla[2][2]== s :
        return True
    if pla[0][2]== s and pla[1][1]== s and pla[2][0]== s :
        return True
        
    return False 

assert gagnet ([["O", " ", "X"], ["O", "X", " "], ["X", " ", " "]], "X") == True
assert gagnet ([["O", " ", "X"], ["O", "X", " "], ["X", " ", " "]], "O") == False
assert gagnet ([["X", " ", "O"], ["X", "O", " "], ["X", " ", " "]], "X") == True
assert gagnet ([["X", " ", "O"], ["O", "X", " "], ["X", " ", " "]], "X") == False
assert gagnet ([["O", "O", "O"], ["O", "O", "O"], ["O", "O", "O"]], "O") == True

def pleint (pla :PlateauT)-> bool:
    """ """
    for i in range (2):
        for j in range (2) :
            if videt (pla , i , j) :
                return False
    return True 
assert pleint ([["X", " ", "O"], ["O", "X", " "], ["X", " ", " "]]) == False
assert pleint ([["O", "X", "O"], ["X", "O", "X"], ["O", "X", "O"]]) == True


def tourt (pla :PlateauT , i:int , j:int )-> None :
    """ """
    a:int=0
    b:int=0
    if videt (pla,i,j ) :
        jouex(pla,i,j)
        if gagnet(pla,"X") :
            print("*** GAGNE ***")
            return None
        elif pleint(pla) :
            print("égalité")
            return None
        for i2 in range (2):
            for j2 in range(2):
                if videt (pla , i2 , j2) :
                    a=i2
                    b=j2
        joueo(pla,a,b)
        print("L’ordinateur joue en (",a, "," ,b," )")
        if gagnet(pla,"o") :
            print("*** PERDU ***")
            return None
        elif pleint(pla) :
            print("égalité")
            return None
    return None
                    

def bordure() -> Image:
    a:Image= draw_line(0.9,0.9,-0.9,0.9)
    b:Image= draw_line(0.9,0.9,0.9,-0.9)
    c:Image= draw_line(0.9,-0.9,-0.9,-0.9)
    d:Image= draw_line(-0.9,0.9,-0.9,-0.9)
    return overlay(a,b,c,d)


#show_image(bordure())

def traits () -> Image:
    a:Image= draw_line(0.3,0.9,0.3,-0.9)
    b:Image= draw_line(-0.3,0.9,-0.3,-0.9)
    c:Image= draw_line(-0.9,0.3,0.9,0.3)
    d:Image= draw_line(-0.9,-0.3,0.9,-0.3)
    return overlay(a,b,c,d)

show_image(overlay(bordure(),traits()))



