import math
#partie guidee:Courbes
Point = Tuple[float,float]
Courbe=List[Point]
O:Point=(0.0,0.0)
tri1:Courbe=[O,(0.0,0.3),(0.4,0.0),O]
#Question 1
def longueur(C:Courbe)->float:
    """Calcule la longueur d'une courbe"""
    i:int
    x1:float
    y1:float
    x2:float
    y2:float
    somme:float=0
    for i in range(len(C)-1):
        x1,y1=C[i]
        x2,y2=C[i+1]
        somme = somme+math.sqrt((x2-x1)**2+(y2-y1)**2)
    return somme
assert abs((longueur(tri1)-1.2))<10**-12
assert longueur([])==0

#question 2
def segment(p1:Point,p2:Point)->Image:
    """Renvoie l'image du egment reliant p1 et p2"""#peut-on mettre une precondition sur les points ici?
    x1,y1=p1
    x2,y2=p2
    seg:Image=draw_line(x1,y1,x2,y2)
    return seg

show_image(segment((0.5,0.5),(0.0,0.0)))

#question 3
def image_courbe(C:Courbe)->Image:
    """Renvoie l'image obtenue en dessinant la courbe C"""
    Cour:Image=segment(C[0],C[1])
    i:int
    inter:Image
    for i in range(1,len(C)-1):
        inter=segment(C[i],C[i+1])
        Cour=overlay(Cour,inter)
    return Cour
show_image(image_courbe(tri1))

#question 4
def deplace(p:Point, direction:str,di:float)->Point:
    """precondition: direction == "H" or direction == "B" or direction == "G" or direction == "D"
precondition:di>=0
renvoie le point obtenu en deplacant le point dans la direction d de la distance di"""
    x,y=p
    if direction=='H':
        y=y+di
    elif direction=='B':
        y=y-di
    elif direction=='G':
        x=x-di
    else :
        x=x+di
    return (x,y)
assert deplace(O,"G",1)==(-1.0,0.0)
assert deplace(O,"H",0.5)==(0.0,0.5)
assert deplace(O,"D",1)==(1.0,0.0)
assert deplace(O,"B",0.5)==(0.0,-0.5)
show_image(segment(O,deplace(O,"H",0.3)))
#question 5
def spirale(ori:Point,dec:float,n:int)->Image:
    """renvoie une spirale d'origine ori"""
    i:int
    cour:Courbe=[ori]
    p:Point=ori
    
    for i in range(0,n-1):
        if i%2==1:
            p=deplace(p,"H",(i)*dec)
            cour.append(p)
            p=deplace(p,"G",(i)*dec)
            cour.append(p)
        else:
            p=deplace(p,"B",(i)*dec)
            cour.append(p)
            p=deplace(p,"D",(i)*dec)
            cour.append(p)
        
    return image_courbe(cour)
        
show_image(spirale(O,0.01,400))       


    
        
