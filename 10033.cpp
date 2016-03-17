#include <stdio.h>

struct stud_node {
    int num;
    struct stud_node *next;
} stu[100];

int count = 1;
struct stud_node *head = &stu[0];

struct stud_node *Create_Stu_Doc() {
    int x, ncount = count++;
    struct stud_node *ptr;
    scanf("%d", &x);
    if (x == -1) return head;
    stu[ncount].num = x;
    ptr = Create_Stu_Doc();
    ptr->next = &stu[ncount];
    return &stu[ncount];
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
    ptr->next = NULL;
    Print_Stu_Doc(head->next);
    return 0;
}