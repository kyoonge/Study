#반복
def factorial_iterative(n):
  result = 1
  #1부터 n까지의 수를 차례대로 곱하기
  for i in range(1,n+1):
    result*=i
  return result

#재귀
def factorial_recursive(n):
  if n==0: return 1
  return n*factorial_recursive(n-1)

print('반복구현:',factorial_iterative(5))
print('재귀구현:',factorial_recursive(5))