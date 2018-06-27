/*
----------description----------
乱世天下，诸侯割据。每个诸侯王都有一片自己的领土。但是不是所有的诸侯王都是安分守己的，实力强大的诸侯国会设法吞并那些实力弱的，让自己的领土面积不断扩大。而实力弱的诸侯王为了不让自己的领土被吞并，他会联合一些其他同样弱小的诸侯国，组成联盟(联盟不止一个)，来共同抵抗那些强大的诸侯国。
强大的诸侯国为了瓦解这些联盟，派出了最优秀的间谍来离间他们，使一些诸侯国退出联盟。最开始，每个诸侯国是一个联盟。

有两种操作

1、U x y 表示x和y在同一个联盟。（0≤x，y）

2、D x 表示x退出联盟。


----------input----------
多组测试数据
第一行两个数，n和m（1 ≤ n≤ 10^5, 1 ≤ m ≤10^5），分别表示诸侯国的个数和操作次数。
接下来有m行操作


----------output----------
输出联盟的个数


----------sample_input----------
5 7

U 0 1

U 1 2

U 0 3

D 0

U 1 4

D 2

U 0 2

10 1

U 0 9
----------sample_putput----------
Case #1: 2

Case #2: 9
*/
/////////////////////////////
#include<stdio.h>
#include<string.h>
#define N 1000050
int father[N], d[N];
bool used[N];
int f(int i) {
    return father[i] == i ? i : father[i] = f(father[i]);
}

int main() {
    int m, n, a, b;
    register int i;
    char s[5];
    int z = 1;
    while(~scanf("%d%d", &n, &m)) {
        for(i = 0; i <= n; i++) {
            father[i] = i;
            d[i] = i;
        }
        int  c = n;
        int count = 0;
        while(m--) {
            scanf("%s", s);
            if(s[0] == 'U') {
                scanf("%d %d", &a, &b);
                int t = f(d[a]);
                int tt = f(d[b]);
                father[t] = tt;
            } else {
                scanf("%d", &a);
                father[c] = c;
                d[a] = c++;
            }
        }
        memset(used, false, sizeof(used));
        for(i = 0; i < n; i++) {
            int t = f(d[i]);
            if(!used[t]) {
                count++;
                used[t] = true;
            }
        }
        printf("Case #%d: %d\n", z++, count);
    }
    return 0;
}
