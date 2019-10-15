//
// Created by HyunI on 2019-10-01.
//

#include <iostream>
#include <cstring>

using namespace std;

class String {
private:
    char *str;
    int len;
public:
    String() {
        len = 0;
        str = new char[0]; // 할당해주어야 함
    }

    ~String() {
        delete[] str;
    }

    String(const char *p) {
        len = strlen(p); // 문자열의 길이 자체는 널문자 빼고
        str = new char[len + 1];
        strcpy(str, p);
    }

    void copy(const String& other) {
        // 원래 할당된 문자열 삭제
        delete[] str;

        // 새로 할당
        len = other.len;
        str = new char[len+1];

        // 문자열 복사
        strcpy(str, other.str);
    }

    void add(const String& other) {
        // 문자열 길이 갱신
        len += other.len;

        // 두 문자열을 이어붙인 문자열 생성
        char* added = new char[len + 1];
        strcpy(added, str);
        strcat(added, other.str);

        // 기존 문자열을 생성한 문자열로 대체
        delete[] str;
        str = added;
    }

    void print() {
        cout << str;
    }
};

int main() {
    String s1;
    String s2("Hello");
    String s3("world");
    s1.copy(s2);  // s1의 내용이 Hello가 된다.
    s1.add(s3);   // Helloworld가 된다.
    s1.print();   // 출력을 한다.
}