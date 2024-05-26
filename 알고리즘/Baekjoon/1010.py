T= int(input())


for i in range(T):
  result = 1
  m = 0
  n = 0
  N, M = map(int,input().split())
  for j in range(N):
    result *= (M/(N-j))
    M-=1
  print(int(result+0.5))