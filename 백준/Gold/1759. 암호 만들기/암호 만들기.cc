#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

unordered_set<char> s{ 'a', 'e', 'i','o','u' };


void dfs(int idx, int vowelNum, string str, vector<char> v, int limit)
{
    str.push_back(v[idx]);
    
    if (s.find(v[idx]) != s.end()) vowelNum++;

    if (str.length() == limit) {
        if (vowelNum >= 1 && limit - vowelNum >= 2)
            cout << str << '\n';
        return;
    }

    for (int i = idx + 1; i < v.size(); i++)
        dfs(i, vowelNum, str, v, limit);
    return;
}


int main() 
{
    int L = 0;
    int C = 0;
    cin >> L >> C;
    vector<char> c(C, ' ');

    for (int i = 0; i < C; i++) {
        std::cin >> c[i];
    }
    sort(c.begin(), c.end());

    for (int i = 0; i <= C - L; i++) {
        dfs(i, 0, "", c, L);
    }

	return 0;
}

