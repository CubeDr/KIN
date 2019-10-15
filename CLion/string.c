//
// Created by HyunI on 2019-07-11.
//
#include <stdio.h>

int strlen_arr(char arr[]) {
    int len = 0;
    while(arr[len] != '\0') len++;
    return len;
}

int strlen_pt_plus(char *arr) {
    int len = 0;
    while(*(arr + len) != '\0') len++;
    return len;
}

int strlen_pt_inc(char *arr) {
    int len = 0;
    while(*arr != '\0') {
        arr++;
        len++;
    }
    return len;
}

void strcpy_arr(char dst[], char src[]) {
    int len = 0;
    while(src[len] != '\0') {
        dst[len] = src[len];
        len++;
    }
    dst[len] = '\0';
}

void strcpy_pt_plus(char *dst, char *src) {
    int len = 0;
    while(*(src + len) != '\0') {
        *(dst + len) = *(src + len);
        len++;
    }
    *(dst + len) = '\0';
}

void strcpy_pt_inc(char *dst, char *src) {
    while(*src != '\0') {
        *dst = *src;
        src++;
        dst++;
    }
    *dst = '\0';
}

int main() {
    char str[100];
    char dst_arr[100];
    char dst_pt_plus[100];
    char dst_pt_inc[100];

    scanf("%s", str);
    printf("%d %d %d\n",
            strlen_arr(str),
            strlen_pt_plus(str),
            strlen_pt_inc(str));

    strcpy_arr(dst_arr, str);
    printf("%s\n", dst_arr);

    strcpy_pt_plus(dst_pt_plus, str);
    printf("%s\n", dst_pt_plus);

    strcpy_pt_inc(dst_pt_inc, str);
    printf("%s\n", dst_pt_inc);

    return 0;
}