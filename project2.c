#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct List {
    int num;
    struct List *next, *pre;
} *head, *tail;

struct List *Create_List(int val) {
    struct List *ptr;
    ptr = malloc(sizeof(struct List));
    ptr->num = val;
    return ptr;
}

int check(int num) {
    struct List *ptr = head;
    while (ptr != NULL)
        if (ptr->num == num) return 0;
        else ptr = ptr->next;
    return 1;
}

void Print_List(struct List *head) {
    if (head == NULL) return;
    printf("%d ", head->num);
    Print_List(head->next);
}

void Delete_List(struct List *head, int x) {
    if (head == NULL) return;
    if (head->num == x) {
        head->pre->next = head->next;
        head->next->pre = head->pre;
        free(head);
        return;
    }
    Delete_List(head->next, x);
}

void Sort_List(struct List *head) {
    struct List *tmp = head, *loop = head;
    int exchange;
    while (loop->num != tail->num) {
        tmp = head;
        while (tmp->num != tail->num) {
            if (tmp->num > tmp->next->num) {
                exchange = tmp->num;
                tmp->num = tmp->next->num;
                tmp->next->num = exchange;
            }
            tmp = tmp->next;
        }
        loop = loop->next;
    }
}

int main() {
    int num = rand() % 100 + 1, i, x;
    char ch;
    struct List *tmp;
    srand((unsigned int)time(0));
    tail = head = Create_List(num);
    head->next = NULL;
    for (i = 1; i < 10; i++) {
        if (check(num = rand() % 100 + 1)) {
            tail->next = Create_List(num);
            tail->next->pre = tail;
            tail = tail->next;
            tail->next = NULL;
        }
    }
    while (scanf("%c", &ch) && ch != 'E') {
        switch (ch) {
            case 'L':
                Print_List(head);
                printf("\n");
                break;
            case 'D':
                scanf("%d", &x);
                if (head->num == x) {
                    head = head->next;
                    free(head->pre);
                    head->pre = NULL;
                    break;
                }
                if (tail->num == x) {
                    tail = tail->pre;
                    free(tail->next);
                    tail->next = NULL;
                    break;
                }
                Delete_List(head, x);
                break;
            case 'I':
                while (!check(num = rand() % 100 + 1));
                tail->next = Create_List(num);
                tail->next->pre = tail;
                tail = tail->next;
                tail->next = NULL;
                break;
            case 'S':
                Sort_List(head);
                break;
        }
    }
    return 0;
}