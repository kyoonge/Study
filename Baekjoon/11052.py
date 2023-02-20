N = int(input())
plist = list(map(int,input().split()))
paylist = [0]*N
for i in range(N):
  paylist[i]=plist[i]

for i in range(N):
  for j in range(0,i):
      paylist[i]=max(paylist[i-j-1]+plist[j],paylist[i]) 

print(paylist[N-1])