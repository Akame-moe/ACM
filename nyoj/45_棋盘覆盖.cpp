/*
----------description----------
在一个2k×2k（1<=k<=100）的棋盘中恰有一方格被覆盖，如图1（k=2时），现用一缺角的2×2方格（图2为其中缺右下角的一个），去覆盖2k×2k未被覆盖过的方格，求需要类似图2方格总的个数s。如k=1时，s=1;k=2时，s=5

图1

__

|

__

|

__

|

__

---|---|---|---

__

|

__

|

__

|

__

__

|

__

|

__

|

__

__

|

__

|

__

|

__

图2

__

|

__

---|---

__

|


----------input----------
第一行m表示有m组测试数据；
每一组测试数据的第一行有一个整数数k;


----------output----------
输出所需个数s;


----------sample_input----------
3

1

2

3
----------sample_putput----------
1

5

21
*/
/////////////////////////////
//标程
#include<iostream>
#include<string.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    while(n--) {
        int a[100];
        memset(a, 0, sizeof(a));
        int size;
        cin >> size;
        a[0] = 1;
        if(size == 1)
            cout << a[0] << endl;
        int i, j, k;
        for(i = 2; i <= size; ++i) {
            for(j = 0; j < 100; ++j)
                a[j] = 4 * a[j];
            a[0]++;
            for(j = 0; j < 99; ++j) {
                a[j + 1] += a[j] / 10;
                a[j] = a[j] % 10;
            }
        }
        for(i = 99; i >= 0; --i)
            if(a[i]) break;
        for(j = i; j >= 0; --j)
            cout << a[j];
        cout << endl;
    }
    return 0;
}
//我的程序
#include<stdio.h>
int main() {
    int N;
    int k;
    int i, j, len;
    int temp, jw;
    scanf("%d", &N);
    while(N--) {
        int a[100] = {0};
        scanf("%d", &k);
        len = 1;
        a[1] = 1;
        for(i = 1; i <= k; i++) {
            jw = 0;
            for(j = 1; j <= len; j++) {
                temp = a[j] * 4 + jw;
                a[j] = temp % 10;
                jw = temp / 10;
                if(j == len && jw != 0)
                    len++;
            }
        }
        temp = 0;
        for(i = len; i >= 1; i--) {
            temp = temp * 10 + a[i];
            a[i] = temp / 3;
            temp = temp % 3;
        }
        while(a[len] == 0)
            len--;
        for(i = len; i >= 1; i--)
            printf("%d", a[i]);
        printf("\n");
    }
    return 0;
}

