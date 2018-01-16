/*
----------description----------
南将军统领着N个部队，这N个部队分别驻扎在N个不同的城市。

他在用这N个部队维护着M个城市的治安，这M个城市分别编号从1到M。

现在，小工军师告诉南将军，第K号城市发生了暴乱，南将军从各个部队都派遣了一个分队沿最近路去往暴乱城市平乱。

现在已知在任意两个城市之间的路行军所需的时间，你作为南将军麾下最厉害的程序员，请你编写一个程序来告诉南将军第一个分队到达叛乱城市所需的时间。

![](/JudgeOnline/admin/kind/attached/20101122174626_27048.png)

注意，两个城市之间可能不只一条路。


----------input----------
第一行输入一个整数T，表示测试数据的组数。(T<20)  
每组测试数据的第一行是四个整数N,M,P,Q(1<=N<=100,N<=M<=1000,M-1<=P<=100000)其中N表示部队数，M表示城市数，P表示城市之间的路的条数,Q表示发生暴乱的城市编号。  
随后的一行是N个整数，表示部队所在城市的编号。  
再之后的P行，每行有三个正整数，a,b,t(1<=a,b<=M,1<=t<=100)，表示a,b之间的路如果行军需要用时为t  
  
数据保证暴乱的城市是可达的。


----------output----------
对于每组测试数据，输出第一支部队到达叛乱城市时的时间。每组输出占一行


----------sample_input----------
1

3 8 9 8

1 2 3

1 2 1

2 3 2

1 4 2

2 5 3

3 6 2

4 7 1

5 7 3

5 8 2

6 8 2
----------sample_putput----------
4
*/
/////////////////////////////
#include<stdio.h>
#include<string.h>
#include<vector>
#define N 1005
#define min(a,b) ((a)>(b)?(b):(a))
using namespace std;
vector <int> v[N];
int map[N][N];
bool vis[N];
int dis[N];
const int INF=1<<30;
void DijkstraPath(int s,int n)
{
    register int i,j,k;
    memset(vis,false,sizeof(vis));
    for(i=0;i<v[s].size();i++)
        dis[v[s][i]]=map[s][v[s][i]];
    dis[s]=0;
    vis[s]=true;
    for(i=1;i<n;i++)
    {
        int Min=INF;
        int t=1;
        for(j=1;j<=n;j++)
        {
            if(vis[j]==false && dis[j]<Min)
            {
                Min=dis[j];
                t=j;
            }
        }
        vis[t]=true;
        for(j=0;j<v[t].size();j++)
        {
            k=v[t][j];
            if(vis[k]==false)
            {
                dis[k]=min(Min+map[t][k],dis[k]);
            }
        }
    }
}
int main()
{
    int T,n,m,p,q;
    register int i,j;
    scanf("%d",&T);
    while(T--)
    {
        int s,e,w;
        int a[105];
        scanf("%d%d%d%d",&m,&n,&p,&q);
        for(i=0;i<m;i++)
            scanf("%d",&a[i]);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
                map[i][j]=INF;
            dis[i]=INF;
        }
        for(i=0;i<p;i++)
        {
            scanf("%d%d%d",&s,&e,&w);
            if(map[s][e]>w)
            {
                if(map[s][e]==INF){    v[s].push_back(e);    v[e].push_back(s);}
                map[s][e]=map[e][s]=w;
            }
        }
        DijkstraPath(q,n);
        int temp=INF;
        for(i=0;i<m;i++)
            temp=min(temp,dis[a[i]]);
        printf("%d\n",temp);
        for(i=1;i<=n;i++)
            v[i].clear();
    }
    return 0;    
}
 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<queue>
using namespace std;
#define INF 100000
int d[1000];
bool use[1000];
typedef struct arc{
int adj;
int cost;
arc *next;
}arc;
typedef struct{
arc *first;
}vex[1000];
typedef struct{
vex vexs;
int arcnum;
int vnum;
}Graph;
void init(Graph &g){
int i;
for(i=0;i<g.vnum;i++){
g.vexs[i].first=NULL;
}
}
void createGraph(int a,int b,int c,Graph &g){
arc *p=new arc;
arc *q=new arc;
p->adj=b-1;
p->cost=c;
q->adj=a-1;
q->cost=c;
p->next=g.vexs[a-1].first;
g.vexs[a-1].first=p;
q->next=g.vexs[b-1].first;
g.vexs[b-1].first=q;
}
void shortpath(int v,Graph &g){
queue<int>q;
memset(use,false,sizeof(use));
q.push(v);
d[v]=0;
use[v]=true;
while(!q.empty()){
int p=q.front();
q.pop();
arc *w;
for(w=g.vexs[p].first;w;w=w->next){
    if(d[p]+w->cost<d[w->adj]){
    d[w->adj]=w->cost+d[p];
    if(!use[w->adj]){
        q.push(w->adj);
        use[w->adj]=true;
    }
    }
}
}
}
int main(){
int T;
scanf("%d",&T);
while(T--){
int n,m,p,q;
scanf("%d%d%d%d",&n,&m,&p,&q);
int i;
int tem[100];
Graph g;
g.vnum=m;
g.arcnum=p;
for(i=0;i<m;i++){
d[i]=INF;
}
for(i=0;i<n;i++){
scanf("%d",&tem[i]);
}
init(g);
for(i=0;i<p;i++){
int a,b,t;
    scanf("%d%d%d",&a,&b,&t);
    createGraph(a,b,t,g);
    
}
shortpath(q-1,g);
int res=d[tem[0]-1];
for(i=1;i<n;i++){
    if(res>d[tem[i]-1]){
    res=d[tem[i]-1];
    }
}
printf("%d\n",res);
}
return 0;
}        

