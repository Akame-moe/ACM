/*
----------description----------
有n个矩形，每个矩形可以用a,b来描述，表示长和宽。矩形X(a,b)可以嵌套在矩形Y(c,d)中当且仅当a<c,b<d或者b<c,a<d（相当于旋转X90度）。例如（1,5）可以嵌套在（6,2）内，但不能嵌套在（3,4）中。你的任务是选出尽可能多的矩形排成一行，使得除最后一个外，每一个矩形都可以嵌套在下一个矩形内。


----------input----------
第一行是一个正正数N(0 每组测试数据的第一行是一个正正数n，表示该组测试数据中含有矩形的个数(n<=1000)
随后的n行，每行有两个数a,b(0<a,b<100)，表示矩形的长和宽


----------output----------
每组测试数据都输出一个数，表示最多符合条件的矩形数目，每组输出占一行


----------sample_input----------
1

10

1 2

2 4

5 8

6 10

7 9

3 1

5 8

12 10

9 7

2 2
----------sample_putput----------
5
*/
/////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#define MAX 1005
#define max(a,b) a>b?a:b
typedef struct Ju {
    int c, k;
} R;
int comp(const void *a, const void *b) {
    //struct Ju
    R *e = (Ju *)a;
    //struct Ju
    R *f = (Ju *)b;
    if(e->c != f->c)
        return e->c - f->c;
    else
        return e->k - f->k;
}
int main() {
    R a[MAX];
    int f[MAX];
    int N, n, i, j;
    scanf("%d", &N);
    while(N--) {
        scanf("%d", &n);
        int tt;
        for(i = 0; i < n; i++) {
            scanf("%d%d", &a[i].c, &a[i].k);
            if(a[i].k > a[i].c) {
                tt = a[i].c;
                a[i].c = a[i].k;
                a[i].k = tt;
            }
        }
        qsort(a, n, sizeof(a[0]), comp);
        //    for(i=0;i<n;i++)
        //    printf("[%d %d]\n",a[i].c,a[i].k);
        for(i = 0; i <= n; i++) {
            f[i] = 1;
            for(j = 0; j < i; j++) {
                if(i == n || (a[i].c > a[j].c && a[i].k > a[j].k))
                    f[i] = max(f[i], f[j] + 1);
            }
        }
        printf("%d\n", f[n] - 1);
    }
    return 0;
}