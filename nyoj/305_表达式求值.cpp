/*
----------description----------
Dr.Kong设计的机器人卡多掌握了加减法运算以后，最近又学会了一些简单的函数求值，比如，它知道函数min(20,23)的值是20 ，add(10,98)
的值是108等等。经过训练，Dr.Kong设计的机器人卡多甚至会计算一种嵌套的更复杂的表达式。

假设表达式可以简单定义为:

1\. 一个正的十进制数 x 是一个表达式。

2\. 如果 x 和 y 是 表达式，则 函数min(x,y )也是表达式,其值为x,y 中的最小数。

3\. 如果 x 和 y 是 表达式，则 函数max(x,y )也是表达式,其值为x,y 中的最大数。

4．如果 x 和 y 是 表达式，则 函数add(x,y )也是表达式,其值为x,y 之和。

例如， 表达式 max(add(1,2),7) 的值为 7。

请你编写程序，对于给定的一组表达式，帮助 Dr.Kong 算出正确答案，以便校对卡多计算的正误。


----------input----------
第一行： N 表示要计算的表达式个数 （1≤ N ≤ 10）
接下来有N行， 每行是一个字符串，表示待求值的表达式
（表达式中不会有多余的空格，每行不超过300个字符，表达式中出现的十进制数都不
超过1000。）


----------output----------
输出有N行，每一行对应一个表达式的值。


----------sample_input----------
3

add(1,2)

max(1,999)

add(min(1,1000),add(100,99))
----------sample_putput----------
3

999

200
*/
/////////////////////////////
#include<stdio.h>
#include<stdlib.h>
#include<stack>
using namespace std;
int calculate(int, int, int);
stack<int> ops;//add==0  max==1  min==2;
stack<int> ovs;
int main() {
    char s[305];
    int N, i, len, num1, num2, op;
    scanf("%d", &N);
    while(N--) {
        scanf("%s", s);
        //len=strlen(s);
        for(i = 0; s[i] != '\0';) {
            if(s[i] >= '0' && s[i] <= '9') {
                int num = s[i++] - '0';
                while(s[i] >= '0' && s[i] <= '9')
                    num = num * 10 + (s[i++] - '0');
                ovs.push(num);
                //printf("num=%d]",ovs.top());
            } else if(s[i] == 'a' && s[i + 1] == 'd') {
                ops.push(0);
                i += 4;
            } else if(s[i] == 'm' && s[i + 1] == 'a') {
                ops.push(1);
                i += 4;
            } else if(s[i] == 'm' && s[i + 1] == 'i') {
                ops.push(2);
                i += 4;
            } else if(s[i] == ')') {
                num2 = ovs.top();
                ovs.pop();
                num1 = ovs.top();
                ovs.pop();
                op = ops.top();
                ops.pop();
                ovs.push(calculate(num1, op, num2));
                //printf("<%d>",ovs.top());
                i++;
            } else
                i++;

        }
        while(ovs.size() != 1) {

            num2 = ovs.top();
            ovs.pop();
            num1 = ovs.top();
            ovs.pop();
            op = ops.top();
            ops.pop();
            ovs.push(calculate(num1, op, num2));
        }
        printf("%d\n", ovs.top());
        ovs.pop();
    }
    return 0;
}
int calculate(int num1, int  op, int num2) {
    switch(op) {
    case 0:
        return num1 + num2;
    case 1:
        return num1 > num2 ? num1 : num2;
    case 2:
        return num1 > num2 ? num2 : num1;
    default :
        printf("error!\n");
        exit(1);
    }
    return -1;
}