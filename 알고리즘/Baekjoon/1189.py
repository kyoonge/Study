import sys

R,C,K = map(int,sys.stdin.readline().split())
world=[]
for i in range(R):
  world.append(list(sys.stdin.readline().strip()))
dr = [1,0,-1,0]
dc = [0,-1,0,1]
result=0

def go(nr,nc,count):
  global result
  if count == K:
    if nr==0 and nc==C-1:
        result+=1
  else:
    for i in range(4):
        newr = nr+dr[i]
        newc = nc+dc[i]
        if 0<=newr and newr<R and 0<=newc and newc<C:
          if world[newr][newc]!='T':
            world[newr][newc]='T'
            go(newr,newc,count+1)
            world[newr][newc]='.'

world[R-1][0]='T'
go(R-1,0,1)
print(result)