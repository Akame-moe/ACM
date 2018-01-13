/*
----------description----------
输入n个整数，输出其中最小的K个数之和。例如输入4,5,1,1,6,2,7,3,3这9个数字，当k=4，则输出最小的4个数之和为7（1,1,2,3）。


----------input----------
测试样例组数不超过10  
每个测试案例包括2行：  
第一行为2个整数n,k(1<=k<=n<=100000)  
第二行包含n个整数，每个整数的范围为【1~2000】


----------output----------
对应每个测试案例，输出最小的k个数之和。


----------sample_input----------
8 4
5 2 1 3 8 1 9 3
----------sample_putput----------
7
*/
/////////////////////////////
#include<stdio.h>
#include<string.h>
const int MAX=2005;
int main()
{
	int a[MAX];
	int i,n,k,j,sum;
	while(~scanf("%d%d",&n,&k))
	{
		int a[MAX]={0};
		for(i=0;i<n;i++)
		{
			scanf("%d",&j);
			a[j]++;
		}
		sum=0;
		for(i=1;i<MAX;i++)
		{
			if(a[i]<=k)
			{
				k-=a[i];
				sum+=a[i]*i;
			}
			else
			{
				sum+=i*k;
				break;
			}
		}
		printf("%d\n",sum);

	}
	return 0;
}