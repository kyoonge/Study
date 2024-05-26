//배열의 평균값
#include <string>
#include <vector>

using namespace std;

double solution(vector<int> numbers) {
    double answer = 0;
    
    for (int i=0;i<numbers.size();i++){
        answer+=numbers[i];
    }
    answer/=numbers.size();
    
    return answer;
}

//양꼬치
#include <string>
#include <vector>

using namespace std;

int solution(int n, int k) {
    int answer = 0;
    int service = n/10;
    
    answer = n*12000 + (k-service)*2000;
    
    return answer;
}

//중복된 숫자 개수
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int n) {
    int answer = 0;
    
    for(int i=0;i<array.size();i++){
        if( array[i] == n ){
            answer+=1;
        }
    }
    
    return answer;
}

//점의 위치 구하기
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> dot) {
    int answer = 0;
    
    if(dot[0]>0){
        if(dot[1]>0){
            answer=1;
        }
        else{
            answer=4;
        }
    }
    else{
        if(dot[1]>0){
            answer=2;
        }
        else{
            answer=3;
        }
    }
    
    return answer;
}

//배열 뒤집기
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    
    int end = num_list.size();
    int tmp;
    for (int i=0;i<end;i++){
        answer.push_back(num_list[end-i-1]);
    }
    
    return answer;
}

//머쓱이보다 키 큰 사람
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int height) {
    int answer = 0;
    
    for(int i=0;i<array.size();i++){
        if(array[i]>height){
            answer+=1;
        }
    }
    return answer;
}