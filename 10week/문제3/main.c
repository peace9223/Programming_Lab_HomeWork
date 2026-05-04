#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main()
{
    FILE* fin, * fout;
    int T;
    long long a, b, x;
    long long orig_a, orig_b;
    int first;

    fin = fopen("input.txt", "r");
    if (fin == NULL) {
        printf("input.txt 파일을 열 수 없습니다.\n");
        return;
    }
    fout = fopen("output.txt", "w");
    if (fout == NULL) {
        printf("output.txt 파일을 만들 수 없습니다.\n");
        fclose(fin);
        return;
    }

    fscanf(fin, "%d", &T);

    while (T-- > 0) {
        fscanf(fin, "%lld %lld", &a, &b);
        orig_a = a;
        orig_b = b;

        // "a/b = " 부분 출력
        fprintf(fout, "%lld/%lld =", orig_a, orig_b);

        first = 1;
        while (a != 1) {
            x = (b + a - 1) / a;

            if (first) {
                fprintf(fout, " 1/%lld", x);
                first = 0;
            }
            else {
                fprintf(fout, " + 1/%lld", x);
            }

            long long new_a = a * x - b;
            long long new_b = b * x;
            a = new_a;
            b = new_b;
        }
        // a == 1 일 때 마지막 단위분수 1/b
        if (first)
            fprintf(fout, " 1/%lld", b);
        else
            fprintf(fout, " + 1/%lld", b);

        fprintf(fout, "\n");
    }

    fclose(fin);
    fclose(fout);
}