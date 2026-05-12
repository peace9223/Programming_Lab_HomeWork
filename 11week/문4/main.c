#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int i, grade, score, sum = 0;
    int nstudents;
    int prob;

    int count[9] = { 0 };
    int maxcount[9] = { 0 };
    int start[9] = { 95, 90, 85, 80, 75, 70, 65, 60,  0 };
    int end[9] = { 100, 94, 89, 84, 79, 74, 69, 64, 59 };
    int dist[9] = { 10, 10, 20, 25, 15, 10,  5,  3,  2 };
    char* name[9] = { "A+", "A ", "B+", "B ", "C+", "C ", "D+", "D ", "F " };

    srand(time(NULL));

    printf("성적 개수 n: ");
    scanf("%d", &nstudents);

    int total = 0;
    int remainder[9];
    for (i = 0; i < 9; i++) {
        maxcount[i] = nstudents * dist[i] / 100;
        remainder[i] = (nstudents * dist[i]) % 100;
        total += maxcount[i];
    }

    int remain = nstudents - total;
    while (remain > 0) {
        int maxIdx = -1;
        for (i = 0; i < 9; i++) {
            if (remainder[i] > 0 && (maxIdx == -1 || remainder[i] > remainder[maxIdx])) {
                maxIdx = i;
            }
        }
        if (maxIdx == -1) break;
        maxcount[maxIdx]++;
        remainder[maxIdx] = 0;
        remain--;
    }

    printf("\n");
    for (i = 0; i < nstudents; i++) {
        do {
            prob = rand() % 100;

            if (prob <= 9) grade = 0;
            else if (prob <= 19) grade = 1;
            else if (prob <= 39) grade = 2;
            else if (prob <= 64) grade = 3;
            else if (prob <= 79) grade = 4;
            else if (prob <= 89) grade = 5;
            else if (prob <= 94) grade = 6;
            else if (prob <= 97) grade = 7;
            else                 grade = 8;
        } while (count[grade] + 1 > maxcount[grade]);

        score = start[grade] + rand() % (end[grade] - start[grade] + 1);
        printf("%d ", score);
        sum += score;

        count[grade]++;
    }

    printf("\n\nn=%d 평균 = %.2f\n", nstudents, (double)sum / nstudents);
    for (i = 0; i < 9; i++) {
        printf("%s : %5d (%5.2f%%)\n", name[i], count[i], (double)count[i] / nstudents * 100);
    }

    return 0;
}