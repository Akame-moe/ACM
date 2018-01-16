/*
----------description----------
在美丽大兴安岭原始森林中存在数量繁多的物种，在勘察员带来的各种动物资料中有未统计数量的原始动物的名单。科学家想判断这片森林中哪种动物的数量最多，但是由于数据太过庞大，科学家终于忍受不了，想请聪明如你的ACMer来帮忙。


----------input----------
第一行输入动物名字的数量N(1<= N <=
10000),接下来的N行输入N个字符串表示动物的名字（字符串的长度不超过10,字符串全为小写字母，并且只有一组测试数据）。


----------output----------
输出这些动物中最多的动物的名字与数量，并用空格隔开（数据保证最多的动物不会出现两种以上）。


----------sample_input----------
10

boar

pig

sheep

gazelle

sheep

sheep

alpaca

alpaca

marmot

mole
----------sample_putput----------
sheep 3
*/
/////////////////////////////
#include<stdio.h>
#include<string.h>
int main()
{
    int N;
    char s[10005][15];
    int i,max,j;
    int t;
    int loc;
    while(~scanf("%d",&N))
    {
        static int a[10005];
        t=-1;
        for(i=0;i<N;i++)
        {
            scanf("%s",s[i]);
            a[i]=1;
            for(j=i-1;j>=0;j--)
            {
                if(strcmp(s[j],s[i])==0)
                {
                    a[i]+=a[j];
                    break;
                }
            }
        }
        max=0;
        loc=0;
        for(j=0;j<N;j++)
            if(a[j]>max)
            {
                max=a[j];
                loc=j;
            }
        printf("%s %d\n",s[loc],max);

        
    }
    return 0;
}
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
    int num;
    struct node *next[26];
};
struct node *root;
node *build()
{
    struct node *p=(node *)malloc(sizeof(node));
    p->num=1;
    for(int i=0;i<26;i++)
        p->next[i]=NULL;
    return p;
}
int insert(char *s)
{
    struct node *p=root;
    int len=strlen(s);
    for(int i=0;i<len;i++)
    {
       if(p->next[s[i]-'a']==NULL)
           p->next[s[i]-'a']=build();
       p=p->next[s[i]-'a'];     
    }
    return p->num++;
}
int main()
{
    int  n,i,max=-1,a;
    char str[10],s[10];
    root=build();
    scanf("%d",&n);
        for(i=0;i<n;i++)
    {
        scanf("%s",str);
             a=insert(str);
        if(a>max)
        {
            max=a;
                    strcpy(s,str); 
        }
    }
    printf("%s %d\n",s,max);
    return 0;
}              