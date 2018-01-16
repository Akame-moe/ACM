/*
----------description----------
给定整数a1、a2、.......an，判断是否可以从中选出若干数，使它们的和恰好为K。


----------input----------
首先，n和k，n表示数的个数，k表示数的和。  
接着一行n个数。  
（1<=n<=20,保证不超int范围）


----------output----------
如果和恰好可以为k，输出“YES”，并按输入顺序依次输出是由哪几个数的和组成，否则“NO”


----------sample_input----------
4 13

1 2 4 7
----------sample_putput----------
YES

2 4 7
*/
/////////////////////////////
#include<stdio.h>
#include<string.h>
int n,k;
int a[21];
bool visit[21];
bool flag;
int sum;
int main()
{
    int i;

    void dfs(int ,int );
    while(~scanf("%d%d",&n,&k))
    {
        memset(visit,false,21);
        flag=false;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        sum=0;
        dfs(0,0);
        if(!flag)
            printf("NO\n");
    
    }
    return 0;
}
void dfs(int cur,int sum)
{
    if(sum==k)
    {
        flag=true;
        int i;
            printf("YES\n");
            for(i=0;i<n;i++)
                if(visit[i])
                    printf("%d ",a[i]);
            printf("\n");
        return ;
    }
    if(cur==n)
    {
        return ;
    }
    visit[cur]=false;
    dfs(cur+1,sum);
    visit[cur]=false;
    if(sum+a[cur]<=k)
    {
        visit[cur]=true;
        dfs(cur+1,sum+a[cur]);
        visit[cur]=false;        
    }

}
 
#include<stdio.h>
int f = 1,n,k,w[21]={0},s[21]={0};
bool a[21]={0};
void DFS(int i, int c)
{
    int j;
    if(i>=0)
    {
        if(c+s[i]<k)return;
        if(c+w[i]<=k)
        {
            a[i]=1;
            DFS(i-1,c+w[i]);
            a[i]=0;            
        }
        DFS(i-1,c);        
        if(c==k&&f)
        {
            f=0;
            printf("YES\n");
            for(j=1;j<=n;j++)
            if(a[j])
            printf("%d ",w[j]);
            printf("\n");
        }
    }
}

int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        int i;f=1;
        for(i=1;i<=n;i++)
        {
            s[i]=0;
            scanf("%d",&w[i]);
            s[i]=s[i-1]+w[i];
        }
        DFS(n,0);
        if(f)printf("NO\n");
    }
}        
    