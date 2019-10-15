//
// Created by HyunI on 2019-10-11.
//

#include <stdio.h>

// 해당 숫자가 소수이면 참, 아니면 거짓 반환
int isPrime(int n) {
    for(int i=2; i*i<=n; i++)
        if(n % i == 0) return 0;
    return 1;
}

void printArray(int arr[], int len) {
    for(int i=0; i<len; i++)
        printf("%d ", arr[i]);
}

int main() {
    int primes[10];
    int count = 0;

    int a, b;
    scanf("%d %d", &a, &b);

    // a, b 사이에 있는 수들 중 소수를 최대 10개까지 찾음
    for(int i=a+1; i<b && count < 10; i++)
        if(isPrime(i))
            primes[count++] = i;

    printArray(primes, count);

    return 0;
}