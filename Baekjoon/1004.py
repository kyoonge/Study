import math

def calcul(count):
  for i in range(n): 
    isin=0
    if math.sqrt((c[i][0]-x1)*(c[i][0]-x1) +(c[i][1]-y1)*(c[i][1]-y1))<c[i][2]:
      isin+=1
    if math.sqrt((c[i][0]-x2)*(c[i][0]-x2) +(c[i][1]-y2)*(c[i][1]-y2))<c[i][2]:
      isin+=1
    if isin != 2:
      count+=isin
  return count
  


T = int(input())

for i in range(T):
  x1,y1,x2,y2 = map(int,input().split())
  n = int(input())
  c=[]
  for i in range(n):
    c.append(list(map(int,input().split())))

  print(calcul(0))