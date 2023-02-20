N = int(input())
result=[]

def calcul(N, count):
  if count in result:
    return
  if N==1:
    result.append(count)
    return
  if N%2==0:
    calcul(N/2,count+1)
  if N%3==0:
    calcul(N/3,count+1)
  calcul(N-1,count+1)
  if N<1:
    return

calcul(N,0)
result.sort()
print(result[0])