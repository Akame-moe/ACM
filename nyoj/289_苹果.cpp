/*
----------description----------
ctest有n个苹果，要将它放入容量为v的背包。给出第i个苹果的大小和价钱，求出能放入背包的苹果的总价钱最大值。




----------input----------
有多组测试数据，每组测试数据第一行为2个正整数，分别代表苹果的个数n和背包的容量v，n、v同时为0时结束测试，此时不输出。接下来的n行，每行2个正整数，用空格隔开，分别代表苹果的大小c和价钱w。所有输入数字的范围大于等于0，小于等于1000。


----------output----------
对每组测试数据输出一个整数，代表能放入背包的苹果的总价值。


----------sample_input----------
3 3

1 1

2 1

3 1

0 0
----------sample_putput----------
2
*/
/////////////////////////////
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct G {
    int w;
    int v;
} a[1005];
int sum;
int dp[1005];
int max(int x, int y) {
    return x > y ? x : y;
}
void zeroonepack(int w, int v) {
    int i;
    for(i = sum; i >= w; i--)
        dp[i] = max(dp[i], dp[i - w] + v);
}
int main() {
    int i, n;
    while(scanf("%d%d", &n, &sum), (n != 0 && sum != 0)) {
        for(i = 0; i < n; i++)
            scanf("%d%d", &a[i].w, &a[i].v);
        memset(dp, 0, sizeof(dp));
        for(i = 0; i < n; i++)
            zeroonepack(a[i].w, a[i].v);
        printf("%d\n", dp[sum]);
    }
    return 0;
}
/*

#include <stdio.h>
#include <string.h>

int result[1005];

int main()
{
    int T;
    int N,V;
    int i,j;

    while(scanf("%d %d",&N,&V)&&(N+V))
    {
        int weight[1001],value[1001];

        for (i=1;i<=N;i++)
        {
            scanf("%d",&weight[i]);
            scanf("%d",&value[i]);
        }

        memset(result,0,sizeof(result));
        for (i=1;i<=N;i++)
            for(j=V;j>=weight[i];j--)
                if (result[j-weight[i]]+value[i]>result[j])
                    result[j] = result[j-weight[i]]+value[i];

        printf("%d\n",result[V]);
    }

    return 0;
}
*/