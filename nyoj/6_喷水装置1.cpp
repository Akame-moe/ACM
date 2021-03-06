/*
----------description----------
现有一块草坪，长为20米，宽为2米，要在横中心线上放置半径为Ri的喷水装置，每个喷水装置的效果都会让以它为中心的半径为实数Ri(0<Ri<15)的圆被湿润，这有充足的喷水装置i（1<i<600)个，并且一定能把草坪全部湿润，你要做的是：选择尽量少的喷水装置，把整个草坪的全部湿润。


----------input----------
第一行m表示有m组测试数据
每一组测试数据的第一行有一个整数数n，n表示共有n个喷水装置，随后的一行，有n个实数ri，ri表示该喷水装置能覆盖的圆的半径。


----------output----------
输出所用装置的个数


----------sample_input----------
2

5

2 3.2 4 4.5 6

10

1 2 3 1 2 1.2 3 1.1 1 2
----------sample_putput----------
2

5
*/
/////////////////////////////
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
struct Pen {
    double r;
    double d;
} p[601];
int comp(const void*a, const void *b) {
    return (*(Pen*)a).r < (*(Pen*)b).r ? 1 : -1;
}
int main() {
    int  N;
    int n;
    int i;
    double l;
    int count;
    scanf("%d", &N);
    while(N--) {
        scanf("%d", &n);
        for(i = 0; i < n; i++) {
            scanf("%lf", &p[i].r);
            p[i].d = 2 * sqrt((p[i].r * p[i].r - 1.0));
        }
        qsort(p, n, sizeof(p[0]), comp);
        //for(i=0;i<n;i++)
        //    printf("[%lf]",p[i].d);
        l = 0;
        count = 0;
        i = 0;
        while(l < 20.0) {
            l += p[i++].d;
            count++;
        }
        printf("%d\n", count);
    }
    return 0;
}
