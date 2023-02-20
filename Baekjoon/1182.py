N, S = map(int,input().split())
nums = list(map(int, input().split()))
count =[]

def calcul(i,sum):
  if i==len(nums):
    if sum==S and i!=0:
      count.append(1)
    return
  calcul(i+1,sum+nums[i])
  calcul(i+1,sum)

calcul(0,0)
result = len(count)
if (S==0): result-=1
elif (S==0 and result==0): result=0
print(result)