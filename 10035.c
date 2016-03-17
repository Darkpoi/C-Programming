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

/*void DeleteDoc(struct stud_node *head) {
    if (head == NULL) return;
    if (!(head->num % 2)) {
        if (head->next != NULL) head->next->pre = head->pre;
        if (head->pre != NULL) head->pre->next = head->next;
    }
    DeleteDoc(head->next);
}*/

void Print_Stu_Doc(struct stud_node *head) {
    if (head == NULL)
        return;
    printf("%d ", head->num);
    Print_Stu_Doc(head->next);
}

void InsertDoc(struct stud_node *head1, struct stud_node *head2){
    struct stud_node *tmp;
    if (head2 == NULL) return;
    if (head1->next == NULL) {
        head1->next = head2;
        head2->pre = head1;
        return;
    }
    if (head1->next->num < head2->num) InsertDoc(head1->next, head2);
    else {
        tmp = head2->next;
        head1->next->pre = head2;
        head2->next = head1->next;
        head2->pre = head1;
        head1->next = head2;
        InsertDoc(head2, tmp);
    }
}

int main() {
    struct stud_node *head1 = &stu[0], *head2;
    head1->next = Create_Stu_Doc();
    head2 = Create_Stu_Doc();
    InsertDoc(head1, head2);
    Print_Stu_Doc(head1->next);
    return 0;
}