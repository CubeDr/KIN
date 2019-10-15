//
// Created by HyunI on 2019-10-11.
//

#include <stdio.h>

double triangle(int w, int h) {
    return w * h / 2.0;
}

double square(int l) {
    return l * l;
}

double circle(int r) {
    return 3.14 * r * r;
}

int main() {
    int a, b;

    while(1) {
        int sel;
        printf("도형의 넒이를 계산하는 프로그램입니다\n");
        printf("1.정삼각형 2.정사각형 3.원 4.종료\n");
        scanf("%d", &sel);

        switch(sel) {
            case 1:
                printf("정삼각형을 선택하셨습니다\n");
                printf("정삼각형의 변과 높이를 입력하세요\n");
                scanf("%d %d", &a, &b);
                printf("정삼각형의 넓이는 %g 입니다\n\n", triangle(a, b));
                break;
            case 2:
                printf("정사각형을 선택하셨습니다\n");
                printf("정사각형의 각 변의 크기를 입력하세요\n");
                scanf("%d", &a);
                printf("정사각형의 넓이는 %g 입니다\n\n", square(a));
                break;
            case 3:
                printf("원을 선택하셨습니다\n");
                printf("원의 반지름을 입력하세요\n");
                scanf("%d", &a);
                printf("원의 넓이는 %g 입니다\n\n", circle(a));
            case 4:
                return 0;
        }
    }
}