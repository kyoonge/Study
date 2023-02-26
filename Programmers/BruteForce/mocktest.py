def solution(answers):
    c1,c2,c3=0,0,0
    answer = []
    maxc =0
    list1 = [1,2,3,4,5]*(10000//5)
    list2 = [2,1,2,3,2,4,2,5]*(10000//8)
    list3 = [3,3,1,1,2,2,4,4,5,5]*(10000//10)
    
    for i in range(len(answers)):
        if answers[i]==list1[i]:
            c1+=1
        if answers[i]==list2[i]:
            c2+=1
        if answers[i]==list3[i]:
            c3+=1
    maxc=max(c1,c2,c3)
    if c1==maxc: answer.append(1)
    if c2==maxc: answer.append(2)
    if c3==maxc: answer.append(3)
    

    return answer