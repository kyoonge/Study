N,M = map(int,input().split())
start_x, start_y, a = map(int, input().split())
maplist = []
count = 1
jump_count = 0
for i in range(N):
  maplist.append(list(map(int,input().split())))

Go = [(0,-1),(-1,0),(0,1),(1,0)]
Jump = [(1,0),(0,-1),(-1,0),(0,1)]

while True:
  if start_x + Go[a][0]>=0 and start_x + Go[a][0]<N and  start_y + Go[a][1]>=0 and start_y + Go[a][1]<M and maplist[start_x + Go[a][0]][start_y + Go[a][1]]==0:
    maplist[start_x][start_y] = 1
    start_x+=Go[a][0]
    start_y+=Go[a][1]
    count += 1
    jump_count = 0
    a-=1
    if(a<0): a=3
  elif jump_count == 3:
    if start_x + Jump[a][0]>=0 and start_x + Jump[a][0]<N and  start_y + Jump[a][1]>=0 and start_y + Jump[a][1]<M and maplist[start_x + Jump[a][0]][start_y + Jump[a][1]]==0:
      start_x+=Jump[a][0]
      start_y+=Jump[a][1]
      maplist[start_x + Jump[a][0]][start_y + Jump[a][1]] = 1
      count += 1
      jump_count = 0
    else:
      break
  else:
    jump_count += 1
    a-=1
    if(a<0): a=3
print(count)