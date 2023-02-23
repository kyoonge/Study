import sys
diff = []
count=0
result=[]

N,M = map(int,sys.stdin.readline().split())
for i in range(N):
    line=list(sys.stdin.readline().strip())
    for j in range(M):
        if i%2==0:
            if j%2==0 and line[j]!='B':
                diff.append([i,j])
            elif j%2==1 and line[j]!='W':
                diff.append([i,j])
        else:
            if j%2==0 and line[j]!='W':
                diff.append([i,j])
            elif j%2==1 and line[j]!='B':
                diff.append([i,j])

for n in range(N-8+1):
  for m in range(M-8+1):
    for con in diff:
      if con[0]>=n  and con[0]<8+n and con[1]>=m  and con[1]<8+m:
        count+=1
        
    if count > 8*8/2:
        count=8*8-count
    result.append(count)
    count=0

result.sort()
print(result[0]) 