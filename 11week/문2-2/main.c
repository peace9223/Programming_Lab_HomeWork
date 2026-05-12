#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int i, r, dice, ntest;
    int count1[6] = { 0 };  
    int count2[6] = { 0 };  

    srand(time(NULL));  

    printf("주사위 횟수 : ");
    scanf("%d", &ntest);

    
    for (i = 0; i < ntest; i++) {
        dice = rand() % 6;    
        count1[dice]++;
    }

    
    for (i = 0; i < ntest; i++) {
        r = rand() % 100;       

        if (r >= 0 && r <= 9)        dice = 0;   
        else if (r >= 10 && r <= 19) dice = 1;   
        else if (r >= 20 && r <= 29) dice = 2;   
        else if (r >= 30 && r <= 39) dice = 3;   
        else if (r >= 40 && r <= 49) dice = 4;   
        else                         dice = 5;   

        count2[dice]++;
    }

    
    printf("정상적인 주사위\n");
    for (i = 0; i < 6; i++) {
        printf("%d : %d (%.2f%%)\n", i + 1, count1[i], (double)count1[i] / ntest * 100);
    }

    
    printf("\n이상한 주사위\n");
    for (i = 0; i < 6; i++) {
        printf("%d : %d (%.2f%%)\n", i + 1, count2[i], (double)count2[i] / ntest * 100);
    }

    return 0;
}