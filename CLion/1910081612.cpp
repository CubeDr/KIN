#include <stdio.h>

int main()
{
    // ������
    int money = 100000;

    // �Ž����� ����
    int units[] = {
        50000, 10000, 5000, 1000, 500, 100
    };

    // �Ž����� ����
    int change[6] = {0, };

    int price;
    printf("���� ����: ");
    scanf("%d", &price);

    if(price > money) {
        printf("���� �Ұ�");
        return 0;
    }

    // ���ݸ�ŭ ����
    money -= price;

    // �� ���� ���� ��� �˻�
    for(int i=0; i<6; i++) {
        // ������ �� �ش� ����� ��ȭ�� �� �ִ� ��ŭ ��ȯ
        change[i] = money / units[i];
        // ��ȯ �� ������ ���
        money %= units[i];
    }

    for(int i=0; i<6; i++)
        if(change[i])
            printf("%d���� %d��\n", units[i], change[i]);

    return 0;
}
