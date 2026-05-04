#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 탑에 몇개의 원판이 있는지
int nplates[3];
// 어떤 원판들이 있는지 (탑의 현재 상태)
int tower[3][100];

// 탑의 내용을 화면에 출력
void print_tower()
{
    int i, j;
    char name[3] = { 'A', 'B', 'C' };

    for (i = 0; i < 3; i++) {
        printf("%c :", name[i]);
        // tower[i]에는 아래 -> 위 순서로 저장됨
        // 출력은 큰 원판이 왼쪽에 오도록 (아래쪽부터) 출력
        for (j = 0; j < nplates[i]; j++) {
            printf(" %d", tower[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("다음 Enter : ");
    getchar();      // 잠시 대기
    fflush(stdin);
}

// start 위치(A,B,C)에 n개의 원판(1~n)이 있도록 초기화
void init_tower(int n, char start)
{
    int i, tower_no;
    // A,B,C -> 0,1,2
    tower_no = start - 'A';

    // 모든 탑 비우기
    for (i = 0; i < 3; i++)
        nplates[i] = 0;

    // start 위치에 n, n-1, ..., 2, 1 순서로 쌓기
    // (아래가 큰 원판, 위가 작은 원판)
    nplates[tower_no] = n;
    for (i = 0; i < n; i++) {
        tower[tower_no][i] = n - i;   // 아래부터 n, n-1, ..., 1
    }
}

// 원판 하나를 from 에서 to 로 이동
void move_one(int n, char from, char to)
{
    int from_no = from - 'A';
    int to_no = to - 'A';

    printf("\n원판 %d을 %c에서 %c로 옮긴다.\n", n, from, to);

    // from 의 제일 위(=배열의 마지막) 원판을 빼서
    nplates[from_no]--;
    // to 의 제일 위(=배열의 끝)에 추가
    tower[to_no][nplates[to_no]] = n;
    nplates[to_no]++;

    // 이동 후 탑의 상태 표시
    print_tower();
}

void hanoi_tower(int n, char from, char tmp, char to)
{
    if (n == 1)
        move_one(1, from, to);
    else {
        hanoi_tower(n - 1, from, to, tmp);
        move_one(n, from, to);
        hanoi_tower(n - 1, tmp, from, to);
    }
}

void main()
{
    init_tower(4, 'A');
    printf("초기 상태\n");
    print_tower();
    hanoi_tower(4, 'A', 'B', 'C');

    printf("계속하려면 아무 키나 누르십시오...");
    getchar();
}