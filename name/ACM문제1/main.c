#include <stdio.h>

#define MAX_LIST_SIZE 100

typedef int element;

typedef struct {
    element list[MAX_LIST_SIZE];
    int length;
} ListType;

void init(ListType* L) {
    L->length = 0;
}

void add(ListType* L, int pos, element item) {
    int i;

    for (i = L->length - 1; i >= pos; i--) {
        L->list[i + 1] = L->list[i];
    }

    L->list[pos] = item;
    L->length++;
}

void add_sorted(ListType* L, element item) {
    int i;

    for (i = 0; i < L->length; i++) {
        if (item < L->list[i]) {
            break;
        }
    }

    add(L, i, item);
}

element get_entry(ListType* L, int pos) {
    return L->list[pos];
}

int get_length(ListType* L) {
    return L->length;
}

int main(void) {
    int T;
    int i, j;
    int score;
    int sum;
    ListType list;

    scanf("%d", &T);

    for (i = 0; i < T; i++) {
        init(&list);

        for (j = 0; j < 5; j++) {
            scanf("%d", &score);
            add_sorted(&list, score);
        }

        if (get_entry(&list, 3) - get_entry(&list, 1) >= 4) {
            printf("KIN\n");
        }
        else {
            sum = get_entry(&list, 1) + get_entry(&list, 2) + get_entry(&list, 3);
            printf("%d\n", sum);
        }
    }

    return 0;
}