#include <stdio.h>

void dectobin(int n){
	if (n<2)
	{
		printf("%d",n);
		return;
	}
	dectobin(n/2);
	printf("%d",n%2);
}
	
int main(int argc, char *argv[])
{
	int kase,n;
	scanf("%d",&kase);
	while (kase--)
	{
		scanf("%d",&n);
		dectobin(n);
		printf("\n");
	}
	return 0;
}
