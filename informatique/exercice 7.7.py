#exercice 7.6
#Question 1
def intersection_2_listes(l1:List[int],l2:List[int])->List[int]:
    """renvoie l'intersectin de l1 et l2, deux listes classes par ordre croissant"""
    i:int=0
    j:int
    l:List[int]=l1[:]
    lres:List[int]=[]
    if l1==[] or l2==[] or l1[-1]<l2[0] or l1[0]>l2[-1]:
        return []
    else:
        while l2[i]<l1[0]:
            i=i+1
        while i<len(l2):
            j=0
            while j <len(l) and l2[i]!=l[j]:
                j=j+1
            if j<len(l) and l2[i]==l[j]:
                lres.append(l[j])
                l=l[j+1:]
            i=i+1
        return lres
assert intersection_2_listes([0,1,2],[3,4,5])==[]
assert intersection_2_listes([1,2,3],[1,2,3])==[1,2,3]
assert intersection_2_listes([1,1],[1,1])==[1,1]  
assert intersection_2_listes([1,1],[1,2])==[1]                    
assert intersection_2_listes([],[1,2,3])==[]
assert intersection_2_listes([1,2,2,3,4],[2,3,4,4,5,6])==[2,3,4]

#Question 2
def intersection(l:List[List[int]])->List[int]:
    """renvoie l'intersection des listes de l"""
    if l==[]:
        return []
    else:
        lres : List[int] = l[0]
        i:int
        for i in range(1,len(l)):
            lres = intersection_2_listes(lres,l[i])
        return lres
assert intersection([[1,2,3,4,4,5],[2,5,7],[0,2,2,4,4,5,9]])==[2,5]
assert intersection([[1,2,3,4,4,5],[2,4,4,5,7],[0,2,2,4,4,5,9,]])==[2,4,4,5]
