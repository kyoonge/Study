n,m,k = map(int,input().split())
data = list(map(int, input().split()))
data.sort(reverse = True)
count = k
result = 0

for i in range(0,m):
  if count>0:
    result+=data[0]
    count-=1
  else:
    result+=data[1]
    count = k

print(result)

