import sys
n = int(sys.stdin.readline())

def check(num,count):
    answer=0
    if num<100:
        answer=num
        return answer
    for n in range(100,num+1):
        nlist=list(map(int, str(n)))
        ncheck=True
        d = nlist[1]-nlist[0]
        for i in range(1,len(nlist)-1):
            if nlist[i+1]-nlist[i]!=d:
                ncheck=False
                break
        if ncheck:
            count+=1
  
    return count+99 
    
print(check(n,0))