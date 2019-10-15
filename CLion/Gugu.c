//
// Created by HyunI on 2019-07-10.
//

#include <stdio.h>

// 메뉴를 출력하고 사용자가 선택한 메뉴를 반환하는 함수
int menu() {
    // 메뉴 출력
    printf("======= 구구단 ======\n");
    printf("1. 구구단 모두 출력\n");
    printf("2. 원하는 구구단 출력\n");
    printf("3. 종료\n");

    // 사용자가 메뉴 선택 (1, 2, 3만 가능)
    int sel = 0;
    while(sel < 1 || sel > 3) {
        printf("> ");
        scanf("%d", &sel);
    }
    return sel;
}

// 구구단을 출력하는 함수
// base[]: 출력하고자 하는 단
// len: base 배열의 길이
// base에 들어있는 단을 가로로 출력함
// base = [1, 2, 3] 이면
// 1단 2단 3단
// 1*1=1 2*1=2 3*1=3
// 1*2=2 2*2=4 3*2=6
// 과 같이 출력
void printGugu(int base[], int len) {
    // 몇 단인지 제목 출력
    for(int i=0; i<len; i++)
        printf("%2d%-2s\t", base[i], "단");
    printf("\n");
    // 각 단 출력
    for(int m=1; m<=9; m++) {
        for(int i=0; i<len; i++)
            printf("%d*%d=%2d\t", base[i], m, base[i]*m);
        printf("\n");
    }
}

int main() {
    // 무한 루프 조건
    int isRunning = 1;
    while(isRunning) {
        // 메뉴를 입력받아 해당 기능 수행
        switch(menu()) {
            case 1:
                // 1단부터 9단까지 3개씩 나눠 구구단 출력
                // printGugu() 함수를 세번에 걸쳐 호출
                // [1, 2, 3]
                // [4, 5, 6]
                // [7, 8, 9]
                // 와 같이 전달하여 3개의 단씩 출력
                printf("전체 출력\n");
                for(int i=0; i<3; i++) {
                    int base[3];
                    for(int j=0; j<3; j++)
                        base[j] = i*3 + j + 1;
                    printGugu(base, 3);
                }
                break;
            case 2: {
                // 출력하고자 하는 단을 입력받아 printGugu() 함수 호출
                int gugu;
                printf("출력할 구구단 입력: ");
                scanf("%d", &gugu);
                printGugu((int[]){gugu}, 1);
                break;
            }
            case 3:
                isRunning = 0;
                break;
        }
        printf("\n");
    }
    printf("종료\n");
    return 0;
}