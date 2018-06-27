/*
----------description----------
计算n!的十进制表示最后有多少个0


----------input----------
第一行输入一个整数N表示测试数据的组数(1<=N<=100)
每组测试数据占一行，都只有一个整数M(0<=M<=10000000)


----------output----------
输出M的阶乘的十进制表示中最后0的个数
比如5!=120则最后的0的个数为1


----------sample_input----------
6

3

60

100

1024

23456

8735373
----------sample_putput----------
0

14

24

253

5861

2183837
*/
/////////////////////////////
#include<stdio.h>
int main() {
    int n;
    int m;
    int count = 0;
    scanf("%d", &m);
    while(m--) {
        scanf("%d", &n);
        while(n) {
            n /= 5;
            count += n;
        }
        printf("%d\n", count);
    }
    return 0;
}

#include<stdio.h>
int main() {
    int count;
    int n, t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        count = 0;
        while(n) {
            count += n / 5;
            n /= 5;
        }
        printf("%d\n", count);
    }
    return 0;
}

#include <stdio.h>

/*计算n!结尾零的个数，返回结尾零的个数。*/
int CalZeroNum(int n) {
    int num = 0; //n!结尾零的个数
    int b = 1; //5的次方
    while(b <= n) {
        b *= 5;
        num += n / b;
    }
    return num;//返回结尾零的个数
}

int  main() {
    int n, T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        printf("%d\n", CalZeroNum(n));
    }
    return 0;
}