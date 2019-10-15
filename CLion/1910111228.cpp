#include <stdio.h>

#define Row 5 // 학생 번호
#define Col 6 // 번호, 중간, 기말, 팀프로젝트, 출석 , 합계

void Input(int score[][Col]);

void Compute(int score[][Col], int *total, double *avg);

void Print(int score[][Col], double *avg);


int main(void) {
    // 학생의 데이터와 과목별 총합
    int score[Row][Col] = {0,}, total[Col - 2] = {0,};
    // 과목별 평균
    double avg[Col - 2];

    // 학생 데이터 입력
    Input(score);
    // 학생별 총합, 과목별 합계/평균 계산
    Compute(score, total, avg);
    // 계산 결과 출력
    Print(score, avg);

    return 0;
}

// 학생 데이터를 입력받는 함수
void Input(int score[][Col]) {
    int i, j;

    // 각 학생에 대해서
    for (i = 0; i < Row; i++)
        // 번호, 중간성적, 기말성적, 팀플성적, 출석성적 입력
        for (j = 0; j < Col - 1; j++)
            scanf("%d", &score[i][j]);
}

// 학생별 총합, 과목별 합계, 과목별 평균을 계산하는 함수
void Compute(int score[][Col], int *total, double *avg) {
    int i, j;

    // 학생별 총합 계산
    for (i = 0; i < Row; i++)
        for (j = 1; j < Col - 1; j++)
            score[i][Col - 1] += score[i][j];

    // 과목별 총합 계산
    for (j = 1; j < Col - 1; j++)
        for (i = 0; i < Row; i++)
            total[j - 1] += score[i][j];

    // 과목별 평균 계산
    for (j = 0; j < Col - 2; j++)
        avg[j] = (double) total[j] / Row;
}

// 계산된 데이터 출력
void Print(int score[][Col], double *avg) {
    int i, j;

    putchar('\n');
    for (i = 0; i < Row; i++) {
        printf("학 생 ");
        for (j = 0; j < Col; j++) {
            printf("%3d", score[i][j]);
            if (j == 0) printf("번: ");
            else if (j == Col - 2) printf(" ==>");
            else if (j == Col - 1) putchar('\n');
            else printf(" ");
        }
    }

    printf("항목별 평균: ");
    for (j = 0; j < Col - 2; j++)
        printf("%6.2f%c", avg[j], j == Col - 1 - 1 ? '\n' : ' ');
}