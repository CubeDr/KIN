//
// Created by HyunI on 2019-10-12.
//

#include <stdio.h>

int main() {
    int ctr;

    printf("정수를 입력하시오: ");
    scanf("%d", &ctr);

    do {
        if(ctr%3 == 0) printf(" X");
        else printf(" %d", ctr);
        ctr--;
    } while(ctr != 0);
    printf(" %d", ctr);

    return 0;
}