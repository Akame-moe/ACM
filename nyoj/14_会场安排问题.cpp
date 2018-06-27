/*
----------description----------
学校的小礼堂每天都会有许多活动，有时间这些活动的计划时间会发生冲突，需要选择出一些活动进行举办。小刘的工作就是安排学校小礼堂的活动，每个时间最多安排一个活动。现在小刘有一些活动计划的时间表，他想尽可能的安排更多的活动，请问他该如何安排。


----------input----------
第一行是一个整型数m(m<100)表示共有m组测试数据。
每组测试数据的第一行是一个整数n(1
随后的n行，每行有两个正整数Bi,Ei(0<=Bi,Ei<10000),分别表示第i个活动的起始与结束时间（Bi<=Ei)


----------output----------
对于每一组输入，输出最多能够安排的活动数量。
每组的输出占一行


----------sample_input----------
2

2

1 10

10 11

3

1 10

10 11

11 20
----------sample_putput----------
1

2
*/
/////////////////////////////
#include<stdio.h>
#include<stdlib.h>
struct T {
    int begin;
    int end;
} t[10001];
int comp(const void*a, const void *b) {
    return (*(T*)a).end - (*(T*)b).end;
}
int main() {
    int N;
    int n;
    int i;
    int count;
    int temp;
    scanf("%d", &N);
    while(N--) {
        scanf("%d", &n);
        for(i = 0; i < n; i++)
            scanf("%d%d", &t[i].begin, &t[i].end);
        qsort(t, n, sizeof(t[0]), comp);
        count = 1;
        temp = t[0].end;
        for(i = 1; i < n; i++) {
            if(t[i].begin > temp) {
                count++;
                temp = t[i].end;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}