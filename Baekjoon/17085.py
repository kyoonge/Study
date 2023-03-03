#입력
n,m = map(int,input().split())
field=[]
for i in range(n):
    field.append(list(input()))
savelist=[]

#함수1: '#'포함 좌표, 가능한 크기 리스트에 저장
def savedot(r,c):
    dx = [-1,0,1,0]
    dy = [0,1,0,-1]
    size=0
    while r-size>=0 and r+size<n and c-size>=0 and c+size<m and field[r-size][c]==field[r+size][c]==field[r][c-size]==field[r][c+size]=='#':
        size+=1
    while size>0:
        size-=1
        savelist.append([size, r, c])
  
#함수2: 유효성 검사(두 십자가가 서로 겹치지 않는지, 결과 저장)
def compare(dot1,dot2):
    dx=[-1,1,0,0]
    dy=[0,0,1,-1]
    testfield=[[0 for i in range(m)]for i in range(n)]
    for size in range(dot1[0]+1):
      for i in range(4):
        testfield[dx[i]*size+dot1[1]][dy[i]*size+dot1[2]]=1
    for size in range(dot2[0]+1):
      for i in range(4):
        if testfield[dx[i]*size+dot2[1]][dy[i]*size+dot2[2]]==1:
          return 0
  
  return (dot1[0]*4+1)*(dot2[0]*4+1)

#모든 '#'에 대해 탐색
for i in range(n):
  for j in range(m):
    if field[i][j]=='#':
        savedot(i,j)
#print(savelist)

#결과 비교
result=0
for i in range(len(savelist)):
  for j in range(i, len(savelist)):
    if result<((savelist[i][0]*4+1)*(savelist[j][0]*4+1)):
        result = max(compare(savelist[i], savelist[j]),result)
print(result)