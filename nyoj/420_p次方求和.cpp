/*
----------description----------
一个很简单的问题，求1^p+2^p+3^p+……+n^p的和。


----------input----------
第一行单独一个数字t表示测试数据组数。接下来会有t行数字，每行包括两个数字n,p，  
输入保证0


----------output----------
输出1^p+2^p+3^p+……+n^p对10003取余的结果，每个结果单独占一行。


----------sample_input----------
2
10 1
10 2

----------sample_putput----------
55
385
*/
/////////////////////////////
#include<stdio.h>
int f(int a,int n)
{
	int temp=1;
	while(n>0)
	{
		if(n&1) temp=temp*a%10003;
		a=a*a%10003;
		n>>=1;
	}
	return temp;
}
int main()
{
	int N,n,p,i;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d%d",&n,&p);
		int sum=0;
		for(i=1;i<=n;i++)
		{
			sum+=f(i,p);
			sum%=10003;
		}
		printf("%d\n",sum);
	}
	return 0;
}
