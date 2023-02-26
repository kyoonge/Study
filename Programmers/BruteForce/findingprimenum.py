import itertools
import math

def solution(numbers):
    numlist = list(numbers)
    checklist=[]
    sosu=[]
    
    for i in range(len(numlist)+1):
        checklist.extend(list(map(''.join,itertools.permutations(numlist,i))))
    
    
    for i in checklist:
        check=True
        if i:
            for j in range(2,int(math.sqrt(int(i)))+1):
                if int(i)%j==0:
                    check=False
                    break
            if check and int(i) not in sosu and int(i)>1:
                sosu.append(int(i))
    
    return len(sosu) 
