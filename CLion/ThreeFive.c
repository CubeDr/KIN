//
// Created by HyunI on 2019-07-10.
//

#include <stdio.h>

int main() {
    // 1 부터 100까지 모든 숫자 검사
    for(int n=1; n<=100; n++) {
        // 3과 5의 공배수 (15의 배수)이면 숫자 출력
        if(n % 15 == 0) printf("%3d ", n);
        // 3의 배수이면 * 출력
        else if(n % 3 == 0) printf("%3c ", '*');
        // 5의 배수이면 # 출력
        else if(n % 5 == 0) printf("%3c ", '#');
        // 이외의 경우 숫자 출력
        else printf("%3d ", n);

        // 10개 단위로 개행
        if(n % 10 == 0) printf("\n");
    }
    return 0;
}