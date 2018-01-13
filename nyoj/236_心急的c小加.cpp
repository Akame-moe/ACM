/*
----------description----------
C小加有一些木棒，它们的长度和质量都已经知道，需要一个机器处理这些木棒，机器开启的时候需要耗费一个单位的时间，如果第i+1个木棒的重量和长度都大于等于第i个处理的木棒，那么将不会耗费时间，否则需要消耗一个单位的时间。因为急着去约会，C小加想在最短的时间内把木棒处理完，你能告诉他应该怎样做吗？  
  


----------input----------
第一行是一个整数T(1 每组测试数据的第一行是一个整数N（1<=N<=5000）,表示有N个木棒。接下来的一行分别输入N个木棒的L，W（0 < L ,W
<= 10000），用一个空格隔开，分别表示木棒的长度和质量。


----------output----------
处理这些木棒的最短时间。


----------sample_input----------
3 
5 
4 9 5 2 2 1 3 5 1 4 
3 
2 2 1 1 2 2 
3 
1 3 2 2 3 1 

----------sample_putput----------
2
1
3

*/
/////////////////////////////
//心急的c小家
#include<stdio.h>
#include<stdlib.h>
struct Wood
{
	int L;
	int W;
}m[5001];
int comp(const void *a,const void *b)
{
	if((*(Wood*)a).L!=(*(Wood*)b).L)
		return (*(Wood*)a).L-(*(Wood*)b).L;
	else
		return (*(Wood*)a).W-(*(Wood*)b).W;
}
int main()
{
	int T;
	int N;
	int count;
	int i,j,t;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		for(i=0;i<N;i++)
			scanf("%d%d",&m[i].L,&m[i].W);
		qsort(m,N,sizeof(m[0]),comp);
		count=0;
	//	for(i=0;i<N;i++)
	//		printf("[%d]..[%d]\n",m[i].L,m[i].W);
		for(i=0;i<N;i++)
		{
			if(m[i].W!=0)
			{
				t=m[i].W;
				count++;
				for(j=i+1;j<N;j++)
				{
					if(t<=m[j].W)
					{
						t=m[j].W;
						m[j].W=0;
					}
				}
			}
		}



		printf("%d\n",count);
	}
	return 0;


}