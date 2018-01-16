/*
----------description----------
今天mdd看到这么一段话：在数论，对正整数n，欧拉函数是少于或等于n的数中与n互质的数的数目。此函数以其首名研究者欧拉命名，它又称为Euler's
totient function、φ函数、欧拉商数等。
例如φ(8)=4，因为1,3,5,7均和8互质。于是他想用计算机实现欧拉函数的功能，但是他又不想去写，你能帮帮他吗？

ps: _互质_ （relatively primeì）又叫互素。若N个整数的最大公因数是1，则称这N个整数 _互质_ 。


----------input----------
有多组测试数据组数小于1003，  
每组测试数据有一个整数n(0<n<=65535^2+1).


----------output----------
输出欧拉函数φ(n)的值。


----------sample_input----------
2

6

46
----------sample_putput----------
1

2

22
*/
/////////////////////////////
#include<stdio.h>
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int ret=1;
        int i;
        for(i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                n/=i;
                ret*=i-1;
                while(n%i==0)
                {
                    n/=i;
                    ret*=i;
                }
            }
        }
        if(n>1)
            ret*=n-1;
        printf("%d\n",ret);
    }
    return 0;
}