#include <string>
#include <iostream>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for(int i=1 ; i<=sqrt(n); i++){
        if(n%i!=0) continue;
        if(i != sqrt(n)) answer += i + (n/i);
        else answer += i;
    }
    
    
    return answer;
}