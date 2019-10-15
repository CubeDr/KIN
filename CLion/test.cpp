//
// Created by HyunI on 2019-10-13.
//

#include <stdio.h>

int main() {
    // 동전 종류의 개수 (최대 100)
    int N;
    // 만들고자 하는 금액 (최대 10,000)
    int K;
    // 각 동전의 가치
    int coins[100];

    // 각 금액을 만들 수 있는 최소 동전 수
    int mem[10001];

    scanf("%d %d", &N, &K);
    for(int i=0; i<N; i++)
        scanf("%d", &coins[i]);

    // 아직은 아무것도 만들 수 없음
    for(int i=0; i<=K; i++) mem[i] = -1;
    // 0원을 만드는 최소 동전의 개수는 0개
    mem[0] = 0;

    // 0원부터 K원 까지 금액을 만들 수 있는 최소 동전 수를 구함
    for(int money=0; money<=K; money++) {
        // 모든 동전을 하나씩 써본다
        for(int i=0; i<N; i++) {
            int coin = coins[i];
            if(money < coin) continue;

            // 이전 금액을 만들 수 없으면 이 금액도 만들 수 없다
            if(mem[money - coin] == -1) continue;

            // 이 금액을 처음으로 만들 수 있거나 더 좋은 방법을 찾은 것이면
            if(mem[money] == -1 || mem[money] > mem[money - coin] + 1)
                // 최소 가지 수 갱신
                mem[money] = mem[money - coin] + 1;
        }
    }

    printf("%d", mem[K]);

    return 0;
}