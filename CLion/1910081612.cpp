#include <stdio.h>

int main()
{
    // 소지금
    int money = 100000;

    // 거스름돈 단위
    int units[] = {
        50000, 10000, 5000, 1000, 500, 100
    };

    // 거스름돈 개수
    int change[6] = {0, };

    int price;
    printf("물건 가격: ");
    scanf("%d", &price);

    if(price > money) {
        printf("구매 불가");
        return 0;
    }

    // 가격만큼 차감
    money -= price;

    // 각 지폐 단위 모두 검사
    for(int i=0; i<6; i++) {
        // 소지금 중 해당 지폐로 전화될 수 있는 만큼 전환
        change[i] = money / units[i];
        // 전환 후 나머지 계산
        money %= units[i];
    }

    for(int i=0; i<6; i++)
        if(change[i])
            printf("%d원권 %d장\n", units[i], change[i]);

    return 0;
}
