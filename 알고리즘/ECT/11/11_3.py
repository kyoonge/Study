numLine = input()
List0 = list(map(str, numLine.split('1')))
List1 = list(map(str, numLine.split('0')))

count0, count1=0, 0

for i in List0:
  if(i!=''):
    count0+=1
for i in List1:
  if(i!=''):
    count1+=1

print(min(count0,count1))