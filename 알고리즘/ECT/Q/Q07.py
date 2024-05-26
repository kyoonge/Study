line = list(input())
print(line)

left, right = 0,0

linelen = len(line)
for i in range(int(linelen/2)):
  left += int(line[i])
  right += int(line[linelen-1])
if right == left: print("LUCKY")
else: print("READY")