/*
----------description----------
南阳理工学院校园里有一些小河和一些湖泊，现在，我们把它们通一看成水池，假设有一张我们学校的某处的地图，这个地图上仅标识了此处是否是水池，现在，你的任务来了，请用计算机算出该地图中共有几个水池。


----------input----------
第一行输入一个整数N，表示共有N组测试数据
每一组数据都是先输入该地图的行数m(0<m<100)与列数n(0<n<100)，然后，输入接下来的m行每行输入n个数，表示此处有水还是没水（1表示此处是水池，0表示此处是地面）


----------output----------
输出该地图中水池的个数。
要注意，每个水池的旁边（上下左右四个位置）如果还是水池的话的话，它们可以看做是同一个水池。


----------sample_input----------
2

3 4

1 0 0 0

0 0 1 1

1 1 1 0

5 5

1 1 1 1 0

0 0 1 0 1

0 0 0 0 0

1 1 1 0 0

0 0 1 1 1
----------sample_putput----------
2

3
*/
/////////////////////////////
#include<stdio.h>
int a[101][101];
int max;
int x, y;
int main() {
    int N;
    int i, j;
    void dfs(int, int);
    scanf("%d", &N);
    while(N--) {
        scanf("%d%d", &x, &y);
        for(i = 0; i < x; i++)
            for(j = 0; j < y; j++)
                scanf("%d", &a[i][j]);
        max = 0;
        for(i = 0; i < x; i++)
            for(j = 0; j < y; j++) {
                if(a[i][j] == 1) {
                    dfs(i, j);
                    max++;
                }
            }
        printf("%d\n", max);

    }
    return 0;
}
void dfs(int i, int j) {
    if(a[i][j] == 0 || a[i][j] == 2 || i < 0 || j < 0 || i >= x || j >= y)
        return ;
    a[i][j] = 2;
    if(a[i + 1][j] == 1) dfs(i + 1, j);
    if(a[i][j + 1] == 1) dfs(i, j + 1);
    if(a[i - 1][j] == 1) dfs(i - 1, j);
    if(a[i][j - 1] == 1) dfs(i, j - 1);

}