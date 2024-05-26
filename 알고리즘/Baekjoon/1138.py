N = int(input())
info = list(map(int,input().split()))
info.reverse()
nums=[]
for i in range(N):
    nums.append(N-i)

for i in range(N):
    new = nums.pop(i)
    nums.insert(info[i],new)
    
print(*nums)