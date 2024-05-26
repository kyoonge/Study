#include <iostream>
#include <vector>
using namespace std;

int N, D;
int answer = 10000;

void solution(vector<vector<int>> &shortCut, vector<bool> check, int now, int result) {
	
	if (now > D) {
		cout << "out " << endl;
		return;
	}


	for (int i = 0; i < N; i++) {
		if (check[i] == false) {
			if (now <= shortCut[i][0] && shortCut[i][1] <= D ) {
				check[i] = true;
				solution(shortCut, check, shortCut[i][1], shortCut[i][0] - now + shortCut[i][2]);
				check[i] = false;
			}

		}
		cout << "_i:"<<i << "_now:" << now << "_result:" << result << endl;
	}
	for (int i = 0; i < N; i++) {
		cout << check[i];
	}
	result += D - now;
	cout << "[result] : " << result << " now: "<<now<< endl;
	answer = min(answer, result);
	return;
}


int main()
{
	cin >> N >> D;
	vector<vector<int>> shortCut(N,vector<int>(3));
	vector<bool> check(N, false);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> shortCut[i][j];
		}
	}

	solution(shortCut, check, 0, 0);
	cout << answer;
}
