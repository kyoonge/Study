#include <iostream>

class MyString {
	char* string_content;  // 문자열 데이터를 가리키는 포인터 (null제외 실제 '문자'만을 저장)
	int string_length;     // 문자열 길이
	int memory_capacity;	// 현재 할당된 용량

public:
	// 문자 하나로 생성
	MyString(char c);
	// 문자열로 부터 생성
	MyString(const char* str);
	// 복사 생성자
	MyString(const MyString& str);
	//소멸자
	~MyString();

	//문자열 길이 구하는 함수
	int length() const;
	int capacity() const;
	void reserve(int size);

	//문자열 출력
	void print() const;
	void println() const;

	//문자열 넣기
	MyString& assign(const MyString& str);
	MyString& assign(const char* str);

	//임의의 위치의 문자 리턴
	char at(int i) const;

	//문자열 삽입하기
	MyString& insert(int loc, const MyString& str);
	MyString& insert(int loc, const char* str);
	MyString& insert(int loc, char c);

	//문자열 지우기
	MyString& erase(int loc, int num);

	//문자열 찾기
	int find(int find_from, MyString& str) const;
	int find(int find_from, const char* str) const;
	int find(int find_from, char c) const;

	//문자열 비교
	int compare(const MyString& str) const;
};

MyString::MyString(char c) {
	string_content = new char[1];
	string_content[0] = c;
	string_length = 1;
	memory_capacity = 1;
}

MyString::MyString(const char* str) {
	string_length = strlen(str);
	string_content = new char[string_length];
	for (int i = 0; i < string_length; i++) {
		string_content[i] = str[i];
	}
	memory_capacity = string_length;
	//strncpy(string_content, str, string_length);
}

MyString::MyString(const MyString& str) {
	string_length = str.string_length;
	string_content = new char[string_length];
	memory_capacity = string_length;
	for (int i = 0; i < string_length; i++) {
		string_content[i] = str.string_content[i];
	}
}

MyString::~MyString() {
	delete[] string_content;
}

int MyString::length() const {
	return string_length;
}

int MyString::capacity() const {
	return memory_capacity;
}

void MyString::reserve(int size) {
	if (size > memory_capacity) {
		char* prev_string_content = string_content;

		string_content = new char[size];
		memory_capacity = size;

		for (int i = 0; i != string_length; i++)
			string_content[i] = prev_string_content[i];

		delete[] prev_string_content;
	}
}

void MyString::print() const {
	for (int i = 0; i < string_length; i++) {
		std::cout << string_content[i];
	}
}

void MyString::println() const {
	for (int i = 0; i < string_length; i++) {
		std::cout << string_content[i];
	}
	std::cout << std::endl;
}

MyString& MyString::assign(const MyString& str) {
	if (str.string_length > memory_capacity) {
		delete[] string_content;
		string_content = new char[str.string_length];
		memory_capacity = str.string_length;
	}
	for (int i = 0; i < str.string_length; i++) {
		string_content[i] = str.string_content[i];
	}
	string_length = str.string_length;

	return *this;
}

MyString& MyString::assign(const char* str) {
	int str_length = strlen(str);

	if (str_length > memory_capacity) {
		delete[] string_content;
		string_content = new char[str_length];
		memory_capacity = str_length;
	}

	for (int i = 0; i < str_length; i++) {
		string_content[i] = str[i];
	}
	string_length = str_length;

	return *this;
}

char MyString::at(int i) const {
	if (i > string_length || i < 0) {
		return NULL;
	}
	else
		return string_content[i];
}

MyString& MyString::insert(int loc, const MyString& str) {
	if (loc < 0 || loc > string_length) {
		return *this;
	}

	//용량할당....
	if (string_length + str.string_length > memory_capacity) {
		char* string_tmp = string_content;

		if (memory_capacity * 2 > string_length + str.string_length)
			memory_capacity *= 2;
		else
			memory_capacity = string_length + str.string_length;

		string_content = new char[memory_capacity];

		int j = 0;
		int k = 0;
		for (int i = 0; i < string_length + str.string_length; i++) {
			if (loc <= i && i < loc + str.string_length) {
				string_content[i] = str.string_content[j];
				j++;
			}
			else {
				string_content[i] = string_tmp[k];
				k++;
			}
		}
		delete[] string_tmp;
	}

	else {
		for (int i = string_length - 1; i >= loc; i--) {
			string_content[i + str.string_length] = string_content[i];
		}
		for (int i = 0; i < str.string_length; i++)
			string_content[i + loc] = str.string_content[i];
	}
	string_length = string_length + str.string_length;
	return *this;

}

MyString& MyString::insert(int loc, const char* str) {
	MyString tmp(str);
	return insert(loc, tmp);;
}

MyString& MyString::insert(int loc, char c) {
	MyString tmp(c);
	return insert(loc, tmp);
}

MyString& MyString::erase(int loc, int num) {
	if (loc < 0 || num <0 || loc>string_length) return *this;

	for (int i = loc + num; i < string_length; i++) {
		string_content[i - num] = string_content[i];
	}

	string_length -= num;
	return *this;
}

int MyString::find(int find_from, MyString& str) const {
	if (str.string_length == 0) return -1;

	int i, j;
	for (i = find_from; i <= string_length - str.string_length; i++) {
		for (j = 0; j < str.string_length; j++) {
			if (string_content[i + j] != str.string_content[j]) break;
		}

		if (j == str.string_length) return i;
	}

	return -1;
}

int MyString::find(int find_from, const char* str) const {
	MyString temp(str);
	return find(find_from, temp);
}

int MyString::find(int find_from, char c) const {
	MyString temp(c);
	return find(find_from, temp);
}

int MyString::compare(const MyString& str) const {
	int limit = std::min(string_length, str.string_length);

	for (int i = 0; i < limit; i++) {
		if (string_content[i] > str.string_content[i])
			return 1;

		else if (string_content[i] < str.string_content[i])
			return -1;
	}

	if (string_length == str.string_length) {
		return 0;
	}
	else if (string_length > str.string_length) {
		return 1;
	}

	return -1;
}