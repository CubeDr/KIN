//
// Created by HyunI on 2019-07-10.
//

#include <stdio.h>

// �޴��� ����ϰ� ����ڰ� ������ �޴��� ��ȯ�ϴ� �Լ�
int menu() {
    // �޴� ���
    printf("======= ������ ======\n");
    printf("1. ������ ��� ���\n");
    printf("2. ���ϴ� ������ ���\n");
    printf("3. ����\n");

    // ����ڰ� �޴� ���� (1, 2, 3�� ����)
    int sel = 0;
    while(sel < 1 || sel > 3) {
        printf("> ");
        scanf("%d", &sel);
    }
    return sel;
}

// �������� ����ϴ� �Լ�
// base[]: ����ϰ��� �ϴ� ��
// len: base �迭�� ����
// base�� ����ִ� ���� ���η� �����
// base = [1, 2, 3] �̸�
// 1�� 2�� 3��
// 1*1=1 2*1=2 3*1=3
// 1*2=2 2*2=4 3*2=6
// �� ���� ���
void printGugu(int base[], int len) {
    // �� ������ ���� ���
    for(int i=0; i<len; i++)
        printf("%2d%-2s\t", base[i], "��");
    printf("\n");
    // �� �� ���
    for(int m=1; m<=9; m++) {
        for(int i=0; i<len; i++)
            printf("%d*%d=%2d\t", base[i], m, base[i]*m);
        printf("\n");
    }
}

int main() {
    // ���� ���� ����
    int isRunning = 1;
    while(isRunning) {
        // �޴��� �Է¹޾� �ش� ��� ����
        switch(menu()) {
            case 1:
                // 1�ܺ��� 9�ܱ��� 3���� ���� ������ ���
                // printGugu() �Լ��� ������ ���� ȣ��
                // [1, 2, 3]
                // [4, 5, 6]
                // [7, 8, 9]
                // �� ���� �����Ͽ� 3���� �ܾ� ���
                printf("��ü ���\n");
                for(int i=0; i<3; i++) {
                    int base[3];
                    for(int j=0; j<3; j++)
                        base[j] = i*3 + j + 1;
                    printGugu(base, 3);
                }
                break;
            case 2: {
                // ����ϰ��� �ϴ� ���� �Է¹޾� printGugu() �Լ� ȣ��
                int gugu;
                printf("����� ������ �Է�: ");
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
    printf("����\n");
    return 0;
}