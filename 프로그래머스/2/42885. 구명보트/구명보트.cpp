#include <string>
#include <algorithm>

using namespace std;

bool cmp(int a, int b){
    return a>b;
}

int solution(vector<int> people, int limit) {
    
    int answer = 0;
    int rIndex = people.size()-1;
    
    sort(people.begin(), people.end(), cmp);
    
    for(int i = 0; i<=rIndex; i++){
        
        answer += 1;
        if(people[i] + people[rIndex] <= limit){
            rIndex--;
        }
        
    }
    
    return answer;
}

