/*
----------description----------
有一块草坪，横向长w,纵向长为h,在它的橫向中心线上不同位置处装有n(n<=10000)个点状的喷水装置，每个喷水装置i喷水的效果是让以它为中心半径为Ri的圆都被润湿。请在给出的喷水装置中选择尽量少的喷水装置，把整个草坪全部润湿。


----------input----------
第一行输入一个正整数N表示共有n次测试数据。
每一组测试数据的第一行有三个整数n,w,h，n表示共有n个喷水装置，w表示草坪的横向长度，h表示草坪的纵向长度。
随后的n行，都有两个整数xi和ri,xi表示第i个喷水装置的的横坐标（最左边为0），ri表示该喷水装置能覆盖的圆的半径。


----------output----------
每组测试数据输出一个正整数，表示共需要多少个喷水装置，每个输出单独占一行。
如果不存在一种能够把整个草坪湿润的方案，请输出0。


----------sample_input----------
2

2 8 6

1 1

4 5

2 10 6

4 5

6 5
----------sample_putput----------
1

2
*/
/////////////////////////////
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
struct Pen {
    double x2;//又断电
    double x1;//左端点
} p[10005];
int comp(const void*a, const void *b) {
    return (*(Pen*)a).x1 > (*(Pen *)b).x1 ? 1 : -1; //做断电排序
}
int main() {
    int  N;
    int n;
    int i;
    int count;
    int w, h, r, x;
    double t, m;
    int flag;
    int j;
    scanf("%d", &N);
    while(N--) {
        flag = 1;
        memset(p, 0, sizeof(p));
        scanf("%d%d%d", &n, &w, &h);
        for(i = 0; i < n; i++) {
            scanf("%d%d", &x, &r);
            if(r * 2 > h) { //不符合要求，舍弃词典
                m = sqrt(r * r * 1.0 - (h * h / 4.0));
                p[i].x1 = x - m;
                p[i].x2 = x + m;
                //printf("%lf./%d/%d/..%lf...",p[i].x1,r,h,m);
            } else {
                i--;
                n--;
            }
        }
        qsort(p, n, sizeof(p[0]), comp);
        //for(i=0;i<n;i++)
        //    printf("[%lf]",p[i].x1);
        if(p[0].x1 > 0)
            flag = 0;
        else {
            count = 0;
            t = 0;
            m = p[0].x2;
            for(i = 0; t < w;) {
                if(p[i].x1 > t) {
                    flag = 0;
                    break;
                }
                for(j = 0; p[j].x1 <= t && j < n; j++) {
                    if(p[j].x2 > m)
                        m = p[j].x2;
                }
                t = m;
                i = j;
                count++;
                if(j == n && t < w) {
                    flag = 0;
                    break;
                }
            }
        }
        if(!flag)
            printf("0\n");
        else
            printf("%d\n", count);
    }
    return 0;
}
