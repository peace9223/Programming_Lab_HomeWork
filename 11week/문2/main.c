#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int i, r, ntest;
    int count[6] = { 0 };

    srand(time(NULL)); 

    printf("주사위 횟수 : ");
    scanf("%d", &ntest);

    for (i = 0; i < ntest; i++) {
        r = rand() % 6;        
        count[r]++;            
    }

    for (i = 0; i < 6; i++) {
        printf("%d : %d (%.2f%%)\n", i + 1, count[i], (double)count[i] / ntest * 100);
    }

    return 0;
}