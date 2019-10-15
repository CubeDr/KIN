#include<stdio.h>
#include <stdlib.h>

#define IN 10

#define OUT 10

#define MAX 150

#define MIN 5

int main(void) {
    int i = 0;
    int j = 0;
    int max = 0;
    int min = 0;
    int lion[IN][OUT] = {
            {1, 2, 3},
            {3, 4, 5},
    };
    int cat[IN][OUT] = {1, 2, 3, 0, 0, 0, 20, 30, 40};
    int a = 0;
    int b = 0;
    int c = 0;

    printf("나는 주재오(2019243067)입니다\n");
    printf("나는 배열을 공부하는 일을 합니다\n");

    i = 0;
    while (i < IN) {
        j = 0;
        while (j < OUT) {
            cat[i][j] = rand() % 100;
            printf("%2d ", cat[i][j]);
            j++;
            if (max > cat[i][j]) {
                max = cat[i][j];
                b = c;
            }
            c = c + 1;
        }
        i = i + 1;
        printf("\n");
    }
    printf("cat[i][j]방이 최대값 %d를 갖는다.", c, max);
    system("pause");
    return 0;
}