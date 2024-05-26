#입력
N,M = map(int,input().split())
field=[]
for i in range(N):
    field.append(list(input()))
savelist=[]
#'#'좌표와 가능한 크기 전부 저장
def checkdot(r,c):
    size = 0
    while True:
        if 0<=c-size and c+size<M and 0<=r-size and r+size<N and field[r][c-size] == field[r][c+size] == field[r-size][c] == field[r+size][c] == '#':
          if [r,c,size] not in savelist:
            savelist.append([r,c,size])
            size+=1
        else:
          break
        
#두 십자가 겹치는지 검사
def compare(d1,d2):
    tmpfield = [ [0 for i in range(M)]for j in range(N)]
    dx=[1,-1,0,0]
    dy=[0,0,1,-1]
    r1,c1,s1=d1[0],d1[1],d1[2]
    r2,c2,s2=d2[0],d2[1],d2[2]
  
    for size in range(s1+1):
      for di in range(4):
        tmpfield[r1+dx[di]*size][c1+dy[di]*size]=1
    for size in range(s2+1):
      for di in range(4):
        if tmpfield[r2+dx[di]*size][c2+dy[di]*size] ==1:
          return -1
    return (4*s1+1)*(4*s2+1)
        
for i in range(N):
  for j in range(M):
    if field[i][j]=='#':
        checkdot(i,j)
        
result =0

for i in range(len(savelist)):
  for j in range(i+1,len(savelist)):
    if (savelist[i][2]*4+1)*(savelist[j][2]*4+1)>result:
        result = max(result,compare(savelist[i],savelist[j]))
        
print(result)