/*
----------description----------
某国为了防御敌国的导弹袭击，发展中一种导弹拦截系统。但是这种导弹拦截系统有一个缺陷：虽然它的第一发炮弹能够到达任意的高度，但是以后每一发炮弹都不能高于等于前一发的高度。某天，雷达捕捉到敌国导弹来袭。由于该系统还在试用阶段，所以只用一套系统，因此有可能不能拦截所有的导弹。


----------input----------
第一行输入测试数据组数N（1<=N<=10）  
接下来一行输入这组测试数据共有多少个导弹m（1<=m<=20）  
接下来行输入导弹依次飞来的高度，所有高度值均是大于0的正整数。  


----------output----------
输出最多能拦截的导弹数目


----------sample_input----------
2

8

389 207 155 300 299 170 158 65

3

88 34 65
----------sample_putput----------
6

2
*/
/////////////////////////////
#include<stdio.h>
#include<limits.h>
int a[25];
int n;
int max;
int main()
{
    void dfs(int ,int,int);
    int N;
    int i;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        max=0;
        dfs(0,0,INT_MAX);
        printf("%d\n",max);
    }
    return 0;
}
void dfs(int cur,int count,int h)
{
    if(count>max)
        max=count;
    if(cur==n)
        return ;
    dfs(cur+1,count,h);    //这句和下一句的位置不能交换，否则改变了h的值，当初就是错在这个位置
    if(h>a[cur])
    {
        h=a[cur];
        //printf("%d  %d \n",cur,h);
        dfs(cur+1,count+1,h);
    }
    
}
 
 
#include<iostream>
#include<string>
using namespace std;
const int MAX=10010;
int f[MAX];
#define max(a,b) a>b?a:b
int data[MAX]={0};
int main()
{
    int n;
    int i,j;
    cin>>n;
    while(n--)
    {
        int sz;
        cin>>sz;
        for( i=0;i!=sz;++i)
            cin>>data[i];
        for( i=0;i<=sz;i++)
        {
            f[i]=1;
            for( j=0;j!=i;j++)
            {
                if(i==sz || data[i]<data[j])
                    f[i]=max(f[i],f[j]+1);
            }
        }
        cout<<f[sz]-1<<endl;
    }
}                