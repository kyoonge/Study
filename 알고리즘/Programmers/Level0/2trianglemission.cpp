#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int solution(vector<int> sides);

int main() {
  int num1, num2;

  vector<int> sides;
  sides.push_back(1);
  sides.push_back(2);

  solution(sides);
}

int solution(vector<int> sides) {
  int answer = 0;
  int test;
  sort(sides.begin(), sides.end());
  answer = 2 * sides[0] - 1;
  return answer;
}