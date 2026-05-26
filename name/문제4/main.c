#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct DlistNode {
    element data;
    struct DlistNode* llink;
    struct DlistNode* rlink;
} DlistNode;

void init(DlistNode* phead) {
    phead->llink = phead;
    phead->rlink = phead;
}

void display(DlistNode* phead) {
    DlistNode* p;

    printf("-- 이중 연결 리스트 --\n");

    for (p = phead->rlink; p != phead; p = p->rlink) {
        printf("<---|%p: [%d:%p:%d] %p|--->\n",
            p->llink,
            p->data,
            p,
            p->data,
            p->rlink);
    }
}

void dinsert_node(DlistNode* before, DlistNode* new_node) {
    new_node->llink = before;
    new_node->rlink = before->rlink;
    before->rlink->llink = new_node;
    before->rlink = new_node;
}

void dremove_node(DlistNode* phead_node, DlistNode* removed) {
    if (removed == phead_node) {
        return;
    }

    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;

    free(removed);
}

DlistNode* search(DlistNode* phead_node, element data, int* pos) {
    DlistNode* p;
    int i;

    p = phead_node->rlink;
    i = 0;

    while (p != phead_node) {
        if (p->data == data) {
            *pos = i;
            return p;
        }

        p = p->rlink;
        i++;
    }

    *pos = -1;
    return NULL;
}

int main(void) {
    DlistNode head;
    DlistNode* node;
    DlistNode* result;
    element data;
    int pos;
    int debug;

    printf("디버그모드<1/0> : ");
    scanf("%d", &debug);

    init(&head);

    node = (DlistNode*)malloc(sizeof(DlistNode));
    node->data = 10;
    dinsert_node(&head, node);

    node = (DlistNode*)malloc(sizeof(DlistNode));
    node->data = 20;
    dinsert_node(&head, node);

    node = (DlistNode*)malloc(sizeof(DlistNode));
    node->data = 30;
    dinsert_node(&head, node);

    node = (DlistNode*)malloc(sizeof(DlistNode));
    node->data = 40;
    dinsert_node(&head, node);

    display(&head);

    while (1) {
        printf("\n찾을 항목 <종료999> : ");
        scanf("%d", &data);

        if (data == 999) {
            break;
        }

        result = search(&head, data, &pos);

        if (result != NULL) {
            printf("[%d:%d]\n", pos, result->data);
        }
        else {
            printf("찾는 항목이 없습니다.\n");
        }
    }

    return 0;
}