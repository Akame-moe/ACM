/*
----------description----------
写一个程序，找出给出素数范围内的所有孪生素数的组数。一般来说，孪生素数就是指两个素数距离为2，近的不能再近的相邻素数。有些童鞋一看到题就开始写程序，不仔细看题，咱们为了遏制一下读题不认真仔细的童鞋，规定，两个素数相邻为1的也成为孪生素数。


----------input----------
第一行给出N(0 接下来组测试数据给出m，表示找出m之前的所有孪生素数。
(0<m<1000000)


----------output----------
每组测试数据输出占一行，该行为m范围内所有孪生素数组数。


----------sample_input----------
1

14
----------sample_putput----------
4
*/
/////////////////////////////
//26
#include<stdio.h>
#include<string.h>
//#include<time.h>
#define range 1000005
bool IsPrime[range];
int count;
int prime[range];
void set() {
    int i, j;
    //for(i=0;i<range;++i)
    //    IsPrime[i]=true;
    memset(IsPrime, true, range);
    IsPrime[0] = IsPrime[1] = false;
    for(i = 2; i < range; i++) {
        if(IsPrime[i]) {
            for(j = 2 * i; j < range; j += i)
                IsPrime[j] = false;
        }
    }
    prime[0] = 2;
    j = 1;
    for(i = 3; i < range; i += 2)
        if(IsPrime[i]) {
            prime[j++] = i;
            //printf("%d ",i);
        }
    count = j;
    return ;
}

int main() {
    void set();
    //double f=clock(),s;
    int T;
    int n;
    int sum;
    int i;
    int t;
    set();
    //printf("%0.3lf",(clock()-f)/1000.0);
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        sum = 0;
        for(i = 1; prime[i] <= n && i < count; i++) {
            t = prime[i] - prime[i - 1];
            if(t == 1 || t == 2 )
                sum++;
        }
        printf("%d\n", sum);
    }
    return 0;
}
