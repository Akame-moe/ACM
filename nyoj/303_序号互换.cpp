/*
----------description----------
Dr.Kong设计了一个聪明的机器人卡多，卡多会对电子表格中的单元格坐标快速计算出来。单元格的行坐标是由数字编号的数字序号，而列坐标使用字母序号。观察字母序号，发现第1列到第26列的字母序号分别为A，B，…，Z，接着，第27列序号为AA，第28列为AB，依此类推。

若给Dr.Kong的机器人卡多一个数字序号（比如32），它能很快算出等价的字母序号（即AF），若给机器人一个字母序号（比如AA）），它也能很快算出等价的数字序号（27），你能不能与卡多比试比试，看谁能算得更快更准确。


----------input----------
第一行： N 表示有多少组测试数据。  
接下来有N行， 每行或者是一个正整数，或者是一个仅由大写字母组成的字符串。  
输入保证，所有数字序号和字母序号对应的数字序号均 ≤ 2*10^9


----------output----------
对于每一行测试数据，输出一行。如果输入为一个正整数序号，则输出等价的字母序号；如果输入为字符串，则输出等价的数字序号。


----------sample_input----------
3
27
G
AA
----------sample_putput----------
AA
7
27
*/
/////////////////////////////
#include<cstdio>
#include<iostream>
#include<cmath>
#include<string.h>
#include<stdlib.h>
using namespace std;
#define jz 26
int main()
{
	char s[15];
	char sss[]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	int N;
	int b[10];
	int i=0;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%s",s);
		int len=strlen(s);
		if(s[0]>='0' && s[0]<='9')
		{
			int num=0;
			
			num=atoi(s);
			i=0;
			while(num>0)
			{
				b[i++]=(--num)%jz;
				num/=jz;

			}
			while(--i>=0)
			{
				printf("%c",sss[b[i]]);

			}
			printf("\n");
		}
		else
		{
			int num=0;
			int ch;
			
			for(i=0;i<len;i++)
			{
				ch=int(s[i]-'A');
				num+=(int)pow(26,len-i-1)*(ch+1);
			}
			printf("%d\n",num);


		}
	}
	return 0;
}


