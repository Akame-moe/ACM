/*
----------description----------
求a的b次方对c取余的值


----------input----------
第一行输入一个整数n表示测试数据的组数（n<100）  
每组测试只有一行，其中有三个正整数a,b,c(1=


----------output----------
输出a的b次方对c取余之后的结果


----------sample_input----------
3

2 3 5

3 100 10

11 12345 12345
----------sample_putput----------
3

1

10481
*/
/////////////////////////////
#include<stdio.h>
int main()
{
    int N;
    long long  a,b,c;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%lld%lld%lld",&a,&b,&c);
        long long temp=1;
        a%=c;
        while(b>0)
        {
            
            if(b%2==1)
            {
                temp=(temp*a)%c;
            }
            b/=2;
            a=(a*a)%c;
        
        }
        printf("%lld\n",temp);
    }
    return 0;
}