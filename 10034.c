#include <stdio.h>

struct stud_node {
    int num;
    struct stud_node *next, *pre;
} stu[100];

int count = 1;
struct stud_node *head = &stu[0];

struct stud_node *Create_Stu_Doc() {
    int x, ncount = count++;
    struct stud_node *ptr;
    scanf("%d", &x);
    if (x == -1) return NULL;
    stu[ncount].num = x;
    ptr = Create_Stu_Doc();
    stu[ncount].next = ptr;
    if (ptr != NULL) ptr->pre = &stu[ncount];
    return &stu[ncount];
}

void DeleteDoc(struct stud_node *head) {
    if (head == NULL) return;
    if (!(head->num % 2)) {
        if (head->next != NULL) head->next->pre = head->pre;
        if (head->pre != NULL) head->pre->next = head->next;
    }
    DeleteDoc(head->next);
}

void Print_Stu_Doc(struct stud_node *head) {
    if (head == NULL)
        return;
    printf("%d ", head->num);
    Print_Stu_Doc(head->next);
}

int main() {
    struct stud_node *ptr;
    ptr = Create_Stu_Doc();
    ptr->pre = head;
    head->next = ptr;
    DeleteDoc(head->next);
    if (head->next != NULL) {
        Print_Stu_Doc(head->next);
        printf("\n");
    }
    else printf("No Records\n");
    return 0;
}