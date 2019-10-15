//
// Created by HyunI on 2019-10-10.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * 문자열 string에 저장된 숫자들을 double의 배열 result로 변환해주는 함수
 * 반환된 배열의 길이 반환
 */
int toDoubleArray(const char *string, double result[]) {
    char *copy = strdup(string);
    char *ptr = strtok(copy, ",");

    int length = 0;
    while(ptr) {
        result[length++] = atof(ptr);
        ptr = strtok(NULL, ",");
    }

    free(copy);
    return length;
}

int main() {
    const char *pronum = "10.1234,20.5678,30,-100";
    double arr[10];

    int length = toDoubleArray(pronum, arr);

    for(int i=0; i<length; i++) {
        printf("%g\n", arr[i]);
    }
    return 0;
}