import math
#Suggestion: Flocon de Koch
Point = Tuple[float,float]
Seg = Tuple[Point,Point]
Flocon = List[Seg]
def segment(s:Seg)->Image:
    """Renvoie l'image du segment  s"""#peut-on mettre une precondition sur les points ici?
    p1,p2=s
    x1,y1=p1
    x2,y2=p2
    seg:Image=draw_line(x1,y1,x2,y2)
    return seg
def image_flocon(F:List[Seg])->Image:
    """Renvoie l'image obtenue en dessinant le flocon F"""
    res:Image=segment(F[0])
    i:int
    for i in range(1,len(F)):
        res=overlay(res,segment(F[i]))
    return res
def triangle_initial(p:Point,r:float)->List[Seg]:
    """renvoie le triangle de centre p et de rayon r"""
    x,y=p
    res:List[Seg]=[((x,y+r),(x+r*math.sqrt(3)/2,y-r*1/2)),((x+r*math.sqrt(3)/2,y-r*1/2),(x-r*math.sqrt(3)/2,y-r*1/2)),((x-r*math.sqrt(3)/2,y-r*1/2),(x,y+r))]
    return res
def flocon_n(tri:List[Seg])->List[Seg]:
    """renvoie la liste de segments d'un flocon de Koch a l'etape n"""
    var : Seg
    p1:Point
    p2:Point
    x1:float
    y1:float
    x2:float
    y2:float
    p3:Point
    A1:Point
    A2:Point
    a1:float
    b1:float
    a2:float
    b2:float
    ray:float
    res:List[Seg]=[]
    for var in tri:
        p1,p2=var
        x1,y1=p1
        x2,y2=p2
        A1=(x2*1/3+x1*2/3,y2*1/3+y1*2/3)
        A2=(x2*2/3+x1*1/3,y2*2/3+y1*1/3)
        a1,b1=A1
        a2,b2=A2
        ray=math.sqrt((a2-a1)**2+(b2-b1)**2)
        p3=((a1-a2)*1/2+(b1-b2)*math.sqrt(3)/2+a2,-(a1-a2)*math.sqrt(3)/2+(b1-b2)*1/2+b2)
        res.append((p1,A1))
        res.append((A2,p2))
        res.append((A1,p3))
        res.append((p3,A2))
    return res

def courbe_flocon(p:Point,n:int,r:float)->Image:
    """renvoie l'image correspondant a un flocon de Koch"""
    Im_res:Image
    i:int
    list_res:List[Seg]=triangle_initial(p,r)
    for i in range(n):
        list_res=flocon_n(list_res)
    Im_res=image_flocon(list_res)

    return Im_res
        
show_image(courbe_flocon((0,0),6,0.8))   
    
    
