N = int(input())
numList = list(map(int,input().split()))
count = 0
result = 0

numList.sort(reverse=True)

count = numList[0]-1
for i in range(N):
  if(count!=0):
    count-=1
    print(i)
    continue
  result+=1
  count = numList[i]-1

print(result)