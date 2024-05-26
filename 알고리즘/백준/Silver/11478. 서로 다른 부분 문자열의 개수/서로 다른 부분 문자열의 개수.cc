#include <iostream>
#include <unordered_set>

using namespace std;

int main(){
  string N ="";
  string tmp = "";

  unordered_set<string> s;
  
  cin >> N;

  for(int i=0; i< N.length(); i++){
    tmp ="";
    for(int j=i; j< N.length(); j++){
      tmp += N[j];
      s.insert(tmp);
    }
  }

  cout << s.size();
  return 0;
}