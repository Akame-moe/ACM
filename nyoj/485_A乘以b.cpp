/*
----------description----------
设计一个程序求出A*B，然后将其结果每一位相加得到C，如果C的位数大于等于2，继续将C的各位数相加，直到结果是个一位数k。

例如：

6*8=48；

4+8=12；

1+2=3；

输出3即可。


----------input----------
第一行输入一个数N(0 随后的N行每行给出两个非负整数m，n（0<=m,n<=10^12)。


----------output----------
对于每一行数据，输出k。


----------sample_input----------
3

6 8

1234567 67

454 1232
----------sample_putput----------
3

4

5
*/
/////////////////////////////
#include<stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    long long  a, b, m;
    while(n--) {
        scanf("%lld%lld", &a, &b);
        if(a == 0 || b == 0)
            printf("0\n");
        else {
            m = (a % 9) * (b % 9) % 9;
            printf("%d\n", m == 0 ? 9 : m);
        }
    }
    return 0;
}
