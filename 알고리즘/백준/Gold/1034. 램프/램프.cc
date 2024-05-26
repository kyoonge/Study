#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int n, m, k, answer = 0;
int main() {
  cin >> n >> m;
  unordered_map<string, pair<int, int>> ma;
  
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    ma[str].first++;
    if (ma[str].second == 0) {
      int cnt = 0;
      for (int j = 0; j < str.length(); j++) {
        if (str[j] == '0')
          cnt++;
      }
      ma[str].second = cnt;
    }
  }
  cin >> k;

  for (auto o : ma) {
    int cnt = o.second.second;
    if (cnt <=k && cnt %2 == k%2) {
      answer = max(answer, o.second.first);
    }
  }

  cout << answer;
  return 0;
}