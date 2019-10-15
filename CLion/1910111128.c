//
// Created by HyunI on 2019-10-11.
//

#include <stdio.h>

#define WORK_START 9 // 근무 시작시간
#define WORK_END 22 // 근무 종료시간
#define LUNCH_START 12 // 점심시간 시작시간
#define LUNCH_END 13 // 점심시간 종료시간
#define OVER_START 18 // 연장근무 시작 시간

typedef struct _WorkHour {
    int start;
    int end;
} WorkHour;

int regular(const WorkHour *w) {
    int start = w->start;
    int end = w->end;

    // 연장근무 제외
    if(start >= OVER_START) return 0;
    if(end > OVER_START) end = OVER_START;

    // 점심시간 제외
    if(start <= LUNCH_START && end >= LUNCH_END) end--;
    return end - start;
}

int over(const WorkHour *w) {
    int start = w->start;
    int end = w->end;

    // 정상근무 제외
    if(end <= OVER_START) return 0;
    if(start < OVER_START) start = OVER_START;

    // 2시간 이상 연장근무 시 저녁시간 제외
    if(end - start >= 2) end--;

    return end - start;
}

const char *days[] = {
        "월", "화", "수", "목", "금"
};

/* ===== 범위 입력 함수 ===== */
// 데이터를 받는 질문이 필요한 입력
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

// 데이터가 필요없는 질문이 필요한 입력
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

// 간단한 질문만 하는 입력
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

/* ===== 메뉴 ===== */
// 메뉴 출력 함수
void printMenu(const WorkHour ws[]) {
    printf("----------------------\n");
    for (int i = 0; i < 5; i++)
        printf("[%s](출근) %2d시 (퇴근) %2d시\n",
               days[i], ws[i].start, ws[i].end);
    printf("\n");
    printf("1. 근무시간 변경\n");
    printf("2. 주당 총 근무시간 현황표\n");
    printf("3. 종료\n");
    printf("----------------------\n");
}

// 메뉴 입력 함수
int menu(const WorkHour ws[]) {
    return queryFunctionInRange(printMenu, ws, 1, 3, NULL);
}

/* ===== 1. 근무시간 변경 ===== */
// 메뉴 출력 함수
void printChangeHourMenu() {
    for (int i = 0; i < 5; i++)
        printf("%d-%s, ", i + 1, days[i]);
    printf("6-취소 원하는 숫자를 입력하세요.\n");
}

// 근무시간 변경 함수
void changeHour(WorkHour ws[]) {
    int day = queryPrintInRange(printChangeHourMenu, 1, 6,
            "1부터 6까지 원하는 숫자를 입력하세요.");
    if(day-- == 6) return;
    int start = queryInRange("출근시간을 입력해주세요.", WORK_START, WORK_END,
                             "근무시간은 9시~22시까지 입력할 수 있습니다.");
    int end = queryInRange("퇴근시간을 입력해주세요.", WORK_START, WORK_END,
                           "근무시간은 9시~22시까지 입력할 수 있습니다.");

    if(end < start) {
        printf("퇴근시간이 출근시간보다 이를 수 없습니다.");
    } else {
        ws[day].start = start;
        ws[day].end = end;
    }
}

/* ===== 2. 주당 중 근무시간 현황표 ===== */
void chart(const WorkHour ws[]) {
    int r=0;
    int o=0;
    for(int i=0; i<5; i++) {
        r += regular(&ws[i]);
        o += over(&ws[i]);
    }

    printf("***** 주당 총 근무시간 현황표 *****\n");
    printf("총근무시간: %d시간\n", r + o);
    printf("정상근무시간: %d시간\n", r);
    printf("연장근무시간: %d시간\n", o);
}

int main() {
    WorkHour workHours[5];

    // 기본 출퇴근시간
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