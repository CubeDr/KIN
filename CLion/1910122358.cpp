//
// Created by HyunI on 2019-10-12.
//

#include <stdio.h>

void length() {
    int type, value;
    printf("어떻게 변환할까요? (1: cm->inch, 2: inch->cm)[입력]");
    scanf("%d", &type);

    if(type != 1 && type != 2) {
        printf("잘못된 입력입니다.");
        return;
    }
    printf("변환할 값을 입력하세요: [입력]");
    scanf("%d", &value);

    if(type == 1)
        printf("%d cm = %.2lf inch", value, value / 2.54);
    else
        printf("%d inch = %.2lf cm", value, value * 2.54);
}

void time() {
    int sec;
    printf("초 입력: [입력]");
    scanf("%d", &sec);
    printf("%d초는 %d분 %s초 입니다.", sec/60, sec%60);
}

void temperature() {
    int cel;
    printf("섭씨 입력: [입력]");
    scanf("%d", &cel);
    printf("섭씨 %d도는 화씨 %.2lf도 입니다.", cel, (cel * 9 / 5.0) + 32);
}

int main() {
    int type;
    printf("변환할 것은 무엇인가요? (1: 길이, 2: 시간, 3: 온도)[입력]");
    scanf("%d", &type);
    switch(type) {
        case 1: length(); break;
        case 2: time(); break;
        case 3: temperature(); break;
        default: printf("잘못된 입력입니다."); break;
    }
    return 0;
}