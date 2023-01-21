num = int(input())
A = num//5
B = (num%5)//3

while (A*5+B*3)!=num:
  A-=1
  if(A<0):
    break
  B = (num-A*5)//3

if A<0:
  print("-1")
else:
  print(A+B)