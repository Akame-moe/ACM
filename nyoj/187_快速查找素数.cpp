/*
----------description----------
现在给你一个正整数N，要你快速的找出在2.....N这些数里面所有的素数。


----------input----------
给出一个正整数数N(N<=2000000)
但N为0时结束程序。
测试数据不超过100组


----------output----------
将2~N范围内所有的素数输出。两个数之间用空格隔开


----------sample_input----------
5

10

11

0
----------sample_putput----------
2 3 5

2 3 5 7

2 3 5 7 11
*/
/////////////////////////////
//快速查找素数
#include<stdio.h>
#define N 2000001
bool a[N];
int main() {

    int n, i, j;
    memset(a, true, N);
    for(i = 2; i < N; i++) {
        if(a[i]) {
            for(j = 2 * i; j <= N; j += i)
                a[j] = false;
        }
    }
    while( scanf("%d", &n), n != 0) {
        for(j = 2; j <= n; j++) {
            if(a[j])
                printf("%d ", j);
        }
        printf("\n");
    }
    return 0;
}