#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int scale = brown + yellow;
    int row = 0;
    
    for(int col=scale; col>0;col--){
        
        if( scale % col != 0 ) continue;

        row = scale / col;
        if( 2*(col+row) == brown + 4 )
        {
            answer.push_back(col);
            answer.push_back(row);
            break;
        }
            
    }
    
    return answer;
}