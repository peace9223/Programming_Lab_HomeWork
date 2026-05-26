#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXITEM 100

typedef char* element;

typedef struct ListNode {
    element data;
    struct ListNode* link;
} ListNode;

typedef struct {
    ListNode* head;
    int length;
} ListType;

void init(ListType* list) {
    if (list == NULL) return;

    list->length = 0;
    list->head = NULL;
}

void add_tail(ListType* list, element item) {
    ListNode* node;
    ListNode* p;

    printf("Add pos:%d %s\n", list->length, item);

    node = (ListNode*)malloc(sizeof(ListNode));
    node->data = (element)malloc(strlen(item) + 1);
    strcpy(node->data, item);
    node->link = NULL;

    if (list->head == NULL) {
        list->head = node;
    }
    else {
        p = list->head;

        while (p->link != NULL) {
            p = p->link;
        }

        p->link = node;
    }

    list->length++;
}

void display(ListType* list) {
    ListNode* p;

    p = list->head;

    printf("< ");

    while (p != NULL) {
        printf("%s ", p->data);
        p = p->link;
    }

    printf(">\n");
}

int get_length(ListType* list) {
    return list->length;
}

element get_entry(ListType* list, int n) {
    ListNode* p;
    int i;

    if (n < 0 || n >= list->length) {
        return NULL;
    }

    p = list->head;

    for (i = 0; i < n; i++) {
        p = p->link;
    }

    return p->data;
}

ListNode* search2(ListType* list, element item, int* pos) {
    ListNode* p;
    int i;

    p = list->head;
    i = 0;

    while (p != NULL) {
        if (strcmp(p->data, item) == 0) {
            *pos = i;
            return p;
        }

        p = p->link;
        i++;
    }

    *pos = -1;
    return NULL;
}

int main(void) {
    int i, n;
    ListType list;
    ListNode* node;
    char item[100];
    int debug;

    printf("디버그모드<1/0> : ");
    scanf("%d", &debug);

    init(&list);

    add_tail(&list, "마요네즈");
    add_tail(&list, "빵");
    add_tail(&list, "치즈");
    add_tail(&list, "우유");

    n = get_length(&list);

    printf("쇼핑해야할 항목수는 %d입니다.\n", n);

    display(&list);

    while (1) {
        int pos;

        printf("찾을 항목 <종료quit> : ");
        scanf("%s", item);

        if (strcmp(item, "quit") == 0) {
            break;
        }

        node = search2(&list, item, &pos);

        if (node != NULL) {
            printf("[%d:%s]\n", pos, node->data);
        }
        else {
            printf("Not Found.!\n");
        }
    }

    return 0;
}