//
// Created by HyunI on 2019-10-11.
//

#include <stdio.h>

int main() {
    int height, weight;
    printf("키 :");
    scanf("%d", &height);
    printf("몸무게 :");
    scanf("%d", &weight);
    if(weight+100-height > 0) printf("비만\n");
    else printf("정상\n");
    return 0;
}