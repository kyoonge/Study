numList = list(map(int,input()))

def calcul(numList):
  result =1
  if(len(numList)==0):
    return numList[0]
  for i in range(len(numList)):
    if(numList[i]==0):
      continue
    result*=numList[i]
  return result

print(calcul(numList))