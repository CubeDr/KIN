//
// Created by HyunI on 2019-10-12.
//

#include <stdio.h>

#define DEFINE      int
#define MAIN        int main
#define READ(x)     scanf("%d", &x)
#define PRINT(x)    printf(#x" = %d\n", x)
#define BYE         return

MAIN() {
    DEFINE a, b, c;
    READ(a);
    READ(b);
    READ(c);

    PRINT(a+b - c*c);

    BYE 0;
}