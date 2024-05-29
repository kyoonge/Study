#include <malloc.h>

class MyClass {
	//임의의 클래스
};


int main() {

	MyClass* obj = new MyClass();
	delete obj;

	MyClass* obj = (MyClass*)malloc(sizeof(MyClass));
	free(obj);
}
	//1. 메모리 할당과 해제
	//		- new로 할당, delete로 해제  
	//		- malloc으로 할당  free로 해제
	//
	//2. 생성자와 소명자
	//		- malloc은 new와는 달리 생성자, 소멸자 호출 없음
	//
	//3. 타입 안정성과 형 변환
	//		- new는 타입이 알아서 지정됨
	//		- malloc은 적절한 형변환이 필요함
	//
	//4. 예외 처리
	//		- new는 타입 안전성과 예외 처리를 지원
	//		- malloc은 void 포인터를 반환
