//
// Created by HyunI on 2019-10-12.
//

#include <stdio.h>

int main() {
    int n;

    while(1) {
        printf("정수를 입력하세요 :");
        scanf("%d", &n);

        // 0이하 입력 시 프로그램 종료
        if(n <= 0) break;

        // n개의 줄 출력
        for(int i=1; i<=n; i++) {
            // i번째 줄에는 별을 i개 출력
            for(int j=0; j<i; j++)
                printf("*");
            printf("\n");
        }
    }

    return 0;
}