//
// Created by HyunI on 2019-07-09.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* alphabetString(const char* str, int len) {
    char* astr = (char*) malloc(100);
    int index = 0;
    for(int i=0; i<len; i++) {
        char c = str[i];
        if( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') )
            astr[index++] = c;
    }
    astr[index] = '\0';
    return astr;
}

void stringProcess() {
    char str[100];
    scanf("%s", str);
    char* astr = alphabetString(str, strlen(str));
    printf("%s %s\n", str, astr);
    free(astr);
}

int main() {
    stringProcess();
    return 0;
}