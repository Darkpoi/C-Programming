#include <stdio.h>
void move(int n, int from, int via, int to, int he, int ta)
{
   if(n==1)
   {
      printf("%d(%d) -> %d(%d)\n", from, he, to, ta);
      return;
   }
   move(n-1, from, to, via, he, ta+1);
   move(1, from, via, to, ta, ta);
   move(n-1, via, from, to, he, ta+1);
}

main()
{
   int n;
   scanf("%d", &n);
   move(n, 1, 2, 3, n, 1); /* �ƶ�n��Բ��,1Ϊ���,3Ϊ�յ�,2�ǹ��� */
}
