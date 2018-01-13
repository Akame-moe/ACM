/*
----------description----------
给出一个整数N，每次可以移动2个相邻数位上的数字，最多移动K次，得到一个新的整数。

求这个新的整数的最大值是多少。


----------input----------
多组测试数据。  
每组测试数据占一行，每行有两个数N和K (1 ≤ N≤ 10^18; 0 ≤ K ≤ 100).


----------output----------
每组测试数据的输出占一行，输出移动后得到的新的整数的最大值。


----------sample_input----------
1990 1
100 0
9090000078001234 6
----------sample_putput----------
9190
100
9907000008001234
*/
/////////////////////////////
#include<stdio.h>
#include<string.h>
char s[20];
void Swap(int ,int);
int main()
{
	int k,len,i,j,max;
	while(~scanf("%s%d",s,&k))
	{
		len=strlen(s);
		for(i=0;i<len;i++)
		{
			max=i;
			for(j=1;j<=k && i+j<len;j++)
			{
				if(s[max]<s[i+j])
					max=i+j;
			}
			if(i!=max)
			{
				Swap(i,max);
				k-=(max-i);
			}
		}
		printf("%s\n",s);
	}
	return 0;
}
void Swap(int i,int j)
{
	char temp=s[j];
	for(;j>i;j--)
	{
		s[j]=s[j-1];
	}
	s[i]=temp;
}