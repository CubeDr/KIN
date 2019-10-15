//
// Created by HyunI on 2019-10-11.
//

#include <stdio.h>
#include <string.h>

int countSubstring(const char* string, const char* substring) {
    int count = 0;
    int len = strlen(substring);
    const char *found = string;

    while(1) {
        found = strstr(found, substring);

        if(!found) return count;

        count++;
        // AAAA AA 이면 2
        found += len;
        // AAAA AA 이면 3
        // found++;
    }
}

int main() {
    const char* string = "AAAA";
    const char* substring = "AA";
    printf("%d", countSubstring(string, substring));
    return 0;
}