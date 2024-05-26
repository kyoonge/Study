N = int(input())
map=[]
friends=[]
for i in range(N):
  map.append(list(input()))
count=0
maxcount=0

for i in range(N):
  for j in range(N):
    if(map[i][j]=='Y'):
      if j not in friends:
        friends.append(j)
        count+=1
      for k in range(N):
        if(map[k][j]=='Y' and k != i):
          if( k not in friends):
            friends.append(k)
            count+=1
          
  maxcount = max(count,maxcount)
  count=0
  friends =[]

print(maxcount)
      
      