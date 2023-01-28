from collections import deque

#DFS
def DFS(visited, now):
  visited[now]=True
  print(now,end=" ")
  for i in graph[now]:
    if not visited[i]:
      DFS(visited, i)
   
#BFS
def BFS(graph, visited, now):
  visited[now]=True
  queue = deque([now])
  while queue:
    now = queue.popleft()
    print(now,end= " ")
    for i in graph[now]:
      if not visited[i]:
        queue.append(i)
        visited[i] = True


    
    

#그래프 리스트
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

#방문정보 리스트
visited = [False]*9
#함수 호출
DFS(visited, 1)
BFS(graph, visited, 1)