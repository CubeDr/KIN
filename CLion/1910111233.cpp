//
// Created by HyunI on 2019-10-11.
//

#include<stdio.h>

int main(void) {
    int i = 0, k = 0, t = 0, h = 0;
    scanf("%d", &k);
    for (i = 0; i < k; i++) {
        for (t = 0; t < 10; t++) {
            printf("%2d", (t + i) % 10);
        }
        printf("\n");
    }
    return 0;
}