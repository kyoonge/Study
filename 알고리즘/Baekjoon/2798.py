import itertools

N, M = map (int, input().split())
numlist = list(map(int,input().split()))
com=list(itertools.combinations(numlist,3))
result=0
for i in com:
  if sum(i)<=M:
    result=max(result,sum(i))
print(result)