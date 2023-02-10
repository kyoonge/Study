#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

string solution(string polynomial);

int main(){
  string s = "x";
  
  cout<<solution(s);
}

string solution(string polynomial){
  vector<string> input;
  string answer ="";
  stringstream ss(polynomial);
  string st;
  int nx=0;
  int n=0;
  while(ss>>st){
    if(st.find("x")!= string::npos){
      if(st.size()>1){
        nx+=stoi(st.substr(0, st.find("x")));
      }
      else{
        nx+=1;
      }
    }
    else if(st.find("+")!= string::npos){
      continue;
    }
    else{
      n+=stoi(st);
    }
  }
  
  if(nx!=0){
    if(nx==1){
      if(n!=0){
      answer = "x + "+to_string(n);
      }
      else if(n==0){
        answer = "x";
      }
    }
    else if(n!=0){
      answer = to_string(nx)+"x"+" + "+to_string(n);
    }
    else if(n==0){
      answer = to_string(nx)+"x";
    }
  }
  else if(nx==0){
      answer = to_string(n);
  }

  return answer;
}

