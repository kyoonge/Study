import sys
from collections import deque


N,M= map(int,sys.stdin.readline().split())
g=[[]for i in range(N+1)]
maxc=0

for i in range(M):
    A,B=map(int,sys.stdin.readline().split())
    g[B].append(A)
for i in range(N+1):
    g[i].sort()


def bfs(s):
    visited = [False]*(N+1)
    count=0
    q = deque([s])
    visited[s]=True
    while q:
        now= q.popleft()
        count+=1
        for i in g[now]:
            if not visited[i]:
                q.append(i)
                visited[i]=True
        
    return [count,s]

value=[]
for i in range(1,N+1):
    value.append(bfs(i))
value.sort(key=lambda x: -x[0])

print(value[0][1],end=' ')
for i in range(1,N):
  if value[i][0]==value[0][0]:
    print(value[i][1], end=' ')
  else:
    break