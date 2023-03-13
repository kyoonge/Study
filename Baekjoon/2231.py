N = int(input())

for i in range(1,N+1):
  ilist=list(map(int,str(i)))
  if N==sum(ilist)+i:
    print(i)
    break
  if i==N:
    print(0)