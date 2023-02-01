from collections import deque
road=[]
N, M = map(int,input().split())
for i in range(N):
  road.append(list(map(int,input())))

dx = [1,-1,0,0]
dy = [0,0,-1,1]

queue = deque()
queue.append((0,0))

while queue:
  x, y = queue.popleft()
  for i in range(4):
    nx = x + dx[i]
    ny = y + dy[i]
    if nx < 0 or nx>=N or ny<0 or ny>=M:
      continue
    elif road[nx][ny]!=1:
      continue
    elif road[nx][ny] == 1:
      road[nx][ny] = 1 + road[x][y]
      queue.append((nx,ny))

print(road[N-1][M-1])