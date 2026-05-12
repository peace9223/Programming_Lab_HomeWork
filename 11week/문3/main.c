#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int i, n, score;
    int sum = 0;
    int grade[9] = { 0 };  
    char* name[9] = { "A+", "A ", "B+", "B ", "C+", "C ", "D+", "D ", "F " };

    srand(time(NULL));  

    printf("성적 개수 n: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        score = rand() % 101;   
        printf("%d ", score);
        sum += score;

      
        if (score >= 95)      grade[0]++;   
        else if (score >= 90) grade[1]++;  
        else if (score >= 85) grade[2]++;   
        else if (score >= 80) grade[3]++;   
        else if (score >= 75) grade[4]++;   
        else if (score >= 70) grade[5]++;   
        else if (score >= 65) grade[6]++;   
        else if (score >= 60) grade[7]++;   
        else                  grade[8]++;  
    }

    
    printf("\n\nn=%d 평균 = %.2f\n", n, (double)sum / n);
    for (i = 0; i < 9; i++) {
        printf("%s : %5d (%5.2f%%)\n", name[i], grade[i], (double)grade[i] / n * 100);
    }

    return 0;
}