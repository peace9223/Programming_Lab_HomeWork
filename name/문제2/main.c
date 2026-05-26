#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

typedef int element;

typedef struct ListNode {
    element data;
    struct ListNode* link;
} ListNode;

typedef struct {
    ListNode* head;
    int length;
} ListType;

void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void insert_node(ListNode** phead, ListNode* p, ListNode* new_node) {
    if (*phead == NULL) {
        new_node->link = NULL;
        *phead = new_node;
    }
    else if (p == NULL) {
        new_node->link = *phead;
        *phead = new_node;
    }
    else {
        new_node->link = p->link;
        p->link = new_node;
    }
}

void remove_node(ListNode** phead, ListNode* p, ListNode* removed) {
    if (p == NULL) {
        *phead = removed->link;
    }
    else {
        p->link = removed->link;
    }
    free(removed);
}

void init(ListType* list) {
    list->head = NULL;
    list->length = 0;
}

int is_empty(ListType* list) {
    return list->length == 0;
}

int get_length(ListType* list) {
    return list->length;
}

ListNode* get_node_at(ListType* list, int pos) {
    ListNode* p;

    if (pos < 0 || pos >= list->length) {
        return NULL;
    }

    p = list->head;

    for (int i = 0; i < pos; i++) {
        p = p->link;
    }

    return p;
}

void add(ListType* list, int position, element data) {
    ListNode* p;
    ListNode* new_node;

    if (position < 0 || position > list->length) {
        error("위치 오류");
    }

    new_node = (ListNode*)malloc(sizeof(ListNode));

    if (new_node == NULL) {
        error("메모리 할당 오류");
    }

    new_node->data = data;
    new_node->link = NULL;

    if (position == 0) {
        insert_node(&(list->head), NULL, new_node);
    }
    else {
        p = get_node_at(list, position - 1);
        insert_node(&(list->head), p, new_node);
    }

    list->length++;
}

void add_last(ListType* list, element data) {
    add(list, list->length, data);
}

void add_first(ListType* list, element data) {
    add(list, 0, data);
}

void Delete(ListType* list, int pos) {
    ListNode* p;
    ListNode* removed;

    if (pos < 0 || pos >= list->length) {
        error("위치 오류");
    }

    if (pos == 0) {
        removed = list->head;
        remove_node(&(list->head), NULL, removed);
    }
    else {
        p = get_node_at(list, pos - 1);
        removed = p->link;
        remove_node(&(list->head), p, removed);
    }

    list->length--;
}

element get_entry(ListType* list, int pos) {
    ListNode* p;

    if (pos < 0 || pos >= list->length) {
        error("위치 오류");
    }

    p = get_node_at(list, pos);

    return p->data;
}

void clear(ListType* list) {
    while (!is_empty(list)) {
        Delete(list, 0);
    }
}

void display(ListType* list) {
    ListNode* p = list->head;

    printf("< ");

    while (p != NULL) {
        printf("%d ", p->data);
        p = p->link;
    }

    printf(">\n");
}

int is_in_list(ListType* list, element item) {
    ListNode* p = list->head;

    while (p != NULL) {
        if (p->data == item) {
            return TRUE;
        }

        p = p->link;
    }

    return FALSE;
}

ListNode* search2(ListType* list, element data, int* pos) {
    ListNode* p = list->head;
    int i = 0;

    while (p != NULL) {
        if (p->data == data) {
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
    ListType list;
    int debug;
    int pos;
    element data;

    init(&list);

    printf("[디버그코드(1/0)] : ");
    scanf("%d", &debug);

    add_last(&list, 10);
    add_last(&list, 20);
    add_last(&list, 30);
    add_last(&list, 40);
    display(&list);

    Delete(&list, 3);
    display(&list);

    Delete(&list, 0);
    display(&list);

    clear(&list);

    add_first(&list, 20);
    add_first(&list, 30);
    display(&list);

    add_first(&list, 10);
    display(&list);

    if (is_in_list(&list, 20) == TRUE) {
        printf("is_in_list(list,20) 성공\n");
    }

    printf("get_entry(list,0) = %d\n", get_entry(&list, 0));

    add_first(&list, 100);
    add_last(&list, 40);
    display(&list);

    while (1) {
        printf("찾을 항목 <종료999> : ");
        scanf("%d", &data);

        if (data == 999) {
            break;
        }

        search2(&list, data, &pos);

        if (pos != -1) {
            printf("[%d:%d]\n", pos, data);
        }
        else {
            printf("찾는 항목이 없습니다.\n");
        }
    }

    clear(&list);

    return 0;
}