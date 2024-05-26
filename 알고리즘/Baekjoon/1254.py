line= input()
newline = line

def check(st):
  S= list(st)
  for i in range(len(S)//2):
    if S[i]!=S[len(S)-i-1]:
      return False
  return True

if check(line): 
  print(len(line))
else:
  for i in range(len(line)):
    for j in range(i+1):
      newline += line[i-j]
    if check(newline): 
      print(newline,len(newline))
      break
    else:
      newline=line
    
      
        