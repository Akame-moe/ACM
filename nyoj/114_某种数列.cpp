/*
----------description----------
数列A满足An = An-1 + An-2 + An-3, n >= 3  
编写程序，给定A0, A1 和 A2, 计算A99


----------input----------
输入包含多行数据  
每行数据包含3个整数A0, A1, A2 (0 <= A0, A1, A2 <= 100000000)  
数据以EOF结束


----------output----------
对于输入的每一行输出A99的值


----------sample_input----------
1 1 1
----------sample_putput----------
69087442470169316923566147
*/
/////////////////////////////
#include<stdio.h>
#include<string.h>
#define base  100000000
int a[100][100];
void t(int i,int n)
{
    a[i][1]=n;
}
int main()
{
    //freopen("d:\\data\\1.txt","r",stdin);
    int i,j,len,t1,t2,t3,temp,jw;
    while(scanf("%d%d%d",&t1,&t2,&t3)!=EOF)
    {
        if(t1==0 && t2==0 && t3==0)
            printf("0");
        else
        {
            memset(a,0,sizeof(a));
            t(0,t1);
            t(1,t2);
            t(2,t3);//将数转化为数组存储
            len=1;
            for(i=3;i<=99;i++)
            {
                jw=0;
                for(j=1;j<=len;j++)    
                {
                    temp=a[i-1][j]+a[i-2][j]+a[i-3][j]+jw;
                    a[i][j]=temp%base;
                    jw=temp/base;
                    if(j==len && jw!=0)
                        len++;
                }
            }
        //    printf("[[[%d  %d  %d",a[0][0],a[0][]);
            //while(a[99][len]==0)
                //len--;
            i=len;
            printf("%d",a[99][i--]);
            for(;i>=1;i--)
                printf("%08d",a[99][i]);
        }
        printf("\n");
    }
    return 0;

}