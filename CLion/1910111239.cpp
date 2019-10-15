//
// Created by HyunI on 2019-10-11.
//

#include <stdio.h>

int main() {
    // 주차시간과 주차비용
    int min, cost = 0;
    scanf("%d", &min);

    // 30분 이하면 기본요금
    if(min <= 30) {
        cost = 1200;
    } else {
        // 1일 요금 계산
        while(min >= 60 * 24) {
            cost += 24000 * (min / (60*24));
            min %= (60*24);
        }

        // 초과 비용 계산
        if(min) {
            min -= 30;
            int extra = 1200;

            // 15분마다 600원의 추가비용
            extra += 600 * (min / 15);
            min %= 15;
            if(min) extra += 600;

            // 1일 최대 24000원
            if(extra > 24000) extra = 24000;
            cost += extra;
        }
    }

    printf("%d", cost);
    return 0;
}