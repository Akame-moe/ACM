/*
----------description----------
给定整数a1、a2、.......an，判断是否可以从中选出若干数，使它们的和恰好为K。


----------input----------
首先，n和k，n表示数的个数，k表示数的和。
接着一行n个数。
（1<=n<=20,保证不超int范围）


----------output----------
如果和恰好可以为k，输出“YES”，并按输入顺序依次输出是由哪几个数的和组成，否则“NO”


----------sample_input----------
4 13

1 2 4 7
----------sample_putput----------
YES

2 4 7
*/
/////////////////////////////
#include<iostream>

using namespace std;

int n, k, w[22], sum[22];
bool vis[22], flag;
void dfs(int cur, int cnt) {
    if (cur >= 0 && !flag) {
        if (cnt + sum[cur] < k)
            return;
        if (cnt + w[cur] <= k) {
            vis[cur] = true;
            dfs(cur - 1, cnt + w[cur]);
            vis[cur] = false;
        }
        dfs(cur - 1, cnt);
        if (cnt == k && !flag) {
            flag = true;
            cout << "YES" << endl;
            for (int i = 1; i <= n; i++) {
                if (vis[i])
                    cout << w[i] << ' ';
            }
            cout << endl;
        }
    }
}

int main() {
    while (cin >> n >> k) {
        flag = false;
        for (int i = 1; i <= n; i++) {
            cin >> w[i];
            sum[i] = sum[i - 1] + w[i];
        }
        dfs(n, 0);
        if (!flag)
            cout << "NO" << endl;
    }
    return 0;
}

简单的深搜
#include <stdio.h>
int n, k, ok, arr[22], vis[22], count;

void DFS(int pos) {
    if(count >= k) {
        if(count == k) {
            if(!ok) {
                ok = 1;
                printf("YES\n");
            }
            for(int i = 0; i < n; ++i)
                if(vis[i]) printf("%d ", arr[i]);
            printf("\n");
        }
        return;
    }

    for(int i = pos; i < n; ++i) {
        count += arr[i];
        vis[i] = 1;
        DFS(i + 1);
        count -= arr[i];
        vis[i] = 0;
    }
}

int main() {
    while(scanf("%d%d", &n, &k) == 2) {
        ok = 0;
        for(int i = 0; i < n; ++i) {
            scanf("%d", arr + i);
            vis[i] = 0;
        }
        count = 0;
        DFS(0);
        if(!ok) printf("NO\n");
    }
    return 0;
}
