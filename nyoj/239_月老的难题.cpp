/*
----------description----------
月老准备给n个女孩与n个男孩牵红线，成就一对对美好的姻缘。

现在，由于一些原因，部分男孩与女孩可能结成幸福的一家，部分可能不会结成幸福的家庭。

现在已知哪些男孩与哪些女孩如果结婚的话，可以结成幸福的家庭，月老准备促成尽可能多的幸福家庭，请你帮他找出最多可能促成的幸福家庭数量吧。

假设男孩们分别编号为1~n,女孩们也分别编号为1~n。


----------input----------
第一行是一个整数T,表示测试数据的组数(1<=T<=400)
每组测试数据的第一行有两个整数n,K，其中男孩的人数与女孩的人数都是n。(n<=500,K<=10 000)
随后的K行，每行有两个整数i,j表示第i个男孩与第j个女孩有可能结成幸福的家庭。(1<=i,j<=n)


----------output----------
对每组测试数据，输出最多可能促成的幸福家庭数量


----------sample_input----------
1

3 4

1 1

1 3

2 2

3 2
----------sample_putput----------
2
*/
/////////////////////////////
#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
#define MAX 502
int mat[MAX];
bool used[MAX];
vector<int > v[MAX];
int n;
bool crosspath(int k) {
    int i;
    for(i = 0; i < v[k].size(); i++) {
        int t = v[k][i];
        if(!used[t]) {
            used[t] = true;
            if(mat[t] == 0 || crosspath(mat[t])) {
                mat[t] = k;
                return true;
            }
        }
    }
    return false;
}
int main() {
    int N;
    int a, b, k, i;
    scanf("%d", &N);
    while(N--) {
        scanf("%d%d", &n, &k);
        for(i = 0; i < k; i++) {
            scanf("%d%d", &a, &b);
            v[a].push_back(b);
        }
        int match = 0;
        memset(mat, 0, sizeof(mat));
        for(i = 1; i <= n; i++) {
            memset(used, false, sizeof(used));
            if(crosspath(i))
                match++;
        }
        for(i = 0; i <= n; i++)
            v[i].clear();
        printf("%d\n", match);
    }
    return 0;
}




