#include <cmath>
#include <cstring>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

//상하좌우 이동
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {-1, 1, 0, 0};

struct Room {
  int parentX, parentY;
  double f, g, h;
};

double GetH(int x, int y, pair<int, int> dst);
bool AstarSearch(vector<vector<int>> world, pair<int, int> dst);

int main() {
  //맵 입력
  int row, col = 0;
  pair<int, int> start, dst;

  cin >> row >> col;
  start = {0, 0};
  dst = {row, col};

  vector<vector<int>> grid(row, vector<int>(col));

  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j) {
      cin >> grid[i][j];
    }
  }

  cout << grid[0][0];  
  
  if (AstarSearch(grid, dst)) {
    cout << "good";
  }
}


double GetH(int x, int y, pair<int, int> dst) {
  return (double)sqrt(pow(x - dst.first, 2) + std::pow(y - dst.second, 2));
}

bool AstarSearch(vector<vector<int>> world, pair<int, int> dst) {

  bool closedList[dst.first][dst.second];
  memset(closedList, false, sizeof(closedList));

  Room room[dst.first][dst.second];
  for (int i = 0; i < dst.first; ++i) {
    for (int j = 0; j < dst.second; ++j) {
      room[i][j].f = room[i][j].g = room[i][j].h = -1;
      room[i][j].parentX = room[i][j].parentY = -1;
    }
  }

  
  
  int sx, sy = 0;
  room[sy][sx].f = room[sy][sx].g = room[sy][sx].h = 0.0;
  room[sy][sx].parentX = sx;
  room[sy][sx].parentY = sy;

  //열린배열에 첫 노드 삽입 (0,0)
  set<pair<double, pair<int, int>>> openList;
  openList.insert({0.0, {sy, sx}});

  //탐색
  while (!openList.empty()) {
    pair<double, pair<int, int>> p = *openList.begin();
    openList.erase(openList.begin());

    int y = p.second.first;
    int x = p.second.second;
    closedList[y][x] = true;

    double ng, nf, nh;

    // 상하좌우 노드 탐색
    for (int i = 0; i < 4; ++i) {


      cout<<"\n";
        for(int i=0;i<dst.first;i++){
          for(int j=0;j<dst.second;j++){
            cout<< closedList[i][j];
          }
          cout<<"\n";
        }
          
        cout << "1";
      int ny = y + dy[i];
      int nx = x + dx[i];
      cout << "ny: "<<ny <<" nx: "<<nx<<"\n";

      if (ny >= 0 && ny < dst.first && nx >= 0 && nx < dst.second) {
        cout << "2.1";
        if (ny == dst.first && nx == dst.second) {
          room[ny][nx].parentY = y;
          room[ny][nx].parentX = x;
          // tracePath(cellDetails, dst);
          cout << "2.2";
          return true;
        }
        // bfs와 굳이 비교하자면, closedList를 방문여부라고 생각하시면 됩니다.
        else if (!closedList[ny][nx] && world[y][x] == 1) {
          // 이부분 y x, ny nx 헷갈리는거 조심
          cout << "3";
          ng = room[y][x].g + 1.0;
          nh = GetH(ny, nx, dst);
          nf = ng + nh;

          // 만약 한번도 갱신이 안된f거나, 새로갱신될 f가 기존f보다 작을시 참
          if (room[ny][nx].f == -1 || room[ny][nx].f > nf) {
            cout << "4";
            room[ny][nx].f = nf;
            room[ny][nx].g = ng;
            room[ny][nx].h = nh;
            room[ny][nx].parentX = x;
            room[ny][nx].parentY = y;
            openList.insert({nf, {ny, nx}});
            cout<<" nf: "<<nf;
          }
        }
      }
    }
  }

  return false;
}
