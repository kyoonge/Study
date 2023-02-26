from collections import deque

def solution(maps):
    n = len(maps)
    m = len(maps[0])
    #print(n,m)
    dr = [-1,0,1,0]
    dc = [0,-1,0,1]
    q = deque([(0,0)])
    value = 1

    while q:
        r,c = q.popleft()
        if r==n-1 and c==m-1:
            #print(0)
            break
        for i in range(4):
            nr = r + dr[i]
            nc = c + dc[i]
            if nr>=0 and nr<n and nc>=0 and nc<m:
                #print(1,nr,nc)
                if maps[nr][nc]==0:
                    #print('zero',nr,nc,maps[nr][nc],maps[r][c]+1)
                    continue
                elif maps[nr][nc]==1:
                    #print('go1',nr,nc,maps[r][c]+1)
                    q.append((nr,nc))
                    maps[nr][nc]=maps[r][c]+1
                elif maps[nr][nc]>maps[r][c]+1:
                    #print('go1',nr,nc,maps[r][c]+1)
                    q.append((nr,nc))
                    maps[nr][nc]=maps[r][c]+1
                    
    #print(maps)
    if maps[n-1][m-1]==1:
        answer=-1
    else:
        answer=maps[n-1][m-1]
   
    return answer