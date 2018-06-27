/*
----------description----------
现在有很多物品（它们是可以分割的），我们知道它们每个物品的单位重量的价值v和重量w（1<=v,w<=10）；如果给你一个背包它能容纳的重量为m（10<=m<=20）,你所要做的就是把物品装到背包里，使背包里的物品的价值总和最大。


----------input----------
第一行输入一个正整数n（1<=n<=5）,表示有n组测试数据；
随后有n测试数据，每组测试数据的第一行有两个正整数s，m（1<=s<=10）;s表示有s个物品。接下来的s行每行有两个正整数v，w。


----------output----------
输出每组测试数据中背包内的物品的价值和，每次输出占一行。


----------sample_input----------
1

3 15

5 10

2 8

3 9
----------sample_putput----------
65
*/
/////////////////////////////
#include<stdio.h>
#define max(a,b) a>b?a:b
int main() {
    int n, s, m, v, w, i, j, k;
    scanf("%d", &n);
    while(n--) {
        int DP[25] = {0};
        scanf("%d %d", &s, &m);
        for(i = 0; i < s; i++) {
            scanf("%d %d", &v, &w);
            for(k = 0; k < w; k++)
                for(j = m; j > 0; j--)
                    DP[j] = max(DP[j - 1] + v, DP[j]);
        }
        printf("%d\n", DP[m]);
    }
}
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Good {
    int w;
    int v;
};
int comp(const void *a, const void *b) {
    struct Good *c = (Good *)a;
    struct Good *d = (Good *)b;
    return d->v - c->v;
}
int main() {
    int N;
    int s, m;
    int i;
    int sum;
    struct Good a[12];
    scanf("%d", &N);
    while(N--) {
        scanf("%d%d", &s, &m);
        for(i = 0; i < s; i++) {
            scanf("%d%d", &a[i].v, &a[i].w);
        }
        qsort(a, s, sizeof(a[0]), comp);
        sum = 0;
        for(i = 0; i < s; i++) {
            m -= a[i].w;
            sum += (a[i].v * a[i].w);
            if(m < 0)
                break;
        }
        if(m < 0) {
            m += a[i].w;
            sum -= (a[i].v * a[i].w);
            sum += m * a[i].v;
        }
        printf("%d\n", sum);
    }
    return 0;
}
