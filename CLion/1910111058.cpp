//
// Created by HyunI on 2019-10-11.
//

#include <stdio.h>

int main() {
    char str1[100] = "Hello ";
    char str2[100] = "World!";

    // str1의 마지막 위치 찾기
    char *ptr1 = str1;
    while(*ptr1 != '\0') ptr1++;

    // 복사할 str2의 위치
    char *ptr2 = str2;

    // str2의 마지막에 도달할 때 까지 복사
    while(*ptr2 != '\0') {
        *ptr1 = *ptr2;
        ptr1++;
        ptr2++;
    }
    // 문자열의 끝 삽입
    *ptr1 = '\0';

    printf("%s", str1);

    return 0;
}