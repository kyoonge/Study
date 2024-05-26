N=int(input())
nlist = list(map(int, input().split()))
nlist.sort()
sortlist = []
n = 1001

for i in nlist:
  if i!=n:
    sortlist.append(i)
    n=i

print(*sortlist)