/*
----------description----------
汉诺塔的规则这里就不再多说了，详见题目：汉诺塔（一）

现在假设规定要把所有的金片移动到第三个针上，给你任意一种处于合法状态的汉诺塔，你能计算出从当前状态移动到目标状态所需要的最少步数吗？


----------input----------
第一行输入一个整数N，表示测试数据的组数(0
每组测试数据的第一行是一个整数m表示汉诺塔的层数(0<m<32)，随后的一行有m个整数Ai,表示第i小的金片所在的针的编号。（三根针的编号分别为1，2，3）


----------output----------
输出从当前状态所所有的金片都移动到编号为3的针上所需要的最少总数


----------sample_input----------
2

3

1 1 1

3

1 1 3
----------sample_putput----------
7

3
*/
/////////////////////////////
#include<stdio.h>
long long f(int *p, int i, int final) {
    if(i == 0) return 0;
    else if(p[i] == final) return f(p, i - 1, final);
    else return f(p, i - 1, 6 - p[i] - final) + (1LL << (i - 1));
}
int n, start[35], finish[35];
int main() {
    int T;
    int i, n;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(i = 1; i <= n; i++) {
            finish[i] = 3;
            scanf("%d", &start[i]);
        }
        int k = n;
        long long ans = 0;
        while(k >= 1 && start[k] == finish[k]) k--;
        if(k >= 1) {
            int t = 6 - start[k] - finish[k];
            ans = f(start, k - 1, t) + f(finish, k - 1, t) + 1;
        }
        printf("%lld\n", ans);
    }
    return 0;

}