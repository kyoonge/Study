#include <iostream>

class MyString {
	char* string_content;  // ���ڿ� �����͸� ����Ű�� ������ (null���� ���� '����'���� ����)
	int string_length;     // ���ڿ� ����
	int memory_capacity;	// ���� �Ҵ�� �뷮

public:
	// ���� �ϳ��� ����
	MyString(char c);
	// ���ڿ��� ���� ����
	MyString(const char* str);
	// ���� ������
	MyString(const MyString& str);
	//�Ҹ���
	~MyString();

	//���ڿ� ���� ���ϴ� �Լ�
	int length() const;
	int capacity() const;
	void reserve(int size);

	//���ڿ� ���
	void print() const;
	void println() const;

	//���ڿ� �ֱ�
	MyString& assign(const MyString& str);
	MyString& assign(const char* str);

	//������ ��ġ�� ���� ����
	char at(int i) const;

	//���ڿ� �����ϱ�
	MyString& insert(int loc, const MyString& str);
	MyString& insert(int loc, const char* str);
	MyString& insert(int loc, char c);

	//���ڿ� �����
	MyString& erase(int loc, int num);

	//���ڿ� ã��
	int find(int find_from, MyString& str) const;
	int find(int find_from, const char* str) const;
	int find(int find_from, char c) const;

	//���ڿ� ��
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

	//�뷮�Ҵ�....
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