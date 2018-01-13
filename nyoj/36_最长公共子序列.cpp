/*
----------description----------
咱们就不拐弯抹角了，如题，需要你做的就是写一个程序，得出最长公共子序列。  
tip：最长公共子序列也称作最长公共子串(不要求连续)，英文缩写为LCS（Longest Common Subsequence）。其定义是，一个序列 S
，如果分别是两个或多个已知序列的子序列，且是所有符合此条件序列中最长的，则 S 称为已知序列的最长公共子序列。


----------input----------
第一行给出一个整数N(0 接下来每组数据两行，分别为待测的两组字符串。每个字符串长度不大于1000.


----------output----------
每组测试数据输出一个整数，表示最长公共子序列长度。每组结果占一行。


----------sample_input----------
2
asdf
adfsd
123abc
abc123abc
----------sample_putput----------
3
6
*/
/////////////////////////////
//超时
#include<stdio.h>
#include<string.h>
char s1[1005],s2[1005];
int len1,len2;
int max;
//int a[1005][1005];
int main()
{
	void dfs(int ,int ,int );
	int N;	
	scanf("%d",&N);
	while(N--)
	{
	
		scanf("%s",s1);
		scanf("%s",s2);
		len1=strlen(s1);
		len2=strlen(s2);
		max=0;
		dfs(0,0,0);
		printf("%d\n",max);
	}
	return 0;
}
void dfs(int i,int j,int len)
{	
	if(len>max)
		max=len;
	if(i>=len1 || j>=len2)
		return ;
	if(s1[i]==s2[j])
		dfs(i+1,j+1,len+1);
	else
	{
		dfs(i+1,j,len);
		dfs(i,j+1,len);
	}

}
//ac
#include<stdio.h>
#include<string.h>
#define max(a,b) a>b?a:b
char s1[1005],s2[1005];
int len1,len2;
int a[1005][1005];
int main()
{
	int N;	
	int i,j;
	scanf("%d",&N);
	while(N--)
	{
	
		scanf("%s",s1);
		scanf("%s",s2);
		len1=strlen(s1);
		len2=strlen(s2);
		//max=0;
		for(i=0;i<=len1;i++)
			a[i][0]=0;
		for(j=0;j<=len2;j++)
			a[0][j]=0;
		for(i=1;i<=len1;i++)
		{
			for(j=1;j<=len2;j++)
			{
				if(s1[i-1]==s2[j-1])
					a[i][j]=a[i-1][j-1]+1;
				else 
					a[i][j]=max(a[i-1][j],a[i][j-1]);
			}
		}				
		printf("%d\n",a[len1][len2]);
	}
	return 0;
}
