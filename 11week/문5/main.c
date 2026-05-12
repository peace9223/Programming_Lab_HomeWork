#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

int main(void) {
    FILE* fp;
    int c;
    int total = 0;
    int alpha = 0;
    int count[26] = { 0 };
    int i;

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    while ((c = fgetc(fp)) != EOF) {
        total++;
        if (isalpha(c)) {
            alpha++;
            count[toupper(c) - 'A']++;
        }
    }

    fclose(fp);

    printf("전체문자수=%d 알파벳수=%d\n", total, alpha);
    for (i = 0; i < 26; i++) {
        printf("%c:%-3d (%5.2f%%) ", 'A' + i, count[i], (double)count[i] / alpha * 100);
        if ((i + 1) % 5 == 0) printf("\n");
    }
    printf("\n");

    return 0;
}