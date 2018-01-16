/*
----------description----------
在一个吝啬的国度里有N个城市，这N个城市间只有N-1条路把这个N个城市连接起来。现在，Tom在第S号城市，他有张该国地图，他想知道如果自己要去参观第T号城市，必须经过的前一个城市是几号城市（假设你不走重复的路）。


----------input----------
第一行输入一个整数M表示测试数据共有M(1<=M<=5)组  
每组测试数据的第一行输入一个正整数N(1<=N<=100000)和一个正整数S(1<=S<=100000)，N表示城市的总个数，S表示参观者所在城市的编号  
随后的N-1行，每行有两个正整数a,b(1<=a,b<=N)，表示第a号城市和第b号城市之间有一条路连通。


----------output----------
每组测试数据输N个正整数，其中，第i个数表示从S走到i号城市，必须要经过的上一个城市的编号。（其中i=S时，请输出-1）


----------sample_input----------
1
10 1
1 9
1 8
8 10
10 3
8 6
1 2
10 4
9 5
3 7
----------sample_putput----------
-1 1 10 10 9 8 3 1 1 8
*/
/////////////////////////////
#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
vector <int> v[100002];
vector <int> ::iterator pos;
queue <int> Q;
int L[100002];//L【i】=j  i的上一个元素是j
void bfs(int);
int vis[100002];
int main()
{
	int M;
	int N,S;
	int i,n1,n2;
	scanf("%d",&M);
	while(M--)
	{
		memset(vis,0,sizeof(vis));
		scanf("%d %d",&N,&S);
		for(i=1;i<N;i++)
		{
			scanf("%d %d",&n1,&n2);
			v[n1].push_back(n2);
			v[n2].push_back(n1);
		}
		bfs(S);
		for(i=1;i<=N;i++)
			printf("%d ",i==S?-1:L[i]);
		printf("\n");
		for(i=1;i<=N;i++)
			v[i].clear();

	}
	return 0;
}
void bfs(int S)
{
	int cur;
	Q.push(S);
	while(!Q.empty())
	{
		cur=Q.front();
		Q.pop();
	
		if(!v[cur].empty() && !vis[cur])
		{
			vis[cur]=1;// 当前城市访问过
			for(pos=v[cur].begin();pos!=v[cur].end();pos++)
			{
				if(!vis[*pos])
				{
					L[*pos]=cur;
				//	printf("%d->%d\n",cur,*pos);
					Q.push(*pos);
				}
			}
		
		}
		
	}
	while(!Q.empty())
		Q.pop();
	return ;
}