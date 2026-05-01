#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>



int main(void) {
    time_t now;
    struct tm* tp;
    char* days[] = { "일요일", "월요일", "화요일", "수요일",
                    "목요일", "금요일", "토요일" };

    time(&now); // 현재 시각을 now에 저장
    printf("now = %ld\n", now); // 1900년도 이후 부터 흐른 초
    printf("ctime() : %s", ctime(&now)); // 영문 시간 숫자열

    tp = localtime(&now);
    printf("%d년 %d월 %d일 %s %d시 %d분 %d초\n",
        tp->tm_year + 1900, // 1900년도 부터 시작이니 1900 더해줌
        tp->tm_mon + 1, // 0부터 11까지이니까 맞춰주기 위해 1증가
        tp->tm_mday,
        days[tp->tm_wday],
        tp->tm_hour,
        tp->tm_min,
        tp->tm_sec);

    return 0;
}