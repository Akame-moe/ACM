/*
----------description----------
Shiva得到了两个只有加号和减号的字符串，字串长度相同。Shiva一次可以把一个加号和它相邻的减号交换。他想知道最少需要多少次操作才能把第一个字符串变换成第二个字符串。你现在要去帮助他完成那个这个问题。


----------input----------
多组测试数据

每组数据有两行，每行包含一个由”+”和”-“最成的字符串。每个子符串长度不超过5000。


----------output----------
仅一个整数，输出最少需要操作的次数。如果答案不存在，输出-1。


----------sample_input----------
++-+--+

-++--++
----------sample_putput----------
4
*/
/////////////////////////////
#include<stdio.h>
#include<string.h>
#include<math.h>
int main() {
    int len1, len2;
    char s1[5001];
    char s2[5001];
    int sum;
    int flag;
    int count1, count2;
    int i, j;
    int l;
    while(scanf("%s%s", s1, s2) != EOF) {
        len1 = strlen(s1);
        len2 = strlen(s2);
        count1 = count2 = 0;
        for(i = 0; i < len1; i++) {
            if(s1[i] == '+')
                count1++;
            if(s2[i] == '+')
                count2++;
        }
        flag = 1;
        if((len1 != len2) || (count1 != count2))
            flag = 0;
        else {
            sum = 0;
            l = 0;
            for(i = 0; i < len1; i++) {
                if(s1[i] == '+') {
                    for(j = l; j < len1; j++) {
                        if(s2[j] == '+') {
                            sum += (fabs(i - j));
                            s2[j] = '-';
                            l = j;
                            break;
                        }
                    }
                }
            }
        }
        if(flag)
            printf("%d\n", sum);
        else
            printf("-1\n");
    }
    return 0;
}
