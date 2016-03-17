#include <stdio.h>

int ack(int x,int y){
	if (!x) return y+1;
	if (!y) return ack(x-1,1);
	return ack(x-1,ack(x,y-1));
}
int main(int argc, char *argv[])
{
	int kase,x,y;
	scanf("%d",&kase);
	while (kase--)
	{
		scanf("%d %d",&x,&y);
		printf("Ackerman(%d,%d)=%d\n",x,y,ack(x,y));
	}
	return 0;
}
