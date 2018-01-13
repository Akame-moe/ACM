/*
----------description----------
问题很简单，在一条直线上，坐标从0开始到1000000；现在有n个石子在这条直线上（同一个位置可能有多个石子）

那么用一个定长为m的杆子去覆盖，请问最多能覆盖多少个石子？


----------input----------
输入有多组数据  
第一行有2个整数，n 和 m(n <= 50000,0 < m <= 1000)  
第二行有n个整数代表每个石子的位置(所有的数小于50000）


----------output----------
每种情况输出一个整数（最多能覆盖的石子数）


----------sample_input----------
3 2
0 0 1
5 2
0 1 2 4 5
----------sample_putput----------
3
3
*/
/////////////////////////////
#include<stdio.h>
#include<string.h>
#define M 1000002
int a[M];
int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		memset(a,0,M);
		int i,j;
		for(i=0;i<n;i++)
		{
			scanf("%d",&j);
			a[j]++;
		}
		int sum=0;
		for(i=0;i<=m;i++)
			sum+=a[i];
		int max=sum;
		for(i=0;i<M-m;i++)
		{
			sum=sum-a[i]+a[i+m+1];
			if(sum>max)
				max=sum;

		}
		printf("%d\n",max);

	}
	return 0;
}