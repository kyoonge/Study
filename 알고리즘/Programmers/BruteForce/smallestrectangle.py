def solution(sizes):
    maxw,maxh = 0,0
    answer = 0
    for i in sizes:
        if i[0]<i[1]:
            i[0],i[1] = i[1],i[0]
        maxw = max(i[0],maxw)
        maxh = max(i[1],maxh)
    
    
    
    
    
    return maxw*maxh