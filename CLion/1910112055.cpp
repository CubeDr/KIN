//
// Created by HyunI on 2019-10-11.
//

#include <stdint-gcc.h>
#include <cstdio>

uint8_t circular_shift_left(uint8_t value) {
    // 최상위 비트 구하기
    uint8_t bit = (value & (1 << 7)) >> 7;
    // 한 칸 당기고 최상위 비트랑 합치기
    return (value << 1) | bit;
}

void printbits(uint8_t value) {
    int bits[8];
    for(int i=0; i<8; i++) {
        bits[7-i] = value % 2;
        value /= 2;
    }
    for(int i=0; i<8; i++) {
        printf("%d", bits[i]);
    }
    printf("\n");
}

int main() {
    uint8_t bit = 164; // 1010 0100
    printbits(bit);
    bit = circular_shift_left(bit);
    printbits(bit);
    bit = circular_shift_left(bit);
    printbits(bit);
    bit = circular_shift_left(bit);
    printbits(bit);
    return 0;
}