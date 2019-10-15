//
// Created by HyunI on 2019-10-12.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// string을 int로 변환해주는 함수
bool parseInt(const string& str, int& result) {
    int num = 0;
    for(char c: str) {
        if(c < '0' || c > '9') return false;

        num *= 10;
        num += c - '0';
    }
    result = num;
    return true;
}

vector<int> readIntsFromFile(const string& filename) {
    ifstream in(filename);

    // 파일에서 읽은 숫자들을 저장할 변수
    vector<int> numbers;

    // 파일의 각 문자열을 담을 변수
    string tok;
    // 각 문자열을 숫자로 변환한 결과를 담을 변수
    int num;
    // 파일의 모든 문자열을 공백 단위로 읽어옴
    while(in >> tok) {
        // 숫자로 변환
        if(parseInt(tok, num))
            // 변환한 숫자를 저장
            numbers.push_back(num);
    }
    // 파일 읽기 종료
    in.close();

    return numbers;
}

int main() {
    // "input.txt" 파일에서 숫자만 뽑아오기
    vector<int> numbers = readIntsFromFile("input.txt");
    // 뽑아온 결과 출력
    for(int v: numbers)
        cout << v << " ";
    return 0;
}