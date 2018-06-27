/*
----------description----------
有一个牧场，牧场上有很多个供水装置，现在牧场的主人想要用篱笆把这些供水装置圈起来，以防止不是自己的牲畜来喝水，各个水池都标有各自的坐标，现在要你写一个程序利用最短的篱笆将这些供水装置圈起来！（篱笆足够多，并且长度可变）


----------input----------
第一行输入的是N,代表用N组测试数据（1<=N<=10）
第二行输入的是m,代表本组测试数据共有m个供水装置（3<=m<=100）
接下来m行代表的是各个供水装置的横纵坐标


----------output----------
输出各个篱笆经过各个供水装置的坐标点，并且按照x轴坐标值从小到大输出，如果x轴坐标值相同，再安照y轴坐标值从小到大输出


----------sample_input----------
1

4

0 0

1 1

2 3

3 0
----------sample_putput----------
0 0

2 3

3 0
*/
/////////////////////////////
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>
#include<iostream>
using namespace std;
typedef struct Point {
    int x, y;
} P;
int q[105];//zhan
P a[105], b[105];
int top;
void _swap(int u, int uu) {
    P t = a[u];
    a[u] = a[uu];
    a[uu] = t;
}
double dis(P p1, P p2) {
    return sqrt(pow(fabs((double)p1.x - p2.x), 2) + pow(fabs((double)p1.y - p2.y), 2));
}
int xchen(P p, P p1, P p2) { //左转关系判定。大于0就是。
    return (p1.x - p.x) * (p2.y - p.y) - (p1.y - p.y) * (p2.x - p.x);
}
int comp(const void *x, const void *y) {
    int t = xchen(a[0], *(P *)x, *(P *)y);
    if(t == 0)
        return dis(*(P *)x, a[0]) - dis(*(P *)y, a[0]) > 0 ? 1 : -1;
    else
        return t;
}
int _comp(const void *c, const void *d) {
    P x = *(P *)c;
    P y = *(P *)d;
    if(x.x != y.x)
        return x.x - y.x;
    else
        return x.y - y.y;
}
int main() {
    int N, i, n, j;
    scanf("%d", &N);
    while(N--) {
        scanf("%d", &n);
        int tt = INT_MAX;
        int loc = 0;
        for(i = 0; i < n; i++) {
            cin >> a[i].x >> a[i].y;
            if(a[i].y < tt || (a[i].y == tt && a[i].x <= a[loc].x)) {
                tt = a[i].y;
                loc = i;
            }
        }
        _swap(0, loc);
        qsort(a + 1, n - 1, sizeof(a[0]), comp);
//        for(i=0;i<n;i++)
//        cout<<a[i].x<<"..."<<a[i].y<<endl;
        top = 1;
        q[0] = 0;
        q[1] = 1;
        for(i = 2; i < n; i++) {
            while(top >= 1 && xchen(a[q[top - 1]], a[q[top]], a[i]) > 0) top--;
            q[++top] = i;
        }
        for(i = 0, j = 0; i <= top; i++, j++)
            b[j] = a[q[i]];
        qsort(b, top + 1, sizeof(b[0]), _comp);
        for(i = 0; i <= top; i++)
            cout << b[i].x << " " << b[i].y << endl;
    }
    return 0;
}


