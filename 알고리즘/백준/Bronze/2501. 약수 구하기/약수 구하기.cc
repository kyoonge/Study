#include <iostream>
using namespace std;

int solution(int& N, int& K) {
	int count = 0;
	int answer = 0;

	for (int i = 1; i <= N; i++) {
		if (N % i != 0) continue;
		count++;
		if (count == K) {
			return i;
		}
	}
	return 0;
}

int main()
{
	int N, K;

	cin >> N >> K;
	cout << solution(N, K);
}
