#3-2
N, M, K = map(int, input().split())
num = list(map(int,input().split()))
result = 0

sorted(num)
for i in range(1,M+1):
  if M%i==1:
    result+=num[N-2]
    print(result)
  else:
    result+=num[N-1]
    print(result)

print(result)

#3-3
N, M = map(int, input().split())
data = []
nums = []
for i in range(N):
  data.append(sorted(list(map(int, input().split()))))
  nums.append(data[i][0])

sorted(nums)
  
print(nums[N-1])

#3-4
N, k = map(int, input().split())
result = 0
while N!=1:
  if not N%k:
    N //= k
  else:
    N -= 1
  result+=1
print(result)
