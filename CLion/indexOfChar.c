//
// Created by HyunI on 2019-07-11.
//
#include <stdio.h>

int indexOfChar(char str[], char c) {
    int index = -1;

    while(index == -1 && // ���� ��ã�Ұ�
        str[index] != '\0' && // ���ڿ��� ������ �ʾҰ�
        str[index] != c) // ���ϴ� ���ڰ� �ƴϸ�
        index++; // ��� ã��

    return index;
}

int main() {
    char str[1000];
    char c;
    printf("# ���ڿ��� �Է��Ͻÿ� : ");
    scanf("%s", str); fflush(stdin);
    printf("# ���ڸ� �Է��Ͻÿ� : ");
    scanf("%c", &c);

    int index = indexOfChar(str, c);
    printf("\"%s\"���ڿ� �ȿ� \'%c\'���ڴ� ", str, c);
    if(index == -1) printf("�������� �ʽ��ϴ�.\n");
    else printf("%d�� ��ġ�� �����մϴ�.\n", index);
    return 0;
}