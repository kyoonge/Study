#pragma once

class MyString {
    char* string_content;  // 문자열 데이터를 가리키는 포인터 (null제외 실제 '문자'만을 저장)
    int string_length;     // 문자열 길이
    int memory_capacity;    // 현재 할당된 용량

public:

    MyString(char c);       // 문자 하나로 생성
    MyString(const char* str);    // 문자열로 부터 생성
    explicit MyString(int capacity);  // capacity만큼 미리 할당함
    MyString(const MyString& str);      // 복사 생성자
    ~MyString();        //소멸자

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