/*
----------description----------
写一个程序实现指数运算 X^N。(1


----------input----------
输入包含多行数据
每行数据是两个整数X N
数据以EOF结束


----------output----------
于输入的每一行输出X^N的值


----------sample_input----------
2 1

3 2
----------sample_putput----------
2

9
*/
/////////////////////////////
#include<cstdio>
#include<time.h>
using namespace std;
long long calc(long long n, long long m) {
    long long re = 1;
    while(m) {
        if(m & 1)
            re *= n;
        n *= n;
        m >>= 1;
    }
    return re;
}
int main() {
    int x, n;
    while(scanf("%d%d", &x, &n) != EOF) {
        printf("%lld\n", calc(x, n));
    }
}
#include<stdio.h>
#include<math.h>
int main() {
    int a, b;
    int i, j;
    int len;
    int temp, jw;
    while(~scanf("%d%d", &a, &b)) {
        int num[25] = {0};

        len = 1;
        num[1] = a;
        for(i = 1; i < b; i++) {
            jw = 0;
            for(j = 1; j <= len; j++) {
                temp = num[j] * a + jw;
                num[j] = temp % 10;
                jw = temp / 10;
                if(j == len && jw != 0)
                    len++;
            }
        }
        for(j = len; j >= 1; j--)
            printf("%d", num[j]);
        printf("\n");
    }
    return 0;
}