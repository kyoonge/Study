#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int maxCount = 0;

void calculate(int hp, vector<vector<int>> dungeons, vector<bool> checked, int count){
    
    for(int i=0; i< dungeons.size();i++){
        if(count == dungeons.size()){
            return;
        }
        
        if(!checked[i] && hp>=dungeons[i][0]){
            checked[i] = true;
            hp -= dungeons[i][1];
            count++;

            if(count > maxCount){
                maxCount = count;
            }
            
            calculate(hp, dungeons, checked, count);
            
            checked[i] = false;
            hp += dungeons[i][1];
            count--;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    vector<int> indexArray(dungeons.size(),0);
    vector<bool> checked(dungeons.size(),false);
    
    calculate(k, dungeons, checked, 0);
    
    return maxCount;
}

