#pragma once

class MyString {
    char* string_content;  // ���ڿ� �����͸� ����Ű�� ������ (null���� ���� '����'���� ����)
    int string_length;     // ���ڿ� ����
    int memory_capacity;    // ���� �Ҵ�� �뷮

public:

    MyString(char c);       // ���� �ϳ��� ����
    MyString(const char* str);    // ���ڿ��� ���� ����
    explicit MyString(int capacity);  // capacity��ŭ �̸� �Ҵ���
    MyString(const MyString& str);      // ���� ������
    ~MyString();        //�Ҹ���

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