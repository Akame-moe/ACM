/*
----------description----------
xiaod现在正在某个球场负责网球的管理工作。为了方便管理，他把每个球都编了号，且每个编号的球的总个数都是偶数。有一天，xiaod发现少了一个球，你能帮他找出丢的那个球的球号吗？


----------input----------
有多组测试数据。每组数据包括两行。  
第一行是一个整数N(0 随后的一行是N个数，表示所剩的各个球的编号M(0<M<10^9)。


----------output----------
对于每组数据，输出弄丢的那个球的球号。


----------sample_input----------
5

1 1 3 6 6

3

1 2 1
----------sample_putput----------
3

2
*/
/////////////////////////////
//异或运算符的特点是：数a两次异或同一个数b（a=a^b^b）仍然为原值a.
#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int N;
    int i,num,a;
    while(~scanf("%d",&N))
    {
        num=0;
        for(i=0;i<N;i++)
        {
            scanf("%d",&a);
            num^=a;
        }
        cout<<num<<endl;
    }
    return 0;
}