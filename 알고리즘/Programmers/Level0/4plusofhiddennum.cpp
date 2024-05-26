#include <iostream>
#include <string>
#include <vector>

using namespace std;
int solution(string my_string);

int main() {
  string string = "aAb1B2cC34oOp";
  cout<<solution(string);
}

int solution(string my_string){
  int answer =0;
  long result=0;
  int my_stringtoInt =0;
  string buf="";
  for(int i=0; i<my_string.size(); i++){
    my_stringtoInt = (int)my_string[i] - '0';
    while(my_stringtoInt>=0 && my_stringtoInt<=9){
      
      buf += my_string[i];
      i++;
      if(i>=my_string.size()){break;}
      my_stringtoInt = (int)my_string[i] - '0';
    }
    if(buf.size()!=0){
    answer+=stoi(buf);  
    }
    buf = "";
  }
  return answer;
}