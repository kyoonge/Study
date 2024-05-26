#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> v, int n, int k) {

  vector<int> dist(v.size()-1,0);

  sort(v.begin(), v.end());

  for(int i=1; i<n; i++) {
    dist[i-1] = v[i] - v[i-1];
  }

  sort(dist.begin(), dist.end());

  int answer =0;
  for(int i=0; i<n-k; i++) {
    answer += dist[i];
  }

  return answer;

}


int main() {

  int N, K;
  cin >> N >> K;

  vector<int> v(N);
  for (int i = 0; i < N; i++){
    cin >> v[i];
  }

  int a = solution(v, N, K);
  cout << a;
}