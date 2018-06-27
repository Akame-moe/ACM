/*
----------description----------
zyc从小就比较喜欢玩一些小游戏，其中就包括画一笔画，他想请你帮他写一个程序，判断一个图是否能够用一笔画下来。

规定，所有的边都只能画一次，不能重复画。


----------input----------
第一行只有一个正整数N(N<=10)表示测试数据的组数。
每组测试数据的第一行有两个正整数P,Q(P<=1000,Q<=2000)，分别表示这个画中有多少个顶点和多少条连线。（点的编号从1到P）
随后的Q行，每行有两个正整数A,B(0<A,B<P)，表示编号为A和B的两点之间有连线。


----------output----------
如果存在符合条件的连线，则输出"Yes",
如果不存在符合条件的连线，输出"No"。


----------sample_input----------
2

4 3

1 2

1 3

1 4

4 5

1 2

2 3

1 3

1 4

3 4
----------sample_putput----------
No

Yes
*/
/////////////////////////////
#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
vector <int > v[1005];
int cnt;
bool vis[1005];
void dfs(int k) {
    int i;
    for(i = 0; i < v[k].size(); i++) {
        int t = v[k][i];
        if(!vis[t]) {
            vis[t] = true;
            cnt++;
            dfs(t);
        }
    }
}
int main() {
    int N, n, m, a, b, i;
    scanf("%d", &N);
    while(N--) {
        memset(vis, false, sizeof(vis));
        scanf("%d%d", &n, &m);
        while(m--) {
            scanf("%d%d", &a, &b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        vis[b] = true;
        cnt = 1;
        dfs(b);
        int count = 0;
        if(cnt == n) {
            for(i = 1; i <= n; i++) {

                if(v[i].size() & 1) count++;
                v[i].clear();
            }
        }
        printf("%s\n", (count == 0 || count == 2) && cnt == n ? "Yes" : "No");
    }
    return 0;
}