#include <stdio.h>

int fib(int n){
	if (n<2)
	{
		return n;
	}
	return fib(n-1) + fib(n-2);
}
int main(int argc, char *argv[])
{
	int kase,n;
	scanf("%d",&kase);
	while (kase--)
	{
		scanf("%d",&n);
		printf("fib(%d)=%d\n",n,fib(n));
	}
	return 0;
}
