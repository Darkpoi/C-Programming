/*This problem doesn`t need to think about numbers like 100*/
#include <stdio.h>

void reverse(int n){
	if (n < 10)
	{
		printf("%d",n);
		return;
	}
	printf("%d",n%10);
	reverse(n/10);
}
int main(int argc, char *argv[])
{
	int kase,n;
	scanf("%d",&kase);
	while (kase--)
	{
		scanf("%d",&n);
		reverse(n);
		printf("\n");
	}
	return 0;
}
