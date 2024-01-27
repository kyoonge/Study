#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct Pos{
    int x;
    int y;
    Pos(int _x, int _y){x=_x; y=_y;}
};

Pos findCharacterInVector(vector<string> vec, char character) {
    for (int y = 0; y < vec.size(); ++y) {
        for (int x = 0; x < vec[y].size(); ++x) {
            if (vec[y][x] == character) {
                return Pos(y, x);
            }
        }
    }
    return Pos(-1, -1); // 문자를 찾지 못한 경우
}

int Dfs(vector<string> maps, char start, char end){
    int answer = 0;
    int maxR = maps.size();
    int maxC = maps[0].length();
    
    if(start == 'L')cout << maxR << " ";
    if(start == 'L')cout << maxC << " ";
    
    vector<vector<bool>> checked(maxR, vector<bool>(maxC,false));
    vector<vector<int>> dist(maxR, vector<int>(maxC));
       
    int direction[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    Pos startPos = findCharacterInVector(maps, start);
    
    queue<Pos> q;
    q.push(startPos);
    checked[startPos.x][startPos.y] = true;
    dist[startPos.x][startPos.y] = 1;
    
    while(!q.empty()){
        Pos curPos = q.front();
        q.pop();
        int curR = curPos.x;
        int curC = curPos.y;
        
        for(int i=0; i<4; i++){
            int r = curR + direction[i][0];
            int c = curC + direction[i][1];
            
            if(r<0||r>=maxR||c<0||c>=maxC) continue;
            if(checked[r][c]==true) continue;
            if(maps[r][c] =='X') continue;
            q.push(Pos(r,c));
            checked[r][c] = true;
            dist[r][c] = dist[curR][curC] + 1;
            
            if(maps[r][c] == end){
                return dist[r][c];
            }
        }
    }
    
    return -1;
}

int solution(vector<string> maps) {
    int answer = 0;
    
    int firstAnswer = Dfs(maps, 'S', 'L');
    int secAnswer = Dfs(maps, 'L', 'E');
    
    cout << firstAnswer << " ";
    cout << secAnswer << " ";
    
    if(firstAnswer == -1 || secAnswer == -1) return -1;
    else return firstAnswer + secAnswer -2;
}

