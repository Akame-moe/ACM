/*
----------description----------
请在整数 n 中删除m个数字, 使得余下的数字按原次序组成的新数最大，

比如当n=92081346718538，m=10时，则新的最大数是9888


----------input----------
第一行输入一个正整数T，表示有T组测试数据
每组测试数据占一行，每行有两个数n,m（n可能是一个很大的整数，但其位数不超过100位，并且保证数据首位非0，m小于整数n的位数）


----------output----------
每组测试数据的输出占一行，输出剩余的数字按原次序组成的最大新数


----------sample_input----------
2

92081346718538 10

1008908 5
----------sample_putput----------
9888

98
*/
/////////////////////////////
#include<stdio.h>
#include<string.h>
#include<math.h>
int main() {
    char s1[105];
    char s2[105];
    int T;
    int m;
    int i, j, loc;
    int len;
    int t;
    scanf("%d", &T);
    while(T--) {
        scanf("%s %d", s1, &m);
        len = strlen(s1);
        j = 0;
        loc = 0;
        for(t = m; t <= len - 1; t++) {
            s2[j] = s1[loc];
            for(i = loc; i <= t; i++) {
                if(s1[i] > s2[j]) {
                    s2[j] = s1[i];
                    loc = i;
                }

            }
            loc++;
            j++;
        }
        s2[j] = '\0';
        printf("%s\n", s2);
    }


    return 0;
}
