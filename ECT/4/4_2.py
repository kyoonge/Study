N = int(input())
count = 0


for h in range(N+1):
  if(str(h).find('3')!=-1):
    count+=3600
    continue
  for m in range(60):
    if(str(m).find('3')!=-1):
      count+=60
      continue
    for s in range(60):
      if(str(s).find('3')!=-1):
        count+=1

print(count)