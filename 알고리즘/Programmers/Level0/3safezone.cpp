#include <string>
#include <vector>
#include <iostream>

using namespace std;
int solution(vector<vector<int>> board);

int main(){
  vector<vector<int>> board = {{1,1,1,1,1,1}, {1,1,1,1,1,1},{1,1,1,1,1,1}, {1,1,1,1,1,1}, {1,1,1,1,1,1}, {1,1,1,1,1,1}};

  /*vector<vector<int>> board = {{0,1,0},{0,0,0},{0,0,0}};
  */
  cout << solution(board);
  
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    int nx[8] = {-1,0,1,-1,1,-1,0,1};
    int ny[8] = {-1,-1,-1,0,0,1,1,1};
    int nowx=0;
    int nowy=0;
    int n = board.size();
    
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if(board[i][j]==1){
              answer+=1;
              for(int k=0; k<8;k++){
                nowx = i+nx[k];
                nowy = j+ny[k];
                if(nowx>=0&&nowy>=0&&nowx<n&&nowy<n){
                    if(board[nowx][nowy]==0){
                        answer+=1;
                        board[nowx][nowy]=2;
                    }
                }                
              }             
            }
        }
    }
    answer = n*n-answer;
    return answer;
}

