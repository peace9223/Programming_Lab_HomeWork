#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int i, n, r, sum = 0;
    int start, end;

    srand(time(NULL));  

    printf("난수의 개수: ");
    scanf("%d", &n);

    printf("시작과 끝: ");
    scanf("%d %d", &start, &end);

    for (i = 0; i < n; i++) {
        r = start + rand() % (end - start + 1);  
        printf("%d ", r);
        sum += r;
    }

    printf("\nsum=%d avg=%d\n", sum, sum / n);

    return 0;
}