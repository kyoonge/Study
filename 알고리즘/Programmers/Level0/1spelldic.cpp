#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(vector<string> spell, vector<string> dic);

int main() {
  vector<string> spell;
  vector<string> dic;

  spell.push_back("p");
  spell.push_back("o");
  spell.push_back("s");
  dic.push_back("sod");
  dic.push_back("eocd");
  dic.push_back("qixm");
  dic.push_back("adio");
  dic.push_back("soo");
  dic.push_back("no");
  dic.pop_back();

  cout << solution(spell,dic);
}

int solution(vector<string> spell, vector<string> dic){
  int answer = 0;
  int count = 0;

  for(int i=0;i<dic.size();i++){
    for(int j=0;j<spell.size();j++){
      if(dic[i].find(spell[j]) != string::npos){
        count++;
      }
    }
    if(count==spell.size()){
      answer = 1;
      return answer;
    }
    count = 0;
  }
  answer = 2;
  return answer;
}