/*
----------description----------
****

********给定两个数m,n,其中m是一个素数。********

********************

**将n（0 <=n<=10000）的阶乘分解质因数，求其中有多少个m。**

****


----------input----------
第一行是一个整数s（0 随后的s行, 每行有两个整数n，m。


----------output----------
输出m的个数。


----------sample_input----------
2

100 5

16 2
----------sample_putput----------
24

15
*/
/////////////////////////////

#include<stdio.h>

int main() {
    int N;
    int num, prime, t;
    int i, count;
    scanf("%d", &N);
    while(N--) {
        count = 0;
        scanf("%d%d", &num, &prime);
        for(i = prime; i <= num; i += prime) {
            t = i;
            while(t % prime == 0) {
                count++;
                t /= prime;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}