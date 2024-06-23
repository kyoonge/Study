#include "MyString.h"


void DoSomethingWithString(MyString s) {

}

int main() {
	MyString str("abcdef");
	str[3] = 'c';

	str.println();
}