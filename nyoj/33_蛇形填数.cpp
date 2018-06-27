/*
----------description----------
在n*n方陈里填入1,2,...,n*n,要求填成蛇形。例如n=4时方陈为：
10 11 12 1
9 16 13 2
8 15 14 3
7 6 5 4


----------input----------
直接输入方陈的维数，即n的值。(n<=100)


----------output----------
输出结果是蛇形方陈。


----------sample_input----------
3
----------sample_putput----------
7 8 1

6 9 2

5 4 3
*/
/////////////////////////////
#include<stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int i, j;
    int k = 1;
    int t;
    static int a[101][101];
    j = n;
    i = 1;
    if(n == 1)
        printf("1\n");
    else {
        for(t = 1; t <= (n + 1) / 2; t++) {
            while(!a[i][j] && i <= n) {
                a[i++][j] = k++;
            }
            i--;
            j--;
            while(!a[i][j] && j >= 1) {
                a[i][j--] = k++;
            }
            j++;
            i--;
            while(!a[i][j] && i >= 1 ) {
                a[i--][j] = k++;
            }
            i++;
            j++;
            while(!a[i][j] ) {
                a[i][j++] = k++;
            }
            j--;
            i++;
        }

        for(i = 1; i <= n; i++) {
            for(j = 1; j <= n; j++)
                printf("%d ", a[i][j]);
            printf("\n");
        }
    }
    return 0;
}