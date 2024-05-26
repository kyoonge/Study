#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int H = 0;
	int W = 0;
	int count = 0;

	cin >> H >> W;
	vector<vector<int>> map(H, vector<int>(W, 0));
	vector<int> input(W, 0);
	vector<int> value;

	bool start = false;
	for (int i = 0; i < W; i++) {
		cin >> input[i];
		if (input[i] != 0 || start) {
			start = true;
			value.push_back(input[i]);
		}
	}

	for (int i = 0; i < value.size()-1; i++) {

		int left = *max_element(value.begin(), value.begin() + i);
		int right = *max_element(value.begin() + 1 +i, value.end());
		int tmp = min(left, right) - value[i];
		if(tmp>0) count += tmp;
		
	}
	cout << count;
	return 0;
}