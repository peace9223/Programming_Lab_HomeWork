#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
    FILE* fin, * fout;
    int T, i, j;
    char buf[256];

    fin = fopen("input.txt", "r");
    if (fin == NULL) {
        printf("input.txt 파일을 열 수 없습니다.\n");
        return 1;
    }

    fout = fopen("output.txt", "w");
    if (fout == NULL) {
        printf("output.txt 파일을 열 수 없습니다.\n");
        fclose(fin);
        return 1;
    }

    fscanf(fin, "%d", &T);
    fgetc(fin);

    for (i = 0; i < T; i++) {
        fgets(buf, sizeof(buf), fin);

        int count = 0;
        int valid = 1;
        int len = strlen(buf);

        for (j = 0; j < len; j++) {
            if (buf[j] == '(') count++;
            else if (buf[j] == ')') count--;
            else continue;

            if (count < 0) {
                valid = 0;
                break;
            }
        }

        if (count != 0) valid = 0;

        if (valid) {
            printf("YES\n");
            fprintf(fout, "YES\n");
        }
        else {
            printf("NO\n");
            fprintf(fout, "NO\n");
        }
    }

    fclose(fin);
    fclose(fout);

    printf("\noutput.txt 파일에 저장되었습니다.\n");
    return 0;
}