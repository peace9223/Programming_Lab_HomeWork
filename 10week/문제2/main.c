#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_FIBS 50

int fibos[MAX_FIBS];   // 피보나치 수열 저장
int nfibos;            // 저장된 피보나치 수의 개수

int result[MAX_FIBS];  // 결과로 사용된 피보나치 수들
int nresult;           // 결과의 개수

// 피보나치 수열 미리 생성 (1,000,000,000 까지)
void make_fibos()
{
    fibos[0] = 1;
    fibos[1] = 2;
    nfibos = 2;
    while (1) {
        int next = fibos[nfibos - 1] + fibos[nfibos - 2];
        if (next > 1000000000) break;
        fibos[nfibos++] = next;
    }
}

// f <= n 인 최대 피보나치 수 f를 반환
int find_max_fibo(int n)
{
    int i;
    for (i = nfibos - 1; i >= 0; i--) {
        if (fibos[i] <= n)
            return fibos[i];
    }
    return 0;
}

// 합이 n이 되는 최소 개수의 피보나치 수들을 result[]에 저장
void find_fibos(int n)
{
    int f;
    if (n == 1) {
        result[nresult++] = 1;
        return;
    }
    f = find_max_fibo(n);
    if (f == n) {
        result[nresult++] = f;
        return;
    }
    result[nresult++] = f;
    find_fibos(n - f);
}

void main()
{
    FILE* fin, * fout;
    int T, n, i;

    // 파일 열기
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

    make_fibos();

    // 테스트 케이스 수 읽기
    fscanf(fin, "%d", &T);

    while (T-- > 0) {
        fscanf(fin, "%d", &n);

        nresult = 0;
        find_fibos(n);

        // 증가하는 순서로 출력 (큰 수부터 저장되어 있으므로 역순)
        for (i = nresult - 1; i >= 0; i--) {
            if (i == nresult - 1)
                fprintf(fout, "%d", result[i]);
            else
                fprintf(fout, " %d", result[i]);
        }
        fprintf(fout, "\n");
    }

    // 파일 닫기
    fclose(fin);
    fclose(fout);
}