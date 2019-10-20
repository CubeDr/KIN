//
// Created by HyunI on 2019-10-15.
//

#include <stdio.h>

int main() {
    char str[100];
    gets(str);

    for(int i=0; str[i] != '\0'; i++) {
        if(str[i] >= 'a' && str[i] <= 'z')
            str[i] -= ('a' - 'A');
    }

    printf("%s", str);
    return 0;
}