/*
----------description----------
南将军麾下有百万精兵，现已知共有M个士兵，编号为1~M，每次有任务的时候，总会有一批编号连在一起人请战（编号相近的人经常在一块，相互之间比较熟悉），最终他们获得的军功，也将会平分到每个人身上，这样，有时候，计算他们中的哪一个人到底有多少军功就是一个比较困难的事情，军师小工的任务就是在南将军询问他某个人的军功的时候，快速的报出此人的军功，请你编写一个程序来帮助小工吧。

假设起始时所有人的军功都是0.


----------input----------
只有一组测试数据。
每一行是两个整数T和M表示共有T条指令，M个士兵。（1<=T,M<=1000000)
随后的T行，每行是一个指令。
指令分为两种：
一种形如
ADD 100 500 55 表示，第100个人到第500个人请战，最终每人平均获得了55军功，每次每人获得的军功数不会超过100，不会低于-100。
第二种形如：
QUERY 300 表示南将军在询问第300个人的军功是多少。


----------output----------
对于每次查询输出此人的军功，每个查询的输出占一行。


----------sample_input----------
4 10

ADD 1 3 10

QUERY 3

ADD 2 6 50

QUERY 3
----------sample_putput----------
10

60
*/
/////////////////////////////
#include<stdio.h>
int N;
int c[1000005];
int lowbit(int i) {
    return i & (-i);
}
void updata(int i, int num) {
    while(i <= N) {
        c[i] += num;
        i += lowbit(i);
    }
}
int S(int i) {
    int sum = 0;
    while(i > 0) {
        sum += c[i];
        i -= lowbit(i);
    }
    return sum;
}

int main() {
    int T;
    int i;
    int num, b, e;
    scanf("%d%d", &T, &N);
    char s[10];
    while(T--) {
        scanf("%s", s);
        if(s[0] == 'A') {
            scanf("%d%d%d", &b, &e, &num);
            updata(b, num);
            updata(e + 1, -num);
        } else {
            scanf("%d", &i);
            printf("%d\n", S(i));
        }
    }
    return 0;
}