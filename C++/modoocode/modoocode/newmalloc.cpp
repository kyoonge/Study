#include <malloc.h>

class MyClass {
	//������ Ŭ����
};


int main() {

	MyClass* obj = new MyClass();
	delete obj;

	MyClass* obj = (MyClass*)malloc(sizeof(MyClass));
	free(obj);
}
	//1. �޸� �Ҵ�� ����
	//		- new�� �Ҵ�, delete�� ����  
	//		- malloc���� �Ҵ�  free�� ����
	//
	//2. �����ڿ� �Ҹ���
	//		- malloc�� new�ʹ� �޸� ������, �Ҹ��� ȣ�� ����
	//
	//3. Ÿ�� �������� �� ��ȯ
	//		- new�� Ÿ���� �˾Ƽ� ������
	//		- malloc�� ������ ����ȯ�� �ʿ���
	//
	//4. ���� ó��
	//		- new�� Ÿ�� �������� ���� ó���� ����
	//		- malloc�� void �����͸� ��ȯ
