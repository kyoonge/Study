#4-1
N = int(input())
count = 0

for h in range(N+1):
  for m in range(60):
    for s in range(60):
      if '3' in str(h)+str(m)+str(s):
        count+=1

print(count)

#4-3
input = str(input())
x = int(ord(input[0]))-int(ord('a'))+1
y = int(input[1])
count=0

direction = [(-2,1),(-2,-1),(2,1),(2,-1),(-1,2),(-1,-2),(1,2),(1,-2)]

for i in range(8):
  nx = x + direction[i][0]
  ny = y + direction[i][1]
  if nx>0 and nx<=8 and ny>0 and ny<=8:
    count+=1

print(count)

#4-4
N, M = map(int, input().split())
x, y, d = map(int,input().split())
countd = 0
result = 1
world =[]
for i in range(N):
  world.append(list(map(int,input().split())))

fdir = [(-1,0),(0,1),(1,0),(0,-1)]
bdir = [(1,0),(0,-1),(-1,0),(0,1)]
world[x][y]=1

while True:
  d-=1
  if d<0: d=3
  countd +=1
  if world[x+fdir[d][0]][y+fdir[d][1]]==0:
    x += fdir[d][0]
    y += fdir[d][1]
    world[x][y]=1
    countd=0
    result+=1
    print("1",x,y,result)
  elif countd == 3:
    if world[x+bdir[d][0]][y+bdir[d][1]]==0:
      x += bdir[d][0]
      y += bdir[d][1]
      world[x][y]=1
      countd=0
      result+=1
      print("2",x,y,result)
    else:
      break

print(result)
      