/*
----------description----------
有一个整数n，把从1到n的数字无重复的排列成环，且使每相邻两个数（包括首尾）的和都为素数，称为素数环。

为了简便起见，我们规定每个素数环都从1开始。例如，下图就是6的一个素数环。

![](/JudgeOnline/admin/kind/attached/20120315192417_81102.gif)


----------input----------
有多组测试数据，每组输入一个n(0<n<20)，n=0表示输入结束。


----------output----------
每组第一行输出对应的Case序号，从1开始。
如果存在满足题意叙述的素数环，从小到大输出。
否则输出No Answer。


----------sample_input----------
6

8

3

0
----------sample_putput----------
Case 1:

1 4 3 2 5 6

1 6 5 2 3 4

Case 2:

1 2 3 8 5 6 7 4

1 2 5 8 3 4 7 6

1 4 7 6 5 8 3 2

1 6 7 4 3 8 5 2

Case 3:

No Answer
*/
/////////////////////////////
//sushuhuan
#include<stdio.h>
#include<string.h>
#define N 22
int prime[41] = {
    0, 0, 1, 1, 0, 1, 0,
    1, 0, 0, 0, 1, 0, 1,
    0, 0, 0, 1, 0, 1, 0,
    0, 0, 1, 0, 0, 0, 0,
    0, 1, 0, 1, 0, 0, 0,
    0, 0, 1, 0, 0
};
bool vis[N];
int a[N];
int flag;
int n;
int cas = 1;
int main() {
    cas = 1;
    void dfs(int );
    while(scanf("%d", &n), n != 0) {
        printf("Case %d:\n", cas);
        if(n % 2 == 0 || n == 1) {
            flag = 0;
            memset(vis, false, 21);
            a[0] = 1;
            dfs(1);
            if(!flag)
                printf("No Answer\n");
        } else
            printf("No Answer\n");
        cas++;
    }
    return 0;

}
void dfs(int i) {
    int j;
    if(i == n && prime[1 + a[n - 1]]) {
        flag = 1;
        for(j = 0; j < n; j++)
            printf("%d ", a[j]);
        printf("\n");
    }
    for(j = 2; j <= n; j++) {
        if(!vis[j] && (a[i - 1] + j) % 2) {
            if(prime[j + a[i - 1]]) {
                vis[j] = true;
                a[i] = j;
                dfs(i + 1);
                vis[j] = false;
            }
        }
    }

}