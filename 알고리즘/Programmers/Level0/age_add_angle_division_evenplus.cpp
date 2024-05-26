//나이 출력
#include <string>
#include <vector>

using namespace std;

int solution(int age) {
    int answer = 0;
    
    answer = 2023-age;
    return answer;
}

//두 수의 합
#include <string>
#include <vector>

using namespace std;

int solution(int num1, int num2) {
    int answer = num1+num2;
    return answer;
}

//각도기
#include <string>
#include <vector>

using namespace std;

int solution(int angle) {
    int answer = 0;
    
    if(angle>0 && angle<90){
        answer = 1;
    }
    else if(angle==90){
        answer =2;
    }
    else if(angle>90 && angle<180)
    {
        answer =3;
    }
    else if(angle ==180)
    {
        answer=4;
    }
    return answer;
}

//두 수의 나눗셈
#include <string>
#include <vector>

using namespace std;

int solution(int num1, int num2) {
    int answer = 0;
    
    answer = num1*1000/num2;
    
    return answer;
}

//짝수의 합
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for (int i=1;i<=n;i++){
        if(i%2==0){
            answer+=i;
        }
    }
    return answer;
}