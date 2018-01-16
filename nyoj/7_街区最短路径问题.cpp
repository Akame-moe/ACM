/*
----------description----------
一个街区有很多住户，街区的街道只能为东西、南北两种方向。  
  
住户只可以沿着街道行走。  
  
各个街道之间的间隔相等。  
  
用(x,y)来表示住户坐在的街区。  
  
例如（4,20），表示用户在东西方向第4个街道，南北方向第20个街道。  
  
现在要建一个邮局，使得各个住户到邮局的距离之和最少。  
  
求现在这个邮局应该建在那个地方使得所有住户距离之和最小；  
  


----------input----------
第一行一个整数n<20，表示有n组测试数据，下面是n组数据;  
每组第一行一个整数m<20,表示本组有m个住户，下面的m行每行有两个整数0 m行后是新一组的数据；  


----------output----------
每组数据输出到邮局最小的距离和，回车结束；


----------sample_input----------
2
3
1 1
2 1
1 2
5
2 9 
5 20
11 9
1 1
1 20
----------sample_putput----------
2
44
*/
/////////////////////////////
#include<stdio.h>
#include<memory.h>
#include<math.h>
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
int maxx,minx,maxy,miny;
//bool a[101][101];
int b[20][2];
int m;
int main()
{
	int S(int i,int j);

	int i,j;
	int N;
	
	int sum;
	int t;
	scanf("%d",&N);
	while(N--)
	{
		//memset(a,false,sizeof(bool));
		maxx=1,minx=1,maxy=100,miny=100;
		scanf("%d",&m);
		for(t=1;t<=m;t++)
		{
			scanf("%d%d",&i,&j);
			//a[i][j]=true;
			b[t][0]=i;
			b[t][1]=j;
			minx=min(i,minx);
			miny=min(j,miny);
			maxx=max(i,maxx);
			maxy=max(j,maxy);
		}
		sum=0;
		for(t=1;t<=m;t++)
			sum+=b[t][0]-1+b[t][1]-1;
		for(i=minx;i<=maxx;i++)
			for(j=miny;j<=maxy;j++)
			{
				sum=min(sum,S(i,j));
			}
		printf("%d\n",sum);
		
		
	}
	return 0;

}
int S(int i,int j)
{
	int t;
	int he=0;
	for(t=1;t<=m;t++)
		he+=(fabs(i-b[t][0])+fabs(j-b[t][1]));
	return he;
}
 
#include<iostream>
#include<algorithm>
using namespace std;
int x[30],y[30],n,m,i;;
int main()
{
	cin>>n;
	while(n--)
	{
		cin>>m;
		for(i=0;i<m;i++)
			cin>>x[i]>>y[i];
		sort(x,x+m);
		sort(y,y+m);
		int sum=0;
		for(i=0;i<m/2;i++)
			sum+=x[m-1-i]-x[i]+y[m-1-i]-y[i];
		cout<<sum<<endl;
	}
	return 0;
}        


