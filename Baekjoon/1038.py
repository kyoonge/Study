N = int(input())
nlist=[]
if N<10:
    print(N)
elif int(N)>1022:
    print(-1)
else:
  for i in range(1,10):
    for j in range(i):
        nlist.append(int(str(i)+str(j)))

  if N<=54:
    print(nlist[N-10])
  else:
    for i in nlist:
      for j in range(int(str(i)[0])+1,10):
        #print(i,str(int(i[0])+1)+i)
        nlist.append(int(str(j)+str(i)))
    nlist.sort()
    print(nlist[N-10])