/*
----------description----------
“ACKing”同学以前做一个图像处理的项目时，遇到了一个问题，他需要摘取出图片中某个黑色线圏成的区域以内的图片，现在请你来帮助他完成第一步，把黑色线圏外的区域全部变为黑色。

![](/JudgeOnline/admin/kind/attached/20101110121709_32589.jpg)
![](/JudgeOnline/admin/kind/attached/20101110122055_50520.jpg)

图1 图2

已知黑线各处不会出现交叉（如图2）,并且，除了黑线上的点外，图像中没有纯黑色（即像素为0的点）。


----------input----------
第一行输入测试数据的组数N(0 每组测试数据的第一行是两个个整数W,H分表表示图片的宽度和高度(3<=W<=1440,3<=H<=960)  
随后的H行，每行有W个正整数,表示该点的像素值。(像素值都在0到255之间，0表示黑色，255表示白色）  


----------output----------
以矩阵形式输出把黑色框之外的区域变黑之后的图像中各点的像素值。


----------sample_input----------
1
5 5
100 253 214 146 120
123 0 0 0 0
54 0 33 47 0
255 0 0 78 0
14 11 0 0 0

----------sample_putput----------
0 0 0 0 0
0 0 0 0 0
0 0 33 47 0
0 0 0 78 0
0 0 0 0 0
*/
/////////////////////////////
#include<stdio.h>
#include<stdlib.h>
#include<queue>
using namespace std;
int map[965][1445];
int dir[4][2]={1,0,  0,1,  -1,0,  0,-1};
typedef struct Point
{
	int x,y;
}P;
queue<P> Q;
int w,h;
int main()
{
//	freopen("d:\\data\\1.txt","r",stdin);
	void bfs();
	int ncase;
	int i,j;
	P tt;
	scanf("%d",&ncase);
	while(ncase--)
	{
		scanf("%d%d",&w,&h);
		for(i=0;i<h;i++)
		{
			for(j=0;j<w;j++)
			{
				scanf("%d",&map[i][j]);
				if((i==0 || j==0 || i==(h-1) || j==(w-1) )&& map[i][j]!=0)
				{
					tt.x=j;
					tt.y=i;
					map[i][j]=0;
					Q.push(tt);
				}
			}
		}
		bfs();
		for(i=0;i<h;i++)
		{
			for(j=0;j<w;j++)
				printf("%d ",map[i][j]);
			printf("\n");
		}
	}
	return 0;
}
void bfs()
{
	
	P cur,next;
	while(!Q.empty())
	{
		int k;
		cur=Q.front();
		Q.pop();
		for(k=0;k<4;k++)
		{
			next.x=cur.x+dir[k][0];
			next.y=cur.y+dir[k][1];
			if(next.x>=0 && next.x<w && next.y>=0 && next.y<h && map[next.y][next.x]!=0)
			{
				map[next.y][next.x]=0;
				Q.push(next);
			}
		}
	}
	
	while(!Q.empty())
		Q.pop();
	return ;
}