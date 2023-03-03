from collections import deque

def solution(rectangle, characterX, characterY, itemX, itemY):
    answer = 0
    field = [[0 for i in range(102)] for j in range(102)]
    for r in rectangle:
        for i in range(r[0]*2,r[2]*2+1):
            for j in range(r[1]*2,r[3]*2+1):
                if i==r[0]*2 or i==r[2]*2 or j==r[1]*2 or j==r[3]*2:
                    if field[i][j]!=-1:
                        field[i][j]=1
                else: 
                    field[i][j]=-1
    
    dx=[1,-1,0,0]
    dy=[0,0,1,-1]
    q=deque()
    q.append((2*characterX,2*characterY))
    visited = [[0 for i in range(102)] for j in range(102)]
    visited[2*characterX][2*characterY]=1
    while q:
        x,y=q.popleft()
        if x==itemX*2 and y==itemY*2:
            answer= field[x][y]//2
            break
        for i in range(4):
            nx = x+dx[i]
            ny = y+dy[i]
            if field[nx][ny]==1 and visited[nx][ny]==0:
                visited[nx][ny]=1
                field[nx][ny]= field[x][y]+1
                q.append((nx,ny))
    
    return answer