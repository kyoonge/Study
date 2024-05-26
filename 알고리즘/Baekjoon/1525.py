import sys
from collections import deque
input = ""
for i in range(3):
    l1,l2,l3= map(str,sys.stdin.readline().split())
    input+=l1+l2+l3
r=0

def bfs(input):
    info ={}
    dx=[1,-1,0,0]
    dy=[0,0,1,-1]
    q = deque([input])
    info[input]=0
    while q:
        numline = q.popleft()
        #문자열 같다면 탈출
        if numline=="123456780":
            return info[numline]
            
                
        #자리이동( 확인)
        zero = numline.find("0")
        r = zero//3
        c = zero%3
        for i in range(4):
            nr = r+dx[i]
            nc = c+dy[i]
            if 0<=nr<3 and 0<=nc<3:
                newnum = list(numline)
                newnum[zero], newnum[nr*3+nc]=newnum[nr*3+nc], newnum[zero]
                newnumline = "".join(newnum)
                #큐에 없다면 정보 넣기( 큐, 딕셔너리)
                if newnumline not in info:
                    q.append(newnumline)
                    info[newnumline]=info[numline]+1
    

    return
r = bfs(input)
if r==None:
    r = -1
print(r)
  