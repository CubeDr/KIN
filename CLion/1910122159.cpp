//
// Created by HyunI on 2019-10-12.
//

#include <stdio.h>

int main() {
    int n;
    // 두 플레이어의 수
    int p1=0, p2=0;

    // 반복 횟수 입력
    scanf("%d", &n);
    // n번 만큼 반복
    while(n--) {
        // 주사위의 수
        int a, b;
        scanf("%d %d", &a, &b);

        // 홀수면 빼고 짝수면 더하기
        if(a%2) p1 -= a;
        else p1 += a;
        if(b%2) p2 -= b;
        else p2 += b;
    }

    printf("p1: %d, p2: %d\n", p1, p2);

    if(p1 > p2) printf("Player1 Win!\n");
    else if(p1 == p2) printf("Same\n");
    else printf("Player2 Win!\n");

    return 0;
}