import sys

d = {
    "R": (0, 1),
    "L": (0, -1),
    "B": (-1, 0),
    "T": (1, 0),
    "RT": (1, 1),
    "LT": (1, -1),
    "RB": (-1, 1),
    "LB": (-1, -1)
}

k, r, N = map(str,sys.stdin.readline().split())
Road=[]
N = int(N)
for i in range(N):
  Road.append(sys.stdin.readline().strip())

k0=int(ord(k[0]) - 64)
k1=int(k[1])
r0=int(ord(r[0]) - 64)
r1=int(r[1])

def move(i,k0,k1,r0,r1):
  for i in range(N):
    ni = d[Road[i]]
    nA = k0+ni[1]
    n1 = k1+ni[0]
    if nA>=1 and nA<=8 and n1>=1 and n1<=8:
      if nA==r0 and n1==r1:
        #돌이동
        nrA = r0+ni[1]
        nr1 = r1+ni[0]
        if nrA>=1 and nrA<=8 and nr1>=1 and nr1<=8:
          r0=nrA
          r1=nr1
          k0=nA
          k1=n1
        else:  
          continue
      else:
        #왕이동
        k0=nA
        k1=n1
    else:
      continue
  return k0,k1,r0,r1

k0,k1,r0,r1=move(0,k0,k1,r0,r1)

print(str(chr(k0+64)),k1,sep='')
print(str(chr(r0+64)),r1,sep='')
