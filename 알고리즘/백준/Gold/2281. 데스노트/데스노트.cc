#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
int Name[1001];
int dp[1001][1001];

int DP(int name, int len) {
	if (name >= n)
		return 0;
	int& res = dp[name][len];

	if (res != -1) {
		return dp[name][len];
	}

	res = (m - len + 1) * (m - len + 1) + DP(name + 1, Name[name] + 1);

	if (len + Name[name] <= m)
		res = min(res, DP(name + 1, len + Name[name] + 1));
	return res;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> Name[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << DP(0, 0) << '\n';
	return 0;
}