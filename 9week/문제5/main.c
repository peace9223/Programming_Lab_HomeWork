#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void main(void) {
    clock_t start, now, pause_start;
    clock_t duration, paused_total = 0;
    clock_t sec, min, hour, millisec;
    int ch1, ch2;
    int paused = 0;   // 일시정지 상태 (0: 실행, 1: 정지)

    printf("Enter: 시작  |  P: 중지  |  C: 계속  |  →: 종료\n");

    // Enter 키 입력 대기
    while (getchar() != '\n');

    start = clock();

    while (1) {
        // 일시정지 중이 아닐 때만 시간 갱신
        if (!paused) {
            now = clock();
            duration = (now - start) - paused_total;

            sec = duration / CLOCKS_PER_SEC;
            millisec = duration % CLOCKS_PER_SEC;
            hour = sec / 3600;
            min = (sec / 60) % 60;
            sec = sec % 60;

            printf("%d:%02d:%02d.%03d           \r",
                hour, min, sec, millisec);
        }
        else {
            printf("%d:%02d:%02d.%03d  [PAUSED]\r",
                hour, min, sec, millisec);
        }
        fflush(stdout);

        // 키 입력 감지
        if (_kbhit()) {
            ch1 = _getch();

            // 특수키 (화살표 등) 처리
            if (ch1 == 0xe0 || ch1 == 0x0) {
                ch2 = _getch();
                if (ch2 == 77)        // → 오른쪽 화살표 (종료)
                    break;
            }
            // P: 중지
            else if (ch1 == 'p' || ch1 == 'P') {
                if (!paused) {
                    paused = 1;
                    pause_start = clock();   // 일시정지 시작 시각 기록
                }
            }
            // C: 계속
            else if (ch1 == 'c' || ch1 == 'C') {
                if (paused) {
                    paused = 0;
                    // 멈춰있던 시간을 보정값에 누적
                    paused_total += clock() - pause_start;
                }
            }
        }
    }

    printf("\n종료되었습니다. 최종 시간: %d:%02d:%02d.%03d\n",
        hour, min, sec, millisec);
}