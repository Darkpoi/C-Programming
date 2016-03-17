#include <stdio.h>

double func(double x,int n){
	if (!n)
	{
		return 1;
	}
	return x*func(x,n-1);
}
int main(int argc, char *argv[])
{
	double x;
	int n;
	scanf("%lf %d",&x,&n);
	printf("Root = %.2f\n",func(x,n));
	return 0;
}
