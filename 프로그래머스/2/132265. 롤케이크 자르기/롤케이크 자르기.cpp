#include <string>
#include <vector>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    int size = topping.size();
    vector<int> big(size,0);
    vector<int> little(size,0);
    vector<bool> bigCheck(10000,false);
    vector<bool> littleCheck(10000,false);
    
        
    int bigToppingNum =0;
    int bigCount = 0;
    int littleToppingNum =0;
    int littleCount = 0;
    for(int i=0;i<size;i++){
        if(!bigCheck[topping[i]]){
            bigCheck[topping[i]]= true;
            bigCount++;
        }
        if(!littleCheck[topping[size-1-i]]){
            littleCheck[topping[size-1-i]]= true;
            littleCount++;
        }
        big[i] = bigCount;
        little[size-1-i]= littleCount;
    }
    
    for(int i=0;i<size-1;i++){
        if(big[i] == little[i+1]){
            answer++;
        }
    }
    
    return answer;
}
