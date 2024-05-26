#include <iostream>
#include <unordered_set>

using namespace std;

int main(){
  int N =0;
  int M =0;
  string tmp = "";
  int count =0;

  unordered_set<string> s;
  
  cin >> N >> M;
  for(int i=0; i<N; i++){
    cin >> tmp;
    s.insert(tmp);
  }
  for(int i=0; i<M; i++){
    cin >> tmp;
    if(s.find(tmp) != s.end()){
      count++;
    }
  }

  cout << count;
  return 0;
}