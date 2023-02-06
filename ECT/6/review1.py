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

#6-3
array = [7, 5, 9, 0, 3, 1, 6, 2, 4, 8]

def quick(array,start,end):
  if start>=end:
    return
  pivot = start
  left = start+1
  right = end
  while left<=right:
    while left<=end and array[left]<=array[pivot]:
      left+=1
    while right>start and array[right]>=array[pivot]:
      right-=1
    if left > right:
      array[right], array[pivot] =array[pivot], array[right]
    else:
      array[left], array[right] =array[right], array[left]
    quick(array,start,right-1)
    quick(array,right+1,end)

quick(array,0,len(array)-1)
print(array)

#6-4
array = [7, 5, 9, 0, 3, 1, 6, 2, 4, 8]

def quick_sort(array,start,end):
  if start >= end: #원소가 1개인 경우 종료
    return
  pivot = start #피벗은 첫 번째 원소
  left = start+1
  right = end
  while left <= right:
    #피벗보다 큰 데이터를 찾을 때까지 반복
    while left <= end and array[left] <= array[pivot]:
      left+=1
    #피벗보다 작은 데이터를 찾을 때까지 반복
    while right > start and array[right] >= array[pivot]:
      right-=1
    if left > right: #엇갈렸다면 작은 데이터와 피벗을 교체
      array[right], array[pivot] = array[pivot],array[right]
    else: #엇갈리지 않았다면 작은 데이터와 큰 데이터를 교체
      array[left], array[right] = array[right], array[left]
    #분할 이후 왼쪽 부분과 오른쪽 부분에서 각각 정렬 수행
  quick_sort(array,start, right-1)
  quick_sort(array,right+1,end)

quick_sort(array,0,len(array)-1)
print(array)