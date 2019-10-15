//
// Created by HyunI on 2019-10-12.
//

#include <stdio.h>

int main() {
    int k;
    char c;
    scanf("%d %c", &k, &c);

    // 대문자
    if(c <= 'Z') c = (c - 'A' + k) % ('Z' - 'A' + 1) + 'A';
    // 소문자
    else c = (c - 'a' + k) % ('Z' - 'A' + 1) + 'a';

    printf("%c\n", c);
    return 0;
}