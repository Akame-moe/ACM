/*
----------description----------

           最近zmh喜欢上了打扑克，有一天他又找同学打扑克规则如下:2人各有m张牌轮流出牌(打出的牌不归任何人所有), 遇到出的牌和前面有相同,则这之间的排归出牌人,收回牌不打出 ,zmh先出牌,最后拥有牌多者赢(牌数相等也是zmh赢),聪明的zmh知道了两人牌排列的顺序，他想知道自己能不能赢，可他现在有事，你能帮他吗?


----------input----------
第一行为整数n(n<=200)（n组测试数据）  
第二行为整数m(0<=m<=5000),表示二人拥有的牌数，首先给出zmh的牌，有m个整数，第i个整数pi(0<=pi<=10000)表示zmh第i张牌的编号,其次以同样的方式给出zmh的同学的牌


----------output----------
如果能赢,输出Yes  
不能则输出No


----------sample_input----------
2
4
1 2 3 4
1 2 3 4
4
4 3 2 1
1 2 3 4


----------sample_putput----------
No
Yes

*/
/////////////////////////////
#include<cstdio>
#include<stack>
#include<vector>
using namespace std;
int main()
{
	int a[5005],b[5005];
	
	int N;
	stack<int> v;
	scanf("%d",&N);
	while(N--)
	{
		int vis[10005]={0};
		int n,i;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n;i++)
			scanf("%d",&b[i]);
		int j=0;
		int count1=0,count2=0;
		for(i=0;i<n;i++)
		{
			if(v.empty())
			{
				vis[a[i]]=1;
				v.push(a[i]);
			}
			else
			{
				if(vis[a[i]])
				{
					while(v.top()!=a[i])
					{
						vis[v.top()]=0;
						v.pop();
						count1++;
					}
					vis[v.top()]=0;
					v.pop();
					count1++;
				}
				else
				{v.push(a[i]);	vis[a[i]]=1;}
			}
			if(v.empty())
			{
				vis[b[i]]=1;
				v.push(b[i]);
			}
			else
			{
				if(vis[b[i]])
				{
					while(v.top()!=b[i])
					{
						vis[v.top()]=0;
						v.pop();
						count2++;
					}
					vis[v.top()]=0;
					v.pop();
					count2++;
				}
				else
				{v.push(b[i]);	vis[b[i]]=1;}
			}


		}
		while(!v.empty())
			v.pop();
		printf("%s\n",count1>=count2?"Yes":"No");

	}
	return 0;
}