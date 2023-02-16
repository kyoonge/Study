N = int(input())
numLine = list(map(int,input().split()))
numList = []

cal=0
  
def calculate(value,i,cal):
  cal+=value*numLine[i]
  if(i==(N-1)):
    if(cal not in numList):
     numList.append(cal)
    return
  calculate(1,i+1,cal)
  calculate(0,i+1,cal)

calculate(0,0,0)
calculate(1,0,0)

numList.sort()
print(numList)

j = 0
for i in numList:
  if i != j: 
    print(j)
    break
  j+=1