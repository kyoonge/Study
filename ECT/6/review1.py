#6-1
array = [7,5,9,0,3,1,6,2,4,8]

for i in range(len(array)-1):
  min_index = i
  for j in range(i+1,len(array)):
    if array[j]<array[min_index]:
      min_index = j
  array[min_index], array[i] = array[i], array[min_index]

print(array)

#6-2
array = [7, 5, 9, 0, 3, 1, 6, 2, 4, 8]

for i in range(1, len(array)):
  for j in range(i, 0, -1):
    if array[j] >= array[j-1]:
      break
    else:
      array[j],array[j-1]=array[j-1],array[j]
print(array)