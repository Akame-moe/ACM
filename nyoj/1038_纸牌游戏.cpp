/*
----------description----------
Acm队的四个大神坐在一起玩纸牌。

大家都知道，每轮纸牌游戏结束之后，都需要重新洗牌，拿牌，然后整理手中的牌。而每次都单纯的如此循环很是枯燥，严重的消磨了玩纸牌的积极性。

现在是一个信息爆炸的时代，科技发展迅猛，所以4个大神就希望看看能够写出一个程序，来完成这些步骤。而身为acm队的大神，手上有一定的特权，就是面对一些琐事，可以交给手下的小弟来完成，。

现在，你的机会来了，洗牌没有任何技术含量，包含了强大的随机性，而你的任务，就是写一个程序来完成4个人的摸排和整理手牌的任务。

Acm队的大神说过，AC就像爱情，来的那么突然，让你惊讶，并且欣喜若狂。

尽情的来吧~~~~！！！

Ps：具体细节看样例输入输出。


----------input----------
多组测试数据；  
第一行一个字母（N，S，W，E，分别代表第一张牌由谁来拿）。  
之后按东、南、西、北顺时针的顺序拿牌。  
第二行表示第一摞牌（26张），  
第三行表示第二摞牌（26张）；  
每张牌由两个字符组成，第一个字符表示牌面大小（A，2~9，T，J，Q，K），第二个字符表示纸牌的花色（C，D，S，H，四种花色）


----------output----------
按东（East player），南（South player），西（West player），北（North
player），四个方向的顺序输出四个人已经整理好的手牌；  
每组样例间输出一个空行。


----------sample_input----------
S
4DQH3C2CJSTC2H4C7STS3SJH9CKC9SKD6S5SAS3DAH8SAC7D4S4H
QC6CJDQD7H8D5DQS6D9D3HJC8C2D2S5C9HAD7CKS6H8HKHTDTH5H
----------sample_putput----------
East player:
+---++---++---++---++---++---++---++---++---++---++---++---++---+
|2 2||4 4||6 6||2 2||3 3||7 7||8 8||9 9||K K||A A||5 5||8 8||J J|
| C || C || C || D || D || D || D || D || D || D || H || H || H |
|2 2||4 4||6 6||2 2||3 3||7 7||8 8||9 9||K K||A A||5 5||8 8||J J|
+---++---++---++---++---++---++---++---++---++---++---++---++---+
South player:
+---++---++---++---++---++---++---++---++---++---++---++---++---+
|7 7||9 9||4 4||5 5||J J||2 2||4 4||6 6||7 7||J J||3 3||K K||A A|
| C || C || D || D || D || S || S || S || S || S || H || H || H |
|7 7||9 9||4 4||5 5||J J||2 2||4 4||6 6||7 7||J J||3 3||K K||A A|
+---++---++---++---++---++---++---++---++---++---++---++---++---+
West player:
+---++---++---++---++---++---++---++---++---++---++---++---++---+
|5 5||T T||J J||K K||T T||Q Q||5 5||8 8||T T||Q Q||K K||4 4||Q Q|
| C || C || C || C || D || D || S || S || S || S || S || H || H |
|5 5||T T||J J||K K||T T||Q Q||5 5||8 8||T T||Q Q||K K||4 4||Q Q|
+---++---++---++---++---++---++---++---++---++---++---++---++---+
North player:
+---++---++---++---++---++---++---++---++---++---++---++---++---+
|3 3||8 8||Q Q||A A||6 6||3 3||9 9||A A||2 2||6 6||7 7||9 9||T T|
| C || C || C || C || D || S || S || S || H || H || H || H || H |
|3 3||8 8||Q Q||A A||6 6||3 3||9 9||A A||2 2||6 6||7 7||9 9||T T|
+---++---++---++---++---++---++---++---++---++---++---++---++---+
*/
/////////////////////////////
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Pai
{
	char num;
	char huase;
};
int comp(const void *a,const void *b)
{
	struct Pai *c=(Pai *)a;
	struct Pai *d=(Pai *)b;
	char cc=(c->huase=='H'?'U':c->huase);
	char dd=(d->huase=='H'?'U':d->huase);
	char ccc=c->num;
	char ddd=d->num;
	ccc=(ccc=='A'?'Z':ccc);
	ccc=(ccc=='K'?'Y':ccc);	
	ccc=(ccc=='T'?'B':ccc);
	
	ddd=(ddd=='A'?'Z':ddd);
	ddd=(ddd=='K'?'Y':ddd);
	ddd=(ddd=='T'?'B':ddd);
	if(cc!=dd)
		return cc-dd;
	else
		return ccc-ddd;
}
int main()
{
	//freopen("d:\\data\\1.txt","r",stdin);
	//freopen("d:\\data\\2.txt","w",stdout);
	struct Pai p[4][14];
	char s1[150],s2[60];
	char person;//先拿牌的人
	int yu;
	int i,j,t,k;
	char shuxu[4][6]={"East","South","West","North"};
	while(~scanf("%c",&person))
	{
		getchar();
		scanf("%s",s1);
		scanf("%s",s2);
		getchar();
		strcat(s1,s2);
		switch(person)
		{
			case 'E':yu=0;break;
			case 'S':yu=1;break;
			case 'W':yu=2;break;
			case 'N':yu=3;break;
			default :printf("caonima\n");
		}
		for(i=0;i<4;i++)
		{
			t=0;
			k=(i+yu)%4;
			for(j=i*2;j<=103;j+=8)
			{
				p[k][t].num=s1[j];
				p[k][t].huase=s1[j+1];
				t++;
			}
			p[k][t].num='\0';
			p[k][t].huase='\0';
			
		}
		for(i=0;i<4;i++)
		{
			printf("%s player:\n",shuxu[i]);
			qsort(p[i],13,sizeof(p[i][0]),comp);
			for(j=0;j<13;j++)
				printf("+---+");
			printf("\n");
			for(j=0;j<13;j++)
				printf("|%c %c|",p[i][j].num,p[i][j].num);
			printf("\n");
			for(j=0;j<13;j++)
				printf("| %c |",p[i][j].huase);
			printf("\n");
			for(j=0;j<13;j++)
				printf("|%c %c|",p[i][j].num,p[i][j].num);
			printf("\n");
			for(j=0;j<13;j++)
				printf("+---+");
			printf("\n");
		}
		printf("\n");
			
	}	
	return 0;
}
