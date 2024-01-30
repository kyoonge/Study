#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {

    priority_queue<int> pq;
    int answer = 0;
    for(int i=0; i<enemy.size(); i++){
        if(n>=enemy[i]){
            n-=enemy[i];
            pq.push(enemy[i]);
        }
        else{
            if(k==0) break;
            if(!pq.empty()){
                if(pq.top()>enemy[i]){
                    n+=pq.top();
                    n-=enemy[i];
                    
                    pq.pop();
                    pq.push(enemy[i]);
                }
            }
            k--;
        }
        answer = i;
    }
    
    return answer+1;
}