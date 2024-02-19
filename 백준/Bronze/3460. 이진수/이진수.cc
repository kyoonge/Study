#include <iostream>
using namespace std;

int solution(int n) {
	int cur = 0;
	int curNum = 0;

	while (true) {
		
		curNum = n%2;
		n /= 2;
		if (curNum == 1) cout << cur << " ";
		if (n == 0) break;
		cur++;
	}

	return 0;
}

int main()
{
	int T, N;

	cin >> T;


	for (int i = 0; i < T; i++)
	{
		cin >> N;
		solution(N);
	}
}
