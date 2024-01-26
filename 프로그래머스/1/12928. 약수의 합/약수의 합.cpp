#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> array(n,0); 
    
    for(int i=1 ; i<=n; i++){
        if(n%i!=0) continue;
        array[i-1] = 1;
    }
    
    for(int i = 0; i<n; i++){
        answer += array[i]*(i+1);
    }
    
    return answer;
}