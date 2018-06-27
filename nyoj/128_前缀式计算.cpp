/*
----------description----------
先说明一下什么是中缀式：

如2+(3+4)*5这种我们最常见的式子就是中缀式。

而把中缀式按运算顺序加上括号就是：(2+((3+4)*5))

然后把运算符写到括号前面就是+(2 *( +(3 4) 5) )

把括号去掉就是：+ 2 * + 3 4 5

最后这个式子就是该表达式的前缀表示。

给你一个前缀表达式，请你计算出该前缀式的值。

比如：

\+ 2 * + 3 4 5的值就是 37


----------input----------
有多组测试数据，每组测试数据占一行，任意两个操作符之间，任意两个操作数之间，操作数与操作符之间都有一个空格。输入的两个操作数可能是小数，数据保证输入的数都是正数，并且都小于10，操作数数目不超过500。
以EOF为输入结束的标志。


----------output----------
对每组数据，输出该前缀表达式的值。输出结果保留两位小数。


----------sample_input----------
+ 2 * + 3 4 5

+ 5.1 / 3 7
----------sample_putput----------
37.00

5.53
*/
/////////////////////////////
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stack>
using namespace std;
stack<double> ovs;
char *strr(char *);
double c(double, char, double);
char s[1500];
char sss[50];
int main() {
    //freopen("d:\\data\\1.txt","r",stdin);

    char w[50];
    double num1, num2;
    while(gets(s) != NULL) {
        int len = strlen(s);
        int i;
        for(i = len - 1; i >= 0;) {
            if(s[i] >= '0' && s[i] <= '9') {
                int j = 0;
                w[j++] = s[i--];
                while(s[i] != ' ')
                    w[j++] = s[i--];
                w[j] = '\0';
                strr(w);
                ovs.push(atof(sss));
                //printf("w[]=%s    sss=%s  %lf     %lf\n",w,sss,atof(w),ovs.top());
                i--;
            } else if(s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-') {
                num1 = ovs.top();
                ovs.pop();
                num2 = ovs.top();
                ovs.pop();//printf("%lf %c %lf=",num1,s[i],num2);
                ovs.push(c(num1, s[i], num2));
                //    printf("%lf\n",ovs.top());
                i -= 2;
            } else
                i--;
        }

        //printf("size=%d\n",ovs.size());
        /*
                while(ovs.size()!=1)//跳出循环后ovs栈必为一个数
                {
                    num1=ovs.top();ovs.pop();
                    num2=ovs.top();ovs.pop();
                    ovs.push(c(num1,s[i],num2));
                }
        */
        printf("%.2lf\n", ovs.top());
        ovs.pop();

    }
    return 0;
}
double c(double num1, char op, double num2) {
    switch(op) {
    case '*':
        return num1 * num2;
    case '/':
        return num1 / num2;
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    default :
        printf("ni ma!\n");
        exit(1);
    }
}
char* strr(char *s) {
    int i, j, len = strlen(s);
    char ss[50];
    for(j = len - 1, i = 0; j >= 0; j--, i++) {
        ss[i] = s[j];
    }
    ss[i] = '\0'; //printf("s[]=%s,ss=%s\n",s,ss);
    strcpy(sss, ss);
    return ss;
}
//最短的式子
#include <stdlib.h>
#include <stdio.h>
float cc() {
    float res;
    char c[20];
    if(scanf("%s", c) == -1)
        exit(0);
    switch(c[0]) {
    case '+':
        return cc() + cc();
    case '-':
        return cc() - cc();
    case '*':
        return cc() * cc();
    case '/':
        return cc() / cc();
    default:
        sscanf(c, "%f", &res);
    }
    return res;
}
int main() {
    while(1) {
        printf("%.2f\n", cc());
    }
}
#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<cstdio>
#define N 510
using namespace std;

char a[N];

double exp() {
    char ch[10];
    sscanf(a, "%s", ch);
    int len = strlen(ch);
    strcpy(a, a + len + 1);
    switch(ch[0]) {
    case '+':
        return exp() + exp();
    case '-':
        return exp() - exp();
    case '*':
        return exp() * exp();
    case '/':
        return exp() / exp();
    default :
        return atof(ch);
    }
}

int main() {
    double ans;
    while(gets(a)) {
        ans = exp();
        printf("%0.2lf\n", ans);
    }
    return 0;
}

