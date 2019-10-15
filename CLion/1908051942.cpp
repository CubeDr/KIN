//
// Created by HyunI on 2019-08-05.
//

#include <stdio.h>
#include <stdlib.h>

void writeToFile(const char* filename) {
    // 파일 열기
    FILE* file = fopen(filename, "wt");
    // 100번 반복
    for(int loop=0; loop<100; loop++)
        // 1~100 출력
        for(int n=1; n<=100; n++)
            fprintf(file, "%d ", n);
    // 파일 작성 완료 - 닫기
    fclose(file);
}

void printFromFile(const char* filename) {
    // 파일 열기
    FILE* file = fopen(filename, "rt");
    // 파일에서 읽을 정수를 담는 변수
    int n;
    // EOF까지 정수를 읽음
    while(fscanf(file, "%d", &n) != EOF)
        // 읽은 정수 출력
        printf("%d ", n);
    // 파일 읽기 완료 - 닫기
    fclose(file);
}

int sumFromFile(const char* filename) {
    // 파일 열기
    FILE* file = fopen(filename, "rt");
    // 파일에서 읽을 정수와 합을 담는 변수
    int n, sum=0;
    // EOF까지 정수를 읽음
    while(fscanf(file, "%d", &n) != EOF)
        // 읽은 정수를 합게 가산
        sum += n;
    // 파일 읽기 완료 - 닫기
    fclose(file);
    return sum;
}

int main() {
    const char* filename = "test.txt";
    writeToFile(filename);
    printFromFile(filename);
    int sum = sumFromFile("test.txt");
    printf("sum: %d", sum);
    return 0;
}