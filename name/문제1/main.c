#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100

typedef int element;

typedef struct {
    element list[MAX_LIST_SIZE];
    int length;
} ArrayListType;

void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init(ArrayListType* L) {
    L->length = 0;
}

int is_empty(ArrayListType* L) {
    return L->length == 0;
}

int is_full(ArrayListType* L) {
    return L->length == MAX_LIST_SIZE;
}

void display(ArrayListType* L) {
    for (int i = 0; i < L->length; i++) {
        printf("%d ", L->list[i]);
    }
    printf("\n");
}

void add(ArrayListType* L, int position, element item) {
    if (is_full(L)) {
        error("리스트 오버플로우");
    }

    if (position < 0 || position > L->length) {
        error("위치 오류");
    }

    for (int i = L->length - 1; i >= position; i--) {
        L->list[i + 1] = L->list[i];
    }

    L->list[position] = item;
    L->length++;
}

element delete_list(ArrayListType* L, int position) {
    element item;

    if (is_empty(L)) {
        error("리스트 언더플로우");
    }

    if (position < 0 || position >= L->length) {
        error("위치 오류");
    }

    item = L->list[position];

    for (int i = position; i < L->length - 1; i++) {
        L->list[i] = L->list[i + 1];
    }

    L->length--;

    return item;
}

int search(ArrayListType* L, element data) {
    for (int i = 0; i < L->length; i++) {
        if (L->list[i] == data) {
            return i;
        }
    }

    return -1;
}

int main(void) {
    ArrayListType list;
    int debug;
    element data;
    int index;

    init(&list);

    printf("[디버그코드(1/0)] : ");
    scanf("%d", &debug);

    add(&list, 0, 10);
    add(&list, 0, 20);
    add(&list, 0, 30);

    display(&list);

    add(&list, 2, 100);

    display(&list);

    while (1) {
        printf("찾을 항목 <종료999> : ");
        scanf("%d", &data);

        if (data == 999) {
            break;
        }

        index = search(&list, data);

        if (index != -1) {
            printf("[%d:%d]\n", index, data);
        }
        else {
            printf("찾는 항목이 없습니다.\n");
        }
    }

    return 0;
}