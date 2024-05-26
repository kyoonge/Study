line = list(input())
num=0
startofstr = 0
line.sort()
print(line)

for i in range(len(line)):
  if line[i].isalpha():
    startofstr = i
    break
  else:
    num+=int(line[i])

result = ''.join(line[startofstr: ])+str(num)
print(result)
