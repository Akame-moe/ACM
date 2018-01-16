/*
----------description----------
判断：两个数x、y的正负性。

要求：不可以使用比较运算符，即"<",">","<=",">=","==","!="。

![](/JudgeOnline/admin/kind/attached/20140801095811_84190.jpg)


----------input----------
有多组数据，每组数据占一行，每一行两个数x，y。  
x、y保证在int范围内。  


----------output----------
每组数据输出占一行。  
如果两个数是一正一负，输出"Signs are opposite"  
如果是同为正或同为负，输出"Signs are not opposot"  
如果无法确定，输出"Signs can't be sure"  
输出不包括引号  


----------sample_input----------
1 1

-1 1
----------sample_putput----------
Signs are not opposot

Signs are opposite
*/
/////////////////////////////
#include<stdio.h>
int main()
{
    int a,b;
    while(~scanf("%d%d",&a,&b))
    {
        if(!(a*b))
            printf("Signs can't be sure\n");
        else
        {
            a=a>>31;
            b=b>>31;
            if(a&&b || !a&&!b)
                printf("Signs are not opposot\n");
            else
                printf("Signs are opposite\n");
        }
    }
    return 0;
}        
        //1071