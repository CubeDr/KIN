//
// Created by HyunI on 2019-10-11.
//

#include <stdio.h>

#define WORK_START 9 // �ٹ� ���۽ð�
#define WORK_END 22 // �ٹ� ����ð�
#define LUNCH_START 12 // ���ɽð� ���۽ð�
#define LUNCH_END 13 // ���ɽð� ����ð�
#define OVER_START 18 // ����ٹ� ���� �ð�

typedef struct _WorkHour {
    int start;
    int end;
} WorkHour;

int regular(const WorkHour *w) {
    int start = w->start;
    int end = w->end;

    // ����ٹ� ����
    if(start >= OVER_START) return 0;
    if(end > OVER_START) end = OVER_START;

    // ���ɽð� ����
    if(start <= LUNCH_START && end >= LUNCH_END) end--;
    return end - start;
}

int over(const WorkHour *w) {
    int start = w->start;
    int end = w->end;

    // ����ٹ� ����
    if(end <= OVER_START) return 0;
    if(start < OVER_START) start = OVER_START;

    // 2�ð� �̻� ����ٹ� �� ����ð� ����
    if(end - start >= 2) end--;

    return end - start;
}

const char *days[] = {
        "��", "ȭ", "��", "��", "��"
};

/* ===== ���� �Է� �Լ� ===== */
// �����͸� �޴� ������ �ʿ��� �Է�
int queryFunctionInRange(void (*query)(const WorkHour[]),
        const WorkHour ws[], int min, int max, const char *error) {
    int sel = min;
    query(ws);
    do {
        if (sel != min && error != NULL)
            printf("%s\n", error);
        scanf("%d", &sel);
    } while (sel < min || sel > max);
    return sel;
}

// �����Ͱ� �ʿ���� ������ �ʿ��� �Է�
int queryPrintInRange(void (*query)(), int min, int max, const char *error) {
    int sel = min;
    query();
    do {
        if (sel != min && error != NULL)
            printf("%s\n", error);
        scanf("%d", &sel);
    } while (sel < min || sel > max);
    return sel;
}

// ������ ������ �ϴ� �Է�
int queryInRange(const char *query, int min, int max, const char *error) {
    int sel = min;
    printf("%s\n", query);
    do {
        if (sel != min && error != NULL)
            printf("%s\n", error);
        scanf("%d", &sel);
    } while(sel < min || sel > max);
    return sel;
}

/* ===== �޴� ===== */
// �޴� ��� �Լ�
void printMenu(const WorkHour ws[]) {
    printf("----------------------\n");
    for (int i = 0; i < 5; i++)
        printf("[%s](���) %2d�� (���) %2d��\n",
               days[i], ws[i].start, ws[i].end);
    printf("\n");
    printf("1. �ٹ��ð� ����\n");
    printf("2. �ִ� �� �ٹ��ð� ��Ȳǥ\n");
    printf("3. ����\n");
    printf("----------------------\n");
}

// �޴� �Է� �Լ�
int menu(const WorkHour ws[]) {
    return queryFunctionInRange(printMenu, ws, 1, 3, NULL);
}

/* ===== 1. �ٹ��ð� ���� ===== */
// �޴� ��� �Լ�
void printChangeHourMenu() {
    for (int i = 0; i < 5; i++)
        printf("%d-%s, ", i + 1, days[i]);
    printf("6-��� ���ϴ� ���ڸ� �Է��ϼ���.\n");
}

// �ٹ��ð� ���� �Լ�
void changeHour(WorkHour ws[]) {
    int day = queryPrintInRange(printChangeHourMenu, 1, 6,
            "1���� 6���� ���ϴ� ���ڸ� �Է��ϼ���.");
    if(day-- == 6) return;
    int start = queryInRange("��ٽð��� �Է����ּ���.", WORK_START, WORK_END,
                             "�ٹ��ð��� 9��~22�ñ��� �Է��� �� �ֽ��ϴ�.");
    int end = queryInRange("��ٽð��� �Է����ּ���.", WORK_START, WORK_END,
                           "�ٹ��ð��� 9��~22�ñ��� �Է��� �� �ֽ��ϴ�.");

    if(end < start) {
        printf("��ٽð��� ��ٽð����� �̸� �� �����ϴ�.");
    } else {
        ws[day].start = start;
        ws[day].end = end;
    }
}

/* ===== 2. �ִ� �� �ٹ��ð� ��Ȳǥ ===== */
void chart(const WorkHour ws[]) {
    int r=0;
    int o=0;
    for(int i=0; i<5; i++) {
        r += regular(&ws[i]);
        o += over(&ws[i]);
    }

    printf("***** �ִ� �� �ٹ��ð� ��Ȳǥ *****\n");
    printf("�ѱٹ��ð�: %d�ð�\n", r + o);
    printf("����ٹ��ð�: %d�ð�\n", r);
    printf("����ٹ��ð�: %d�ð�\n", o);
}

int main() {
    WorkHour workHours[5];

    // �⺻ ����ٽð�
    for (int i = 0; i < 5; i++) {
        workHours[i].start = WORK_START;
        workHours[i].end = OVER_START;
    }

    int sel = 0;
    while ((sel = menu(workHours)) != 3) {
        switch (sel) {
            case 1: changeHour(workHours); break;
            case 2: chart(workHours); break;
            default: printf("Unreachable"); break;
        }
    }
    return 0;
}