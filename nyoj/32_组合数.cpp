/*
----------description----------
找出从自然数1、2、... 、n（0<n<10）中任取r(0<r<=n)个数的所有组合。


----------input----------
输入n、r。


----------output----------
按特定顺序输出所有组合。  
特定顺序：每一个组合中的值从大到小排列，组合之间按逆字典序排列。


----------sample_input----------
5 3
----------sample_putput----------
543
542
541
532
531
521
432
431
421
321
*/
/////////////////////////////
#include<stdio.h>
int a[10];
void p(int n,int r)
{
	int i,j;
	 for(i=n;i>0;--i)
	 {
		a[r]=i;
		if(r>1)
			p(i-1,r-1);
	   else
		{
			for(j=a[0];j>0;--j)
				printf("%d",a[j]);
			printf("\n");
		}
	 }
}
int main()
{
	int n,r;
	scanf("%d%d",&n,&r);
	a[0]=r;
    p(n,r);
	return 0;
}