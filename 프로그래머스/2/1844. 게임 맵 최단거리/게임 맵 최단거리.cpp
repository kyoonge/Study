#include<vector>
#include<iostream>
#include<queue>
using namespace std;

struct Pos {
    int x;
    int y;
    Pos(int _y, int _x) { y = _y; x = _x; }
};

int solution(vector<vector<int>> maps)
{
    int direction[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    int answer = 0;
    
    int maxRow = maps.size();
    int maxCol = maps[0].size();
    
    vector<vector<bool>> checked(maxRow, vector<bool>(maxCol));
    vector<vector<int>> dist(maxRow, vector<int>(maxCol));
    queue<Pos> q;
    
    q.push(Pos(0, 0));  // 큐에 넣기
    checked[0][0] = true; // 예약
    dist[0][0] = 1; // 출발지의 거리는 1
    
    while(!q.empty()){
        
        Pos curPos = q.front();
        q.pop();
        int curRow = curPos.y;
        int curCol = curPos.x;
        
        for(int i=0; i<4; i++){
            //4방향 큐에 넣기
            int r = curRow + direction[i][0];
            int c = curCol + direction[i][1];
            
            if(r<0 || c<0 || r>=maxRow || c>=maxCol) continue;
            if(checked[r][c]) continue;
            if(maps[r][c] == 0) continue;
            
            q.push(Pos(r,c));
            checked[r][c] = true;
            dist[r][c] = dist[curRow][curCol] + 1;
        }
    }
    
    answer = dist[maxRow-1][maxCol-1];
    if(!checked[maxRow-1][maxCol-1]) return -1;
    
    return answer;
}