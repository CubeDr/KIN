//
// Created by HyunI on 2019-07-11.
//
#include <stdio.h>

int indexOfChar(char str[], char c) {
    int index = -1;

    while(index == -1 && // 아직 못찾았고
        str[index] != '\0' && // 문자열이 끝나지 않았고
        str[index] != c) // 원하는 문자가 아니면
        index++; // 계속 찾음

    return index;
}

int main() {
    char str[1000];
    char c;
    printf("# 문자열을 입력하시오 : ");
    scanf("%s", str); fflush(stdin);
    printf("# 문자를 입력하시오 : ");
    scanf("%c", &c);

    int index = indexOfChar(str, c);
    printf("\"%s\"문자열 안에 \'%c\'문자는 ", str, c);
    if(index == -1) printf("존재하지 않습니다.\n");
    else printf("%d번 위치에 존재합니다.\n", index);
    return 0;
}