/*
----------description----------
现在有很多长方形，每一个长方形都有一个编号，这个编号可以重复；还知道这个长方形的宽和长，编号、长、宽都是整数；现在要求按照一下方式排序（默认排序规则都是从小到大）；  
  
1.按照编号从小到大排序  
  
2.对于编号相等的长方形，按照长方形的长排序；  
  
3.如果编号和长都相同，按照长方形的宽排序；  
  
4.如果编号、长、宽都相同，就只保留一个长方形用于排序,删除多余的长方形；最后排好序按照指定格式显示所有的长方形；


----------input----------
第一行有一个整数 0 每一组第一行有一个整数 0 接下来的m行，每一行有三个数 ，第一个数表示长方形的编号，  
  
第二个和第三个数值大的表示长，数值小的表示宽，相等  
说明这是一个正方形（数据约定长宽与编号都小于10000）；


----------output----------
顺序输出每组数据的所有符合条件的长方形的 编号 长 宽


----------sample_input----------
1

8

1 1 1

1 1 1

1 1 2

1 2 1

1 2 2

2 1 1

2 1 2

2 2 1
----------sample_putput----------
1 1 1

1 2 1

1 2 2

2 1 1

2 2 1
*/
/////////////////////////////
#include<stdio.h>
#include<stdlib.h>
struct C
{
    int num;
    int a;
    int b;
};
int comp(const void *a1,const void *b1)
{
    struct C *c=(C *)a1;
    struct C *d=(C *)b1;
    if(c->num!=d->num)
        return c->num-d->num;
    else if(c->a!=d->a)
        return c->a-d->a;
    else
        return c->b-d->b;
}

int main()
{
    int N;
    int m,i;
    int temp;
    C c[1001];
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d",&m);
        for(i=1;i<=m;i++)
            scanf("%d%d%d",&c[i].num,&c[i].a,&c[i].b);
        for(i=1;i<=m;i++)//长的放在前面作为长
        {
            if(c[i].b>c[i].a)
            {
                temp=c[i].a;
                c[i].a=c[i].b;
                c[i].b=temp;
            }
        }
        /*for(i=1;i<=m;i++)
            printf("<%d %d %d>\n",c[i].num,c[i].a,c[i].b);*/
        qsort(c,m+1,sizeof(C),comp);
        /*for(i=1;i<=m;i++)
            printf("(%d %d %d)\n",c[i].num,c[i].a,c[i].b);*/
        for(i=1;i<=m-1;)
        {
            if(c[i].num==c[i+1].num && c[i].a==c[i+1].a && c[i].b==c[i+1].b)
                i++;
            else
            {
                printf("%d %d %d\n",c[i].num,c[i].a,c[i].b);
                i++;
            }
        }
        /*if(c[m-1].num==c[m].num && c[m-1].a==c[m].a && c[m-1].b==c[m].b)*/
        printf("%d %d %d\n",c[m].num,c[m].a,c[m].b);
    }
    return 0;
}        