#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

int main(void) {
    time_t now;
    struct tm* tp;
    char* days[] = { "일요일", "월요일", "화요일", "수요일",
                    "목요일", "금요일", "토요일" };

    while (1) {
        time(&now);
        tp = localtime(&now);

        printf("%d년 %d월 %d일 %s %d시 %d분 %d초\r", // 같은 줄 맨앞
            tp->tm_year + 1900,
            tp->tm_mon + 1,
            tp->tm_mday,
            days[tp->tm_wday],
            tp->tm_hour,
            tp->tm_min,
            tp->tm_sec);

        fflush(stdout);
    }// ctrl c를 누르면 종료

    return 0;
}