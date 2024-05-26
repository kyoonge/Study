from collections import deque
import sys


N,M,V=map(int,sys.stdin.readline().split())
g=[[] for i in range(N+1)]
dvisited = [False]*(N+1)

for i in range(M):
    A,B=map(int,sys.stdin.readline().split())
    if B not in g[A]:
        g[A].append(B)
    if A not in g[B]:
        g[B].append(A)

for i in range(1,N+1):
    g[i].sort()


def dfs(s):
    dvisited[s]=True
    print(s,end=' ')
    for i in g[s]:
        if dvisited[i]:
            continue
        elif g[s]:
            dfs(i)
    return


def bfs(s):
    q = deque([s])
    dvisited = [False]*(N+1)
    dvisited[s]=True
    while q:
        now = q.popleft()
        print(now,end=' ')
        for i in g[now]:
            if dvisited[i]:
                continue
            elif g[s]:
                q.append(i)
                dvisited[i]=True 
    return

dfs(V)
print()
bfs(V)