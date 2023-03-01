N=int(input())
d=0
go=[(1,0),(0,-1),(-1,0),(0,1)]
r,c=0,0
maxr,minr,maxc,minc=0,0,0,0
way = input()
waylist=[[0,0]]
for i in range(len(way)):
  if way[i]=='R':
    d+=1
    if(d==4): d=0
  elif way[i]=='L':
    d-=1
    if(d==-1): d=3
  elif way[i]=='F':
    r+=go[d][0]
    c+=go[d][-1]
    waylist.append([r,c])
waylist.sort(key=lambda x: x[0])
minr=waylist[0][0]
maxr=waylist[len(waylist)-1][0]
rlen=maxr-minr
waylist.sort(key=lambda x: x[1])
minc=waylist[0][1]
maxc=waylist[len(waylist)-1][1]
clen=maxc-minc

chr = -minr
chc = -minc
print(waylist,minr,maxr,minc,maxc)
world=[['#'for j in range(clen+1)] for i in range(rlen+1)]
print(world)
for i in waylist:
  i[0]+=chr
  i[1]+=chc
  world[i[0]][i[1]]='.'
for i in world:
  print(*i, sep='')
