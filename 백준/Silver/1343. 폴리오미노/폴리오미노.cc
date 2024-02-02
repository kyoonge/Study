#include <iostream>
#include <vector>

using namespace std;

string printString(int count, string result){
  if(count%2 == 1) {
    cout << -1 << endl;
    return "";
  }
  int a = count /4;
  int b = (count %4) /2;

  for(int i=0; i<a; i++){
    result += "AAAA";
  }
  for(int i=0; i<b; i++){
    result += "BB";
  }

  return result;
}


int main() {

  string s;
  cin >> s;
  string result;

  int count=0;
  for (int i = 0; i < s.length(); i++){
    
    if(s[i] == '.'){
      if(count >0){
        result = printString(count, result);
        if(result == "") return 0;
        count = 0;
      }
      result += ".";
    }    
    else if(s[i]!='.'){
      count++;
      if(i == s.length()-1){
        result = printString(count, result);
        if(result == "") return 0;
      }
    }
  }
  cout << result;
  return 0;
}
