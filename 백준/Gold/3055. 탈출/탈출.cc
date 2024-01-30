#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Pos {
	int r;
	int c;
	Pos(int _r, int _c) { r = _r; c = _c; }
};

int solution(vector<string> map, int maxR, int maxC, queue<Pos> waterq, Pos startPos) {
	
	int answer = -1;
	vector<vector<int>> dist(maxR, vector<int>(maxC,0));
	vector<vector<bool>> checked(maxR, vector<bool>(maxC, false));
	int direction[4][2] = { {-1,0},{0,1 },{1,0},{0,-1 } };
	queue<Pos> q;
	q.push(startPos);
	checked[startPos.r][startPos.c] = true;

	while (!q.empty()) {



		//물
		int curSize = waterq.size();
		for(int qi = 0; qi < curSize; qi++){
			Pos curWater = waterq.front();
			waterq.pop();

			for (int k = 0; k < 4; k++) {
				int nextWR = curWater.r + direction[k][0];
				int nextWC = curWater.c + direction[k][1];
				//예외처리
				if (nextWR < 0 || nextWR >= maxR || nextWC < 0 || nextWC >= maxC) continue;
				if (map[nextWR][nextWC] == 'X'|| map[nextWR][nextWC] == 'S'|| map[nextWR][nextWC] == 'D'|| map[nextWR][nextWC] == '*') continue;

				waterq.push(Pos(nextWR, nextWC));
				map[nextWR][nextWC] = '*';
			}
		}

		int curQSize = q.size();
		for (int qQi = 0; qQi < curQSize; qQi++) {

			Pos cur = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nextR = cur.r + direction[i][0];
				int nextC = cur.c + direction[i][1];
				//예외처리
				if (nextR < 0 || nextR >= maxR || nextC < 0 || nextC >= maxC) continue;
				if (checked[nextR][nextC]) continue;
				if (map[nextR][nextC] == 'X' || map[nextR][nextC] == '*') continue;

				//예약
				q.push(Pos(nextR, nextC));
				checked[nextR][nextC] = true;
				dist[nextR][nextC] = dist[cur.r][cur.c] + 1;
				if (map[nextR][nextC] == 'D') return dist[nextR][nextC];
			}
		}
	}
	return -1;
}

int main()
{
	int r = 0;
	int c = 0;
	cin >> r >> c;
	
	Pos start(0, 0);
	queue<Pos> waterQ;
	vector<string> inputMap(r," ");

	//input
	for (int i = 0; i < r; ++i) {
		cin >> inputMap[i];
		
		for (int j = 0; j < c; j++) {
			if (inputMap[i][j] == 'S') start = Pos(i, j);
			else if (inputMap[i][j] == '*') waterQ.push(Pos(i, j));
		}
	}
	
	int answer = solution(inputMap,r,c, waterQ, start);
	if (answer == -1) cout << "KAKTUS";
	else cout << answer;

}