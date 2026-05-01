#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    time_t start_time, finish_time;
    struct tm* tp;
    clock_t start, finish;
    double duration;
    int i, j, k = 0;

    // ===== ctime() 이용 =====
    time(&start_time);
    start = clock();

    printf("시작 : %s", ctime(&start_time));

    // 약 20초 걸리는 코드
    for (i = 1; i <= 100000; i++)
        for (j = 1; j < 100000; j++)
            k++;

    time(&finish_time);
    finish = clock();

    printf("종료 : %s", ctime(&finish_time));
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("실행시간 = %f 초입니다.\n\n", duration);


    
    time(&start_time);
    start = clock();
    // localtime 이용
    tp = localtime(&start_time);
    printf("시작 : %02d:%02d:%02d\n",
        tp->tm_hour, tp->tm_min, tp->tm_sec);
    
    // 약 20초 걸리는 코드
    for (i = 1; i <= 100000; i++)
        for (j = 1; j < 100000; j++)
            k++;

    time(&finish_time);
    finish = clock();

    tp = localtime(&finish_time);
    printf("종료 : %02d:%02d:%02d\n",
        tp->tm_hour, tp->tm_min, tp->tm_sec);

    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("실행시간 = %f 초입니다.\n", duration);

    return 0;
}