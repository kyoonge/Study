#include <iostream>
#include <vector>
using namespace std;

int N;
int A[11];
int maxResult = -1000000001;
int minResult = 1000000001;

void solution(vector<int> cal, int idx, int result) {
	
	if (idx == N) {
		maxResult = max(maxResult, result);
		minResult = min(minResult, result);
		return;
	}
	
	if (cal[0] > 0) {
		cal[0]--;
		solution(cal, idx+1, result + A[idx]);
		cal[0]++;
	}
	if(cal[1]>0) {
		cal[1]--;
		solution(cal, idx+1, result - A[idx]);
		cal[1]++;
	}
	if (cal[2] > 0) {
		cal[2]--;
		solution(cal, idx+1, result * A[idx]);
		cal[2]++;
	}
	if (cal[3] > 0) {
		cal[3]--;
		solution(cal, idx+1, result / A[idx]);
		cal[3]++;
	}
	
}


int main()
{
	cin >> N;
	vector<int> calculate(4);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> calculate[i];
	}

	solution(calculate, 1, A[0]);

	cout << maxResult << endl;
	cout << minResult;
}
