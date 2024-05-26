s=input()

def solution(s):
  
  checkline=""
  nextline=""
  newline=""
  minlen=1000
  samecount=1

  if len(s)==1:
    return 1
    
  for i in range(1,int(len(s)/2+1)):  
    samecount=1
    for j in range(int(len(s)/i+1)):
      checkline=s[i*j:i*(j+1)]
      nextline=s[i*(j+1):i*(j+2)]
      if (checkline == nextline):
        samecount+=1
        checkline = nextline
      elif (checkline!=nextline):
        if (samecount>1):
          newline+=str(samecount)
        newline+=checkline
        samecount=1
        checkline=nextline
    minlen = min(len(newline),minlen)
    newline =""

  return minlen

print(solution(s))