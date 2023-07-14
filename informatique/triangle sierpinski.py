Point = Tuple[float,float]
Triangle=Tuple[Point,Point,Point]
L1:List[Triangle]=[((0.2,0.3),(0.5,0.4),(0.5,0.6)),((0.4,0.7),(0.2,1),(0,0))]
def triangle_remplis(L:List[Triangle])->Image:
    """dessine les triangles de la liste L"""
    i:int
    p1:Point
    p2:Point
    p3:Point
    x1:float
    y1:float
    x2:float
    y2:float
    x3:float
    y3:float
    p1,p2,p3=L[0]
    x1,y1=p1
    x2,y2=p2
    x3,y3=p3
    q1:Point
    q2:Point
    q3:Point
    a1:float
    b1:float
    a2:float
    b2:float
    a3:float
    b3:float
    Im:Image=fill_triangle(x1,y1,x2,y2,x3,y3)
    for i in range(1,len(L)):
        q1,q2,q3=L[i]
        a1,b1=q1
        a2,b2=q2
        a3,b3=q3
        Im=overlay(Im,fill_triangle(a1,b1,a2,b2,a3,a3))
    return Im
#def triangle_sierpinski(p:Point,d:float,n:int)->Image:
 #   """dessine un flocon de Koch"""
  #  x,y=p
   # TR:image=draw_triangle(x,y+r,x+(math.sqrt(3)/3)*d,y-(1/2)*d,x-(math.sqrt(3)/3)*d,y-(1/2)*d)
    #L:Courbe=[(x,y+r),(x+(math.sqrt(3)/3)*d,y-(1/2)*d),(x-(math.sqrt(3)/3)*d,y-(1/2)*d)]
show_image(L1)
