/*
----------description----------
今天是阴历七月初五，acm队员zb的生日。zb正在和C小加、never在武汉集训。他想给这两位兄弟买点什么庆祝生日，经过调查，zb发现C小加和never都很喜欢吃西瓜，而且一吃就是一堆的那种，zb立刻下定决心买了一堆西瓜。当他准备把西瓜送给C小加和never的时候，遇到了一个难题，never和C小加不在一块住，只能把西瓜分成两堆给他们，为了对每个人都公平，他想让两堆的重量之差最小。每个西瓜的重量已知，你能帮帮他么？


----------input----------
多组测试数据（<=1500）。数据以EOF结尾  
第一行输入西瓜数量N (1 ≤ N ≤ 20)  
第二行有N个数，W1, …, Wn (1 ≤ Wi ≤ 10000)分别代表每个西瓜的重量  


----------output----------
输出分成两堆后的质量差


----------sample_input----------
5
5 8 13 27 14
----------sample_putput----------
3
*/
/////////////////////////////
//还是看成容量为 sum/2 的背包问题，用搜索枚举所有情况，使背包中的重量尽量大。如此可得到最优解
#include<stdio.h>
#include<math.h>
int w[25];
int total,min,n,sum;
void get_next(int cur,int sum)
{
	int t;
	if(cur==n)
		return ;
	t=(int)fabs(total-sum*2);
	if(t<min)
		min=t;
	get_next(cur+1,sum);
	get_next(cur+1,sum+w[cur]);
}
int main()
{
	int i;
	while(~scanf("%d",&n))
	{
		total=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&w[i]);
			total+=w[i];
		}
		min=total;
		get_next(0,0);
		printf("%d\n",min);
	}
	return 0;
}
#include <stdio.h>
#define max(a,b) a>b?a:b
int V,ans,n,w[21],sum[21];
void dfs(int i,int cnt)
{
    if(i == 0)
    {
        ans = max(ans,cnt);
        return ;
    }
    if(ans == V || cnt+sum[i] <= ans)       //cut
        return ;
    if(cnt+w[i] <= V)
        dfs(i-1,cnt+w[i]);
    dfs(i-1,cnt);
}
int main()
{
    while(~scanf("%d",&n))
    {
        ans = 0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&w[i]);
            sum[i] = sum[i-1] + w[i];
        }
        V = sum[n]/2;
        dfs(n,0);
        printf("%d\n",sum[n]-2*ans);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct XGD //结构体:西瓜堆
{
	int  Total;    //西瓜堆总重量
	int  XG[20];   //每个西瓜的重量，该位置为零表示没有西瓜
}Xgd;

int Pos1 = 0;
int Pos2 = 0;

void InitXGD(Xgd * xgd) //数据初始化，全部值为零
{
	int i = 0;
	xgd->Total = 0;
	for(i = 0; i<20; i++)
		((*xgd).XG)[i] = 0;
}

void AddXGD(Xgd * xgd, int wight) //向西瓜堆里面放入一个西瓜
{
	int i = 0;
	xgd->Total += wight;  //总重量增加
	for(i = 0; ((*xgd).XG)[i] != 0; i++) //在西瓜堆里面找到一个空位
		NULL;
	((*xgd).XG)[i] = wight;
}

int DeleteXGD(Xgd * xgd, int i)  //去掉位置i的西瓜，返回该西瓜的重量
{
	int re = ((*xgd).XG)[i];
	xgd->Total -= i;
	((*xgd).XG)[i] = 0;
	return i;
}

int IsGive(XGD * xgd1, XGD * xgd2)  //判断是否有一边需要给出西瓜，不需要则返回0
{
	int i = 0;
	int Di = xgd1->Total - xgd2->Total;  //总量之差
	if(Di = 0)
		return 0;
	if(Di < 0){
		for(i = 0; i < 20; i++){
			if(((*xgd2).XG)[i] < Di/2)  //xgd2需要给出西瓜，返回编号的负值
				return 0 - i;
		}
	}
	if(Di > 0){
		for(i = 0; i < 20; i++){
			if(((*xgd1).XG)[i] < Di/2)  //xgd1需要给出西瓜，返回编号的正值
				return i;
		}
	}
	return 0;
}

int IsExchange(XGD * xgd1, XGD * xgd2)  //判断两堆西瓜是否需要交换，是返回重量之差，否则返回-1，双方需要交换西瓜
{
	int i = 0;
	int j = 0;
	int Di = xgd1->Total - xgd2->Total;  //总量之差
	if(Di = 0)
		return 0;
    if(Di < 0){
		for(i = 0; i < 20; i++){
			if(((*xgd1).XG)[i] == 0)
				continue;
			for(j = 0; j < 20; j++){
				if(((*xgd2).XG)[j] == 0)
					continue;
				if(((((*xgd2).XG)[i] - ((*xgd1).XG)[j] < Di/2) &&  ((*xgd2).XG)[i] > ((*xgd1).XG)[j])){
					Pos1 = i;
					Pos2 = j;
					return -1;
				}
			}
		}
	}
	if(Di > 0){
		for(i = 0; i < 20; i++){
			if(((*xgd1).XG)[i] == 0)
				continue;
			for(j = 0; j < 20; j++){
				if(((*xgd2).XG)[j] == 0)
					continue;
				if(((((*xgd1).XG)[i] - ((*xgd2).XG)[j] < Di/2) &&  ((*xgd1).XG)[i] > ((*xgd2).XG)[j])){
					Pos1 = i;
					Pos2 = j;
					return -1;
				}
			}
		}
	}
	return Di;
}

void main()
{
	int i = 0;
	int j = 0;
	int N = 0;
	Xgd xgd1,xgd2;

	InitXGD(&xgd1);
	InitXGD(&xgd2);

	scanf("%d",&N);
	for(i = 1; i<=N; i++){
		scanf("%d",&j);
		if(i%2)
			AddXGD(&xgd1,j);  //奇数号西瓜放在xgd1里
		else
			AddXGD(&xgd2,j);  //偶数号西瓜放在xgd2里
	}
	i = IsGive(&xgd1, &xgd2);
	while(i){
		if(i < 0){
			i = 0 -i;
			AddXGD(&xgd1, DeleteXGD(&xgd2,i));
		}
		if(i > 0){
			AddXGD(&xgd2, DeleteXGD(&xgd1,i));
		}
		i = IsGive(&xgd1, &xgd2);
	}
	while(IsExchange(&xgd1,&xgd2) == -1){
		AddXGD(&xgd1,DeleteXGD(&xgd2,j));
		AddXGD(&xgd2,DeleteXGD(&xgd1,i));
	}
	i = xgd1.Total - xgd2.Total;
	printf("%d\n",i>0?i:0-i);
}       
