//
// Created by HyunI on 2019-10-13.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 0 ~ 100 의 난수를 생성하는 함수
int myRand() {
    return rand() % 101;
}

// 현재까지 구한 평균과 반복 횟수
int rec(double avg, int count) {
    // 지금까지 구한 평균이 조건을 충족시키면 반복 횟수 반환
    if(avg > 49 && avg < 51) return count;

    // 새로운 난수 생성 후 평균 구하기
    avg = (avg * count + myRand()) / (count + 1);

    // 새로 생성한 데이터로 반복
    return rec(avg, count + 1);
}

int main() {
    srand(time(NULL));

    // 반복 0회, 평균 0으로 시작하여 반복 횟수 구하기
    int count = rec(0, 0);
    printf("난수 %d회 생성", count);
    return 0;
}