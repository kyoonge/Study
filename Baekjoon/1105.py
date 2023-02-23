import sys

L,R= map(str,sys.stdin.readline().split())
result=[]
count=0

if len(L) != len(R):
  print(count)
else:
  for i in range(len(L)):
    if L[i]==R[i] and L[i]=='8':
      count+=1
    else:
      break
  print(count)

