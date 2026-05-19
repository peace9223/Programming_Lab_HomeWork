#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define MAZE_SIZE 6
#define MAX_STACK_SIZE 100

typedef struct StackObjectRec {
    short r;
    short c;
} StackObject;

StackObject stack[MAX_STACK_SIZE];
int top = -1;

StackObject here = { 1, 0 };
StackObject entry = { 1, 0 };

char maze[MAZE_SIZE][MAZE_SIZE] = {
    { '1', '1', '1', '1', '1', '1' },
    { 'e', '0', '0', '0', '0', '1' },
    { '1', '0', '1', '1', '0', '1' },
    { '1', '0', '1', '0', '0', '1' },
    { '1', '0', '1', '0', '1', 'x' },
    { '1', '1', '1', '1', '1', '1' }
};

void gotoxy(int x, int y) {
    COORD Pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void init() {
    top = -1;
}

int is_empty() {
    return top == -1;
}

int is_full() {
    return top == MAX_STACK_SIZE - 1;
}

void push(StackObject item) {
    if (is_full()) {
        printf("스택 포화 에러\n");
        return;
    }

    stack[++top] = item;
}

StackObject pop() {
    if (is_empty()) {
        printf("스택 공백 에러\n");
        exit(1);
    }

    return stack[top--];
}

void pushLoc(int r, int c) {
    StackObject tmp;

    if (r < 0 || c < 0) {
        return;
    }

    if (r >= MAZE_SIZE || c >= MAZE_SIZE) {
        return;
    }

    if (maze[r][c] != '1' && maze[r][c] != '.') {
        tmp.r = r;
        tmp.c = c;
        push(tmp);
    }
}

void maze_print() {
    int r, c;

    gotoxy(0, 0);

    for (r = 0; r < MAZE_SIZE; r++) {
        for (c = 0; c < MAZE_SIZE; c++) {
            if (r == here.r && c == here.c) {
                printf("@ ");
            }
            else {
                printf("%c ", maze[r][c]);
            }
        }
        printf("\n");
    }

    printf("\n현재 위치 : (%d, %d)\n", here.r, here.c);
    printf("스택 내용 : ");

    for (int i = 0; i <= top; i++) {
        printf("(%d,%d) ", stack[i].r, stack[i].c);
    }

    printf("          \n");
}

int main(void) {
    int r, c;

    init();
    here = entry;

    while (maze[here.r][here.c] != 'x') {
        r = here.r;
        c = here.c;

        maze[r][c] = '.';

        maze_print();
        Sleep(700);

        pushLoc(r - 1, c);  // 위
        pushLoc(r + 1, c);  // 아래
        pushLoc(r, c - 1);  // 왼쪽
        pushLoc(r, c + 1);  // 오른쪽

        if (is_empty()) {
            printf("\n실패: 출구를 찾을 수 없습니다.\n");
            return 0;
        }
        else {
            here = pop();
        }
    }

    maze_print();
    printf("\n성공: 출구를 찾았습니다!\n");

    return 0;
}
