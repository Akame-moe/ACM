/*
----------description----------
Given two strings A and B, whose alphabet consist only ‘0’ and ‘1’. Your task
is only to tell how many times does A appear as a substring of B? For example,
the text string B is ‘1001110110’ while the pattern string A is ‘11’, you
should output 3, because the pattern A appeared at the posit


----------input----------
The first line consist only one integer N, indicates N cases follows. In each
case, there are two lines, the first line gives the string A, length (A) <=
10, and the second line gives the string B, length (B) <= 1000. And it is
guaranteed that B is always longer than A.


----------output----------
For each case, output a single line consist a single integer, tells how many
times do B appears as a substring of A.


----------sample_input----------
3
11
1001110110
101
110010010010001
1010
110100010101011 
----------sample_putput----------
3
0
3 
*/
/////////////////////////////
#include<stdio.h>
#include<string.h>
int main()
{
	int N;
	char s1[1001],s2[12];
	int count;
	int i,j;
	int t;
	int len1,len2;
	scanf("%d",&N);
	while(N--)
	{
		count=0;
		scanf("%s",s2);
		scanf("%s",s1);
		len1=strlen(s1);
		len2=strlen(s2);
		for(i=0;i<len1;i++)
		{
			t=i;
			for(j=0;j<len2;j++)
			{
				if(s1[t++]==s2[j])
					continue;
				else
					break;
			}
			if(j==len2)
				count++;
		}
		printf("%d\n",count);
	}
	return 0;
}