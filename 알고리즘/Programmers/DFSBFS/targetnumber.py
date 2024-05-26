def solution(numbers, target):
    answer = 0
    result =[]
    calcul(numbers,0,target,numbers[0],result)
    calcul(numbers,0,target,-numbers[0],result)
    
    return sum(result)

def calcul(numbers, index, target,sums,result):
    if sums == target and index==len(numbers)-1:
        result.append(1)
        return 1
    if index+1>=len(numbers):
        return 0
    calcul(numbers, index+1, target, sums+numbers[index+1],result )
    calcul(numbers, index+1, target, sums-numbers[index+1],result )
    
    