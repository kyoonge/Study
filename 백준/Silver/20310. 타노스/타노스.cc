#include <iostream>
#include <vector>
#include <string>

using namespace std;

string solution(string s) {

  int count0 =0;
  int count1 =0;
  int idx1 =0;
  int idx0 =s.size()-1;

  for(int i=0; i<s.size(); i++){
    if(s[i] == '0') count0++;
    else count1++;
  }

  int maxCount0 = count0/2;
  int maxCount1 = count1/2;
  
  while(count0 > maxCount0 || count1 > maxCount1){
    
    if(s[idx1] == '1'&&count1>maxCount1) {
      s=s.substr(0,idx1)+s.substr(idx1+1);
      count1--;
    } 
    else if(s[idx0] == '0'&&count0>maxCount0) {
      s=s.substr(0,idx0)+s.substr(idx0+1);
      count0--;
    } 

    idx0--;
    idx1++;
  }

  return s;
  
}

int main() {
  string s;
  cin>>s;

  string answer = solution(s);
  cout << answer << endl;
  return 0;
}
