/*
----------description----------
下图是手机常用的九键英文输入法界面，如果要输入字母'A'，我们只

需要按一次数字键2，按键顺序记为2；如果要输入字母'B'的话，我们需要连续按两次数字键2，按键顺序记为22；同理：字母'C’需要连续按3次数字键2，按键顺序记为222。通过这种方法，我们用手机10多个键就能输入26个英文字母。

现在你的任务是统计一段英文用手机输入的按键顺序，同样，你也要能把按键顺序翻译成相应的英文内容。

为了使问题简化，我们假设内容只有大写英文字母和空格。

![](/JudgeOnline/admin/kind/attached/20121214223105_61561.png)  


----------input----------
有多组测试数据  
每组测试数据占一行，有两种情况：  
（1）短信内容(只含有若干个空格和大写字母，不超过1000个字符)  
（2）短信按键顺序（只含有若干空格和数字，其中第一个肯定是数字，不超过1000个字符）  


----------output----------
对于每组测试数据：  
如果是短信内容，输出每个字母的按键顺序，每个字母的按键顺序用空格隔开  
如果是按键顺序，输出它代表的内容


----------sample_input----------
I LOVE YOU
HELLO WORLD
444 0 555 666 888 33 0 999 666 88
44 33 555 555 666 0 9 666 777 555 3
----------sample_putput----------
444 0 555 666 888 33 0 999 666 88
44 33 555 555 666 0 9 666 777 555 3
I LOVE YOU
HELLO WORLD
*/
/////////////////////////////
#include<stdio.h>
#include<string.h>
int main()
{
	char s[1005];
	int i,count;
	int t,j;
	while(gets(s)!=NULL)
	{
		if(s[0]>='0' && s[0]<='9')
		{
			i=0;
			
			while(1)
			{
				count=0;
				while(s[i]==s[++i])
					count++;
				switch(s[i-1]){
					case '0':printf(" ");break;
					case '2':printf("%c",'A'+count);break;
					case '3':printf("%c",'D'+count);break;
					case '4':printf("%c",'G'+count);break;
					case '5':printf("%c",'J'+count);break;
					case '6':printf("%c",'M'+count);break;
					case '7':printf("%c",'P'+count);break;
					case '8':printf("%c",'T'+count);break;
					case '9':printf("%c",'W'+count);break;
				}
				if(s[i]==' ')
					++i;
				if(s[i]=='\0')
					break;
			}
			printf("\n");
		}
		else
		{
			i=0;
			while(1)
			{
				if(s[i]=='\0')
					break;
				else
				{
					t=s[i++]-'A';
					if(t>=0 && t<=15)
					{
						for(j=0;j<=(t%3);j++)
							printf("%d",(t/3)+2);
					}
					else if(t>=16 && t<=18)
					{
						for(j=0;j<=t-15;j++)
							printf("7");
					}
					else if(t>=19 && t<=21)
					{
						for(j=0;j<=t-19;j++)
							printf("8");
					}
					else if(t>=22 && t<=25)
					{
						for(j=0;j<=t-22;j++)
							printf("9");
					}
					else
						printf("0");
				}
				printf(" ");				 
			}
			printf("\n");
		}
	}
	return 0;
}