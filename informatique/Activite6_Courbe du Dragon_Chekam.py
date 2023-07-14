#Suggestion : Courbe du Dragon
import math
Point = Tuple[float,float]
Seg = Tuple[Point,Point]

def segment(s:Seg)->Image:
    """Renvoie l'image du segment  s"""#peut-on mettre une precondition sur les points ici?
    p1,p2=s
    x1,y1=p1
    x2,y2=p2
    seg:Image=draw_line(x1,y1,x2,y2)
    return seg
def image_dragon(F:List[Seg])->Image:
    """Renvoie l'image obtenue en dessinant la courbe du dragon F"""
    res:Image=segment(F[0])
    i:int
    for i in range(1,len(F)):
        res=overlay(res,segment(F[i]))
    return res
def dragon_n(Cour:List[Seg])->List[Seg]:
    """Applique une fois le principe de la courbe du dragon a la courbe Cour"""
    res:List[Seg]=[]
    var:Seg
    p1:Point
    p2:Point
    A:Point
    x1:float
    y1:float
    x2:float
    y2:float
    xrot:float
    yrot:float
    i:int=0
    for var in Cour:
        p1,p2=var
        x1,y1=p1
        x2,y2=p2
        xrot=(x1-x2)/math.sqrt(2)+x2
        yrot=(y1-y2)/math.sqrt(2)+y2
        A=(x2+(xrot-x2)*math.sqrt(2)/2+(yrot-y2)*((-1)**i)*math.sqrt(2)/2,y2-(xrot-x2)*((-1)**i)*math.sqrt(2)/2+(yrot-y2)*math.sqrt(2)/2)
        res.append((p1,A))
        res.append((A,p2))
        i=i+1
    return res
def courbe_dragon(p1:Point,p2:Point,n:int)->Image:
    """renvoie la courbe du dragon a l'etape n"""
    Im_res:Image
    i:int
    list_res:List[Seg]=[(p1,p2)]
    for i in range(n):
        list_res=dragon_n(list_res)
    Im_res=image_dragon(list_res)

    return Im_res
        
show_image(courbe_dragon((-0.5,0),(0.5,0),14)) 
