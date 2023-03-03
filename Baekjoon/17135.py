import sys
import itertools
from collections import deque

field=[]
N,M,D = map(int, sys.stdin.readline().split())
for i in range(N):
    field.append(list(map(int,sys.stdin.readline().split())))
#field=[[1, 1, 1, 1, 1],[1, 1, 1, 1, 1],[1, 1, 1, 1, 1],[1, 1, 1, 1, 1],[1, 1, 1, 1, 1]]
dx = [0,-1,0]
dy = [-1,0,1]

def bfs(archor):
    tmpfield = [arr[:] for arr in field]
    killcount = 0
    
    for i in range(N-1,-1,-1):#한 턴
        killlist=[]
        for a in archor:#궁수 마다 죽일 적 탐색
            q = deque([(i,a,1)])#궁수 바로 위 지점부터 시작
            while q:
                #print(a,q)
                r,c,d= q.popleft()
                #print(r,c,d)
                if tmpfield[r][c]==1:
                    if (r,c) not in killlist:
                        killlist.append((r,c))
                        killcount+=1
                    break
                #방향, 거리에 따라 탐색
                if d<D:
                    for j in range(3):
                        nr = r+dx[j]
                        nc = c+dy[j]
                        if 0<=nr<N and 0<=nc<M :
                          if (nr,nc,d+1) not in q:
                            q.append((nr,nc,d+1))
          
        #궁수들 다 탐색했으면 적 죽이기
        for j in killlist:
            tmpfield[j[0]][j[1]]=0
      
    return killcount

items = [ i for i in range(M)]
alist = itertools.combinations(items,3)
result = 0
for archor in alist:
    result = max(bfs(archor), result)
print(result)