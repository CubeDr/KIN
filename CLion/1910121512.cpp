//
// Created by HyunI on 2019-10-12.
//

#include <stdio.h>
#include <string.h>

int main() {
    char pw[100];

    while(1) {
        int number = 0; // 숫자 포함 여부
        int small = 0; // 소문자 포함 여부
        int big = 0; // 대문자 포함 여부

        printf("암호를 생성하시오:");
        scanf("%s", pw);

        for(int i=0; i<strlen(pw); i++) {
            char c = pw[i];
            if(c >= '0' && c <= '9') number = 1;
            else if(c >= 'a' && c <= 'z') small = 1;
            else if(c >= 'A' && c <= 'Z') big = 1;
        }

        // 모두 포함하면 성공
        if(number && small && big) break;
        // 하나라도 포함하지 않으면 실패
        printf("숫자, 소문자, 대문자를 섞어서 암호를 다시 만드세요!\n");
    }

    printf("정정한 암호입니다.\n");

    return 0;
}