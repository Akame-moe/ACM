/*
----------description----------
光棍们，今天是光棍节。聪明的NS想到了一个活动来丰富这个光棍节。

规则如下：

每个光棍在一个纸条上写一个自己心仪女生的名字，然后把这些纸条装进一个盒子里，这些光
棍依次抽取一张纸条，如果上面的名字就是自己心仪的女生，那么主持人就在现场给该女生打电话，告诉这个光棍对她的爱慕之情，并让光棍当场表白，并得到现场所有人的祝福，没抽到的，嘿嘿就可以幸免了。

假设一共有N个光棍,其中有M个没有抽到自己的纸条,求发生这种情况一共有多少种可能.。


----------input----------
每行包含两个整数N和M(1<M<=N<=20)，以EOF结尾。


----------output----------
对于每个测试实例，请输出一共有多少种发生这种情况的可能，每个实例的输出占一行。


----------sample_input----------
2 2

3 2
----------sample_putput----------
1

3
*/
/////////////////////////////
//vc下不通过。结果却ac
#include<stdio.h>
int fun(int n, int m) {
    int i, j;
    m = (n - m) > m ? m : n - m; //优化
    long long t1, t2;
    t1 = t2 = 1;
    for(i = n, j = 1; i > n - m; --i, ++j) { //求n个人中选m个人的组合数，即CnM
        t1 *= i;
        t2 *= j;
    }
    return t1 / t2;
}
int main() {
    int m, n, i;
    long long a[21] = {0, 0, 1};
    for(i = 3; i < 21; ++i)
        a[i] = (i - 1) * (a[i - 2] + a[i - 1]); //a[i]存储i个人的错排
    while(scanf("%d%d", &n, &m) != EOF) {
        printf("%lld\n", fun(n, m)*a[m]);
    }
    return 0;
}

//451
#include<stdio.h>
#include<iostream>
long long  int f[21];
using namespace std;
void fun() {
    int i;
    f[0] = 1;
    f[1] = 1;
    f[2] = 2;
    for(i = 3; i <= 20; i++)
        f[i] = i * f[i - 1];
    return ;
}
int main() {
    void fun();
    int n, m;
    long long int a[25];
    int i;
    a[0] = 0;
    a[1] = 0;
    a[2] = 1;
    fun();
    for(i = 3; i <= 21; i++)
        a[i] = (i - 1) * (a[i - 1] + a[i - 2]);
    while(scanf("%d%d", &n, &m) != EOF) {
        cout << f[n] / f[m] / f[n - m]*a[m] << endl;
    }
    return 0;
}
