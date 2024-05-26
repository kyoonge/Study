#include <iostream>
#include <vector>
#include <string>

using namespace std;

string solution(string s) {

  int count0 =0;
  int count1 =0;

  for(int i=0; i<s.size(); i++){
    if(s[i] == '0') count0++;
    else count1++;
  }

  int maxCount0 = count0/2;
  int maxCount1 = count1/2;

  string result ="";
  for(int i=0; i<s.size(); i++){
    if(s[i] == '0' && maxCount0 > 0){
      maxCount0--;
      result += '0';
    }
    else if(s[i] == '1' && maxCount1 > 0){
      maxCount1--;
    }
    else if(s[i] == '1' && maxCount1 == 0){
      result += '1';
    }
  }

  return result;
  
}

int main() {
  string s;
  cin>>s;

  string answer = solution(s);
  cout << answer << endl;
  return 0;
}
