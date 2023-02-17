food_times = [4,10]
k = 10
result = 1

def solution(food_times, k):
    answer=0
    empty_count=0
    foodlen = len(food_times)
    i = 0

    while k>0:
        if food_times[i]!=0:
            k-=1
            food_times[i]-=1
            i=next_index(i,foodlen)
            empty_count=0
        elif food_times[i]==0:
            i=next_index(i,foodlen)
            empty_count+=1
        if empty_count==foodlen:
            return -1
        #print("i:",i," k:",k," food_times:",food_times)
    answer = i

    return answer+1


def next_index(i, len):
    i+=1
    if i==len:
        i=0
    #print("now i: ",i)
    return i

print(solution(food_times,k))
