/*
----------description----------
LK最近要去某几个地方旅行，她从地图上计划了几个点，并且用笔点了出来，准备在五一假期去这几个城市旅行。现在希望你找出她点的所有的点中距离最远的两个点的距离是多少。各个景点可以认为是在一个平面上。

  


----------input----------
第一行有一个整数0<n<10表示测试数据的组数随后的n组数据中，第一行有一个整数3<m<100000表示有m个旅游景点。随后的m行每行有两个整数，分别表示每一个点的x和y。景点坐标中可能有重复的，0<=x，y<=10000）


----------output----------
每组数据输出距离最远的点对的距离的平方.


----------sample_input----------
1
4
0 0
1 1
0 1
1 0
----------sample_putput----------
2
*/
/////////////////////////////
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define NN 100005
#define max(a,b) ((a)>(b)?(a):(b))
const int INF=1<<30;
typedef struct Point{
	int x,y;
}P;
P a[NN],q[NN];
int top;
int dis_2(P p1,P p2)
{
	return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}
int xx(P p,P p1,P p2)
{
	return (p1.x-p.x)*(p2.y-p.y)-(p1.y-p.y)*(p2.x-p.x);
}
int comp(const void *x,const void *y)
{
	P i=*(P *)x;
	P j=*(P *)y;
	if(i.x!=j.x)
		return i.x-j.x;
	else
		return i.y-j.y;
}
int main()
{
	int N,i,n;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&a[i].x,&a[i].y);
		}
		qsort(a,n,sizeof(a[0]),comp);
	
		top=0;
		q[0]=a[0];
		for(i=1;i<n;i++)//下凸包
		{
			if(a[i].x==q[top].x && a[i].y==q[top].y) continue;
			while(top>=1 && xx(q[top-1],q[top],a[i])>=0) top--;
			q[++top]=a[i];
		}
		int t=top;
		for(i=n-1;i>=0;i--)//上凸包
		{
			if(a[i].x==q[top].x && a[i].y==q[top].y) continue;
			while(top>t && xx(q[top-1],q[top],a[i])>=0) top--;
			q[++top]=a[i];
		}	
//		for(i=0;i<=t;i++) printf("%d.......%d\n",q[i].x,q[i].y);
//		q[++top]=q[0];
//		for(i=t;i<=top;i++) printf("%d..%d\n",q[i].x,q[i].y);
//printf("%d ..%d\n",q[top].x,q[top].y);
		double ans=0.0;
		t=1;
		for(i=0;i<top;i++)
		{
			while(xx(q[i+1],q[t],q[i]) > xx(q[i+1],q[t+1],q[i])) t=(t+1)%top;
			ans=max(ans,max(dis_2(q[i],q[t]),dis_2(q[i+1],q[t+1])));
		}
		printf("%.0lf\n",ans);		
	}
	return 0;
}
