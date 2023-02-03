#5-8
def DFS(graph, v, visited):
  visited[v]=True
  print(v,end=" ")
  for i in graph[v]:
    if not visited[i]:
      DFS(graph,i,visited)
      
graph = [
  [],
  [2,3,8],
  [1,7],
  [1,4,5],
  [3,5],
  [3,4],
  [7],
  [2,6,8],
  [1,7]
]

visited = [False]*9
DFS(graph,1,visited)


#5-9
from collections import deque

def BFS(graph, visited, now):
  queue = deque()
  queue.append(now)
  visited[now] = True
  while queue:
    now = queue.popleft()
    print(now, end=" ")
    for i in graph[now]:
      if not visited[i]:
        queue.append(i)
        visited[i] = True
  
graph = [
  [],
  [2,3,8],
  [1,7],
  [1,4,5],
  [3,5],
  [3,4],
  [7],
  [2,6,8],
  [1,7]
]

visited = [False]*9
BFS(graph, visited, 1)


#5-10
n,m = map(int, input().split())
world =[]
for i in range(n):
  world.append(list(map(int,input())))
result = 0

def CheckIce(world,x,y):
  if x>=0 and x<n and y>=0 and y<m:
    if world[x][y]==0:
      world[x][y] = 1
      CheckIce(world,x+1,y)
      CheckIce(world,x-1,y)
      CheckIce(world,x,y+1)
      CheckIce(world,x,y-1)
      print("1",x,y,world)
      return 1
    else:
      print("2",x,y,world)
      return 0
  else:
    print("3",x,y,world)
    return 0

for i in range(n):
  for j in range(m):
    result+=CheckIce(world,i,j)
print(result)


#5-11
from collections import deque

n,m = map(int, input().split())
world =[]
for i in range(n):
  world.append(list(map(int,input())))
go = [(-1,0),(0,1),(1,0),(0,-1)]

print("go")
queue = deque()
queue.append((0,0))
while queue:
  x,y = queue.popleft()
  for i in range(4):
    nx = x+go[i][0]
    ny = y+go[i][1]
    if nx>=0 and nx<n and ny>=0 and ny<m:
      if world[nx][ny]==1:
        queue.append((nx,ny))
        world[nx][ny]=1+world[x][y]

print(world[n-1][m-1])