#include <iostream>
#include <vector>
#include <cmath>
#include <string.h>

using namespace std;
int dp[101][100001];

int main() {

    int n, k = 0;

    memset(dp, 0, sizeof(dp));

    cin >> n >> k;
    vector<vector<int>> objs(n + 1, vector<int>(2));

    for (int i = 1; i <= n; i++) {
        cin >> objs[i][0] >> objs[i][1];
    }


    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            //담은 수 없음
            if (objs[j][0] > i) dp[j][i] = dp[j - 1][i];
            //담을 수 있음
            else {
                dp[j][i] = max(dp[j - 1][i], dp[j - 1][i - objs[j][0]] + objs[j][1]);
            }
        }
    }

    cout << dp[n][k];
    return 0;
}