/*
----------description----------
省政府“畅通工程”的目标是使全省任何两个村庄间都可以实现公路交通(但不一定有直接的公路相连,只要能间接通过公路可达即可)。经过调查评估,得到的统计表中列出了有可能建设公路的若干条道路的成本(道路是双向的)。现请你编写程序,计算出全省畅通需要的最低成本。


----------input----------
测试输入包含若干测试用例。第一行一个整数 T (T <= 5) 表示测试用例数量,每个测  
试用例的第 1 行给出评估的道路条数 N、村庄数目 M ( 1 <= M < 100,0 <= N <= M *( M-1) /2),随后的 N
行对应村庄间道路的成本,每行给出三个正整数,依次是两个村庄的编号(每对村庄至多出现一次),以及此两村庄间道路的成本( 也是正整数 )。  
为简单起见,村庄从 1 到 M 编号。


----------output----------
对每个测试用例,在 1 行里输出全省畅通需要的最低成本。若统计数据不足以保证畅通,则输出 No solution。


----------sample_input----------
2
3 3
1 2 1
1 3 2
2 3 4
1 3
2 3 2
----------sample_putput----------
3
No solution
*/
/////////////////////////////
#include<stdio.h>
#include<stdlib.h>
int father[5005];
struct P
{
	int v1,v2;
	int val;
}map[5005];
int comp(const void *a,const void *b)
{
	P *c=(P *)a;
	P *d=(P *)b;
	return c->val-d->val;
}
int f(int x)
{
	return x==father[x]?x:(father[x]=f(father[x]));
}
int main()
{
	int T,N,M;
	int i;
	int sum;
	scanf("%d",&T);
	while(T--)
	{
		sum=0;
		scanf("%d%d",&N,&M);
		for(i=0;i<N;i++)
			scanf("%d%d%d",&map[i].v1,&map[i].v2,&map[i].val);
		qsort(map,N,sizeof(map[0]),comp);
		int count=1;
		for(i=1;i<=M;i++)
			father[i]=i;
		for(i=0;i<N;i++)
		{
			int t=f(map[i].v1);
			int tt=f(map[i].v2);
			if(t!=tt)
			{
				sum+=map[i].val;
				father[t]=tt;
				count++;
			}
			if(count==M)
				break;
		}
		if(i==N)
			printf("No solution\n");
		else
			printf("%d\n",sum);
	}
	return 0;
}