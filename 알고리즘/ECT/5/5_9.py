from collections import deque

#dfs 메서드 정의
def bfs(graph,v,visited):
  queue = deque([v])
  #현재 노드 방문 처리
  visited[v] = True

  while queue:
    #pop
    v=queue.popleft()
    print(v, end=' ')
    for i in graph[v]:
      if not visited[i]:
        queue.append(i)
        visited[i]=True

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

#방문 정보
visited = [False]*9
#함수 호출
bfs(graph,1,visited)