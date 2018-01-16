/*
----------description----------
7  
3 8  
8 1 0  
2 7 4 4  
4 5 2 6 5  
(Figure 1)  
Figure 1 shows a number triangle. Write a program that calculates the highest
sum of numbers passed on a route that starts at the top and ends somewhere on
the base. Each step can go either diagonally down to the left or diagonally
down to the right.


----------input----------
Your program is to read from standard input. The first line contains one
integer N: the number of rows in the triangle. The following N lines describe
the data of the triangle. The number of rows in the triangle is > 1 but <=
100. The numbers in the triangle, all integers, are between 0 and 99.


----------output----------
Your program is to write to standard output. The highest sum is written as an
integer.


----------sample_input----------
5
7
3 8
8 1 0 
2 7 4 4
4 5 2 6 5
----------sample_putput----------
30
*/
/////////////////////////////
#include<stdio.h>
#include<string.h>
#define max(a,b) (a>b?a:b)
int f[105][105],a[105][105];
int main()
{
	int i,j,n,c;
	while(~scanf("%d",&n))
	{
		memset(f,0,sizeof(f));
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=i;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		for(i=n;i>=1;i--)
		{
			for(j=1;j<=i;j++)
			{
				f[i][j]=max(f[i+1][j],f[i+1][j+1])+a[i][j];
			}
		}
		printf("%d\n",f[1][1]);
	}
	return 0;
}
