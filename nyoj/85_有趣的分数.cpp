/*
----------description----------
把分数按下面的办法排成一个数表。

**1/1 1/2 1/3 1/4.....**

**2/1 2/2 2/3....**

**3/1 3/2 ....**

**4/1.....**
.........

我们以z字型方法给上表的每项编号。特定方法：第一项是1/1，然后是1/2、2/1、3/1、2/2、1/3、1/4、2/3……。编程输入项号N（1<=N<=100000），输出表中第N项。


----------input----------
第一行有一个整数m(0 随后有m行，每行有一个整数N；


----------output----------
输出表中第N项


----------sample_input----------
4

3

14

7

12345
----------sample_putput----------
2/1

2/4

1/4

59/99
*/
/////////////////////////////
#include<stdio.h>
int main() {
    int N;
    int i, sum, n;
    scanf("%d", &N);
    while(N--) {
        sum = 0;
        scanf("%d", &n);
        i = 0;
        while(sum < n) {
            i++;
            sum = sum + i;
        }
        sum = sum - i;
        if(i % 2 == 0)
            printf("%d/%d\n", n - sum, i + 1 - (n - sum));
        else
            printf("%d/%d\n", i + 1 - (n - sum), n - sum);
    }
    return 0;
}
