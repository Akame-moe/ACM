/*
----------description----------
进行一次独木舟的旅行活动，独木舟可以在港口租到，并且之间没有区别。一条独木舟最多只能乘坐两个人，且乘客的总重量不能超过独木舟的最大承载量。我们要尽量减少这次活动中的花销，所以要找出可以安置所有旅客的最少的独木舟条数。现在请写一个程序，读入独木舟的最大承载量、旅客数目和每位旅客的重量。根据给出的规则，计算要安置所有旅客必须的最少的独木舟条数，并输出结果。


----------input----------
第一行输入s,表示测试数据的组数；  
每组数据的第一行包括两个整数w，n，80<=w<=200,1<=n<=300，w为一条独木舟的最大承载量,n为人数；  
接下来的一组数据为每个人的重量（不能大于船的承载量）；


----------output----------
每组人数所需要的最少独木舟的条数。


----------sample_input----------
3
85 6
5 84 85 80 84 83
90 3
90 45 60
100 5
50 50 90 40 60

----------sample_putput----------
5
3
3
*/
/////////////////////////////
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int comp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
int main()
{
	int N;
	int i;
	int m;
	int sum;
	int n;
	int head,end;
	
	scanf("%d",&N);
	while(N--)
	{
		int ren[305]={0};
		scanf("%d%d",&m,&n);
		n--;
		for(i=0;i<=n;i++)
			scanf("%d",&ren[i]);
		qsort(ren,n+1,sizeof(ren[0]),comp);
		head=0;
		end=n;
		sum=n+1;
		//for(i=0;i<=n;i++)
		//	printf("[%d]",ren[i]);
		while(end>0)
		{
			for(i=end-1;i>=0;)
			{
				if((ren[i]!=0 && ren[end]!=0)&& (ren[end]+ren[i])<=m)
				{
					sum--;
					ren[i]=0;
					break;
				}
				else
					i--;
			}
			end--;
		}		
		printf("%d\n",sum);
	}



	return 0;
}
