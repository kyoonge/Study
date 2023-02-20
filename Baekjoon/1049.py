N, M = map(int,input().split())
minP, minS = 1000, 1000

for i in range(M):
  P, S = map(int,input().split())
  minP = min(minP, P)
  minS = min(minS, S)

def calcul():
  if minS*6 <= minP:
    return minS*N
  return min((N//6)*minP + (N%6)*minS, ((N//6)+1)*minP)

print(calcul())