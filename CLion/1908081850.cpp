#include <iostream>
#include <fstream>

using namespace std;

// 가우스 함수
int gauss(double v) {
    if(v < 0) v--;
    return (int) v;
}

// 작성할 함수
double function(int v) {
    return (double) v * v / 4 + 1;
}

int main() {
    // result.txt 파일에 결과 출력
    ofstream file("result.txt");
    file << std::fixed;
    for(int i=1; i<=65535; i++)
        file << i << " " << function(i) << endl;
    file.close();

    return 0;
}