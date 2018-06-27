/*
----------description----------
南阳理工学院要进行用电线路改造，现在校长要求设计师设计出一种布线方式，该布线方式需要满足以下条件：
1、把所有的楼都供上电。
2、所用电线花费最少


----------input----------
第一行是一个整数n表示有n组测试数据。(n<5)
每组测试数据的第一行是两个整数v,e.
v表示学校里楼的总个数(v<=500)
随后的e行里，每行有三个整数a,b,c表示a与b之间如果建铺设线路花费为c(c<=100)。（哪两栋楼间如果没有指明花费，则表示这两栋楼直接连通需要费用太大或者不可能连通）
随后的1行里，有v个整数,其中第i个数表示从第i号楼接线到外界供电设施所需要的费用。( 0
（楼的编号从1开始），由于安全问题，只能选择一个楼连接到外界供电设备。
数据保证至少存在一种方案满足要求。


----------output----------
每组测试数据输出一个正整数,表示铺设满足校长要求的线路的最小花费。


----------sample_input----------
1

4 6

1 2 10

2 3 10

3 1 10

1 4 1

2 4 1

3 4 1

1 3 5 6
----------sample_putput----------
4
*/
/////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include<algorithm>
#define min(a,b) a>b?b:a
using namespace std;
int L[502];
int father[502];
struct P {
    int val;
    int v1, v2;
} a[130000];
void work();
int v, e;
int sum;
int comp(const void *a, const void *b) {
    P *c = (P *)a;
    P *d = (P *)b;
    return c->val - d->val;
}
int main() {
    int T;
    int i;
    scanf("%d", &T);
    while(T--) {
        memset(father, 0, sizeof(father));
        scanf("%d%d", &v, &e);
        for(i = 0; i < e; i++)
            scanf("%d %d %d", &a[i].v2, &a[i].v1, &a[i].val);
        for(i = 0; i < v; i++)
            scanf("%d", &L[i]);
        sum = 0;
        qsort(a, e, sizeof(a[0]), comp);
        work();
        printf("%d\n", sum + *min_element(L, L + v));

    }
    return 0;
}
int find(int x) {
    if(x != father[x]) father[x] = find(father[x]);
    return father[x];
}
void work() {
    int i;
    for(i = 1; i <= v; i++)
        father[i] = i;
    for(i = 0; i < e; i++) {
        int t = find(a[i].v1);
        int tt = find(a[i].v2);
        if(t != tt) {
            sum += a[i].val;
            father[t] = tt;
        }
    }
}
/*krakusl算法
#include <iostream>#include <cstdio>#include <cstring>#include <cstdlib>#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
#define LL long long
using namespace std;
struct ARC{
    int x,y,c;
};
ARC e[130000];
int d[510],uf[510];
bool cmp(const ARC &a,const ARC &b){
    return a.c < b.c;
}
int findPa(int x){
    if(x != uf[x]) uf[x] = findPa(uf[x]);
    return uf[x];
}
int main(){
    int k,i,j,n,v,theMin,temp,ans;
    scanf("%d",&k);
    while(k--){
        scanf("%d %d",&n,&v);
        for(i = 0; i < v; i++) scanf("%d %d %d",&e[i].x,&e[i].y,&e[i].c);
        sort(e,e+v,cmp);
        theMin = INT_MAX>>2;
        for(i = 0; i < n; i++){
            scanf("%d",&temp);
            if(temp < theMin) theMin = temp;
        }
        for(i = 0; i < 510; i++) uf[i] = i;
        for(ans = i = 0; i < v; i++){
            int x = findPa(e[i].x);
            int y = findPa(e[i].y);
            if(x != y){
                ans += e[i].c;
                uf[x] = y;
            }
        }
        printf("%d\n",theMin+ans);
    }
    return 0;
}*/

///pime算法
#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;
const int INF = INT_MAX;
int d[505], mp[505][505], n, m;
bool in[505];
int prim() {
    int i, j, index, temp, ans;
    for(ans = i = 0; i <= n; i++) d[i] = INF;
    memset(in, false, sizeof(in));
    for(d[1] = i = 0; i < n; i++) {
        temp = INF;
        for(j = 1; j <= n; j++) {
            if(!in[j] && d[j] < temp) temp = d[index = j];
        }
        ans += temp;
        in[index] = true;
        for(j = 1; j <= n; j++)
            if(!in[j] && d[j] > mp[index][j]) d[j] = mp[index][j];
    }
    return ans;
}
int main() {
    int ks, i, j, u, v, w, theMin;
    scanf("%d", &ks);
    while(ks--) {
        scanf("%d%d", &n, &m);
        for(i = 0; i <= n; i++) {
            for(j = 0; j <= n; j++)
                mp[i][j] = INF;
        }
        for(i = 0; i < m; i++) {
            scanf("%d%d%d", &u, &v, &w);
            if(mp[u][v] > w) mp[u][v] = mp[v][u] = w;
        }
        theMin = INF;
        for(i = 0; i < n; i++) {
            scanf("%d", &w);
            if(theMin > w) theMin = w;
        }
        printf("%d\n", theMin + prim());
    }
    return 0;
}