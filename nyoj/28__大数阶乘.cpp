/*
----------description----------
我们都知道如何计算一个数的阶乘，可是，如果这个数很大呢，我们该如何去计算它并输出它？


----------input----------
输入一个整数m(0<m<=5000)


----------output----------
输出m的阶乘，并在输出结束之后输入一个换行符


----------sample_input----------
50
----------sample_putput----------
30414093201713378043612608166064768844377641568960512000000000000
*/
/////////////////////////////
//28
#include<stdio.h>
int main()
{
	static int a[100000]; 
	int n;
	int jw;
	int i,j;
	int len=1;
	int temp;
	scanf("%d",&n);
	a[1]=1;
	for(i=2;i<=n;i++)
	{
		jw=0;
		for(j=1;j<=len;j++)
		{
			temp=a[j]*i+jw;
			a[j]=temp%10;
			jw=temp/10;
			if(j>=len && jw!=0)
				len++;			
		}
		
	}
	for(i=len;i>=1;i--)
		printf("%d",a[i]);
	printf("\n");
	return 0;
}
        