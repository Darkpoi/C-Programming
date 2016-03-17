#include <stdio.h>

struct Stu
{
	char name[100];
	int num, score;
	struct Stu *next, *pfore;
} stu[100];

void Create_Stu(int num, int Num){
	scanf("%s", stu[num].name);
	scanf("%d", &stu[num].score);
	stu[num].num = Num;
	stu[num-1].next = &stu[num];
	stu[num].pfore = &stu[num-1];
	stu[num].next = NULL;
}

void Delete_Stu(struct Stu now_Stu){
	now_Stu.pfore->next = now_Stu.next;
	if (now_Stu.next != NULL)
    now_Stu.next->pfore = now_Stu.pfore;
}

void Print_Stu(struct Stu *now_Stu){
	if (now_Stu == NULL)
	{
		return;
	}
	printf("%d %s %d\n", now_Stu->num, now_Stu->name, now_Stu->score);
	Print_Stu(now_Stu->next);
}
int main(int argc, char *argv[])
{
	int num, count = 0, i, min_score;
	while (scanf("%d ", &num) && num)
	{
		Create_Stu(++count,num);
	}
	scanf("%d", &min_score);
	for (i = 1; i <= count; i++)
	{
		if (stu[i].score < min_score)
		{
			Delete_Stu(stu[i]);
		}
	}
	Print_Stu(stu[0].next);
	return 0;
}
