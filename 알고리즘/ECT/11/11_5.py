N, Max = map(int,input().split())
numLine = list(map(int,input().split()))
result = 0

for i in numLine:
  result += N - numLine.count(i)
print(int(result/2))
