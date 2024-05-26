def solution(n, computers):
    answer = 0
    info=[[] for i in range(n)]
    visited = [False]*n
    sum=0
    for i in range(n):
        for j in range(n):
            if j!=i and computers[i][j]:
                info[i].append(j) 
    for i in range(n):
        sum+=visit(i,True,info,visited)

    return sum

def visit(index,isfirst, info, visited):
    if not visited[index]:
        visited[index]=True
        for i in info[index]:
            visit(i,False,info,visited)
        if isfirst:
            return 1
    else:
        return 0
            
 