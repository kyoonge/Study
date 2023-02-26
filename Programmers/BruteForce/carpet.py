def solution(brown, yellow):
    crlist =[]
    sumcr = brown//2+2
    mulcr = brown+yellow
    
    for i in range(1,sumcr):
        if mulcr == i*(sumcr-i):
            crlist.append(i)
            crlist.append(sumcr-i)
            break
    print(crlist)
    return sorted(crlist,reverse=True)