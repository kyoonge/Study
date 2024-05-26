N = int(input())
A = input()
X, Y = 1,1

for i in range(len(A)):
  if A[i] == "L" and Y > 1:
    Y-=1
  elif A[i] == "R" and Y < 5:
    Y+=1
  elif A[i] == 'U' and X > 1:
    X-=1
  elif A[i] == 'D' and X < 5:
    X+=1

print(str(X)+" "+str(Y))