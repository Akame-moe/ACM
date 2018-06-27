/*
----------description----------
一年一度的河南省程序设计大赛又要来了。

竞赛是要组队的，组队形式：三人为一队，设队长一名，队员两名。

现在问题就来了，给你m个人，要求每队n个人，求共有几种不同的组队方式。

（题目保证m%n等于0，所有数据不超出int范围）


----------input----------
多组测试数据，以EOF结束。
每组测试数据输入两个整数m，n。


----------output----------
对每组测试数据输出不同组队方式的数量（考虑到输出的数可能会很大，所以请输出对2013取余后的值），并在输出结束之后输入一个换行符。


----------sample_input----------
4 2
----------sample_putput----------
6
*/
/////////////////////////////
#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 25;

int Cab(int a, int b) {
    int i, x = 1;
    for( i = a; i > a - b; i--)
        x *= i;
    for( i = b; i > 1; i--)
        x /= i;
    return x % 2013;
}

int main() {
    int a, b;
    while(~scanf("%d%d", &a, &b)) {
        int ans = 1;
        for(int i = b; i <= a; i += b)
            ans = (ans * Cab(i, b)) % 2013;
        printf("%d\n", ans);
    }
    return 0;
}
#include<stdio.h>
#include<math.h>
int main() {
    int fun(int n);
    int n, m;
    while(scanf("%d%d", &m, &n) != EOF) {
        //printf("%d   ",(int)pow(fun(n),m/n));
        printf("%d\n", (fun(m) / (int)pow(fun(n), m / n)) % 2013);
    }
    return 0;
}
int fun(int n) {
    if(n == 1)
        return 1;
    else
        return n * fun(n - 1);
}