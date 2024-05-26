import sys

N,r,c= map(int,sys.stdin.readline().split())


def calcul(N,r,c,count):
  if(N==0):
    print(count)
    return
  if r>=0 and r<2**(N-1):
    if c>=0 and c<2**(N-1):
        count+=0
        calcul(N-1,r,c,count)
    elif c>=2**(N-1) and c<2**N:
        count+=4**(N-1)
        calcul(N-1,r,c-2**(N-1),count)
  elif r>=2**(N-1) and r<2**N:
    if c>=0 and c<2**(N-1):
        count+=(4**(N-1))*2
        calcul(N-1,r-2**(N-1),c,count)
    elif c>=2**(N-1) and c<2**N:
        count+=(4**(N-1))*3
        calcul(N-1,r-2**(N-1),c-2**(N-1),count)

calcul(N,r,c,0)