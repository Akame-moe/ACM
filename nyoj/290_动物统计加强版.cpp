/*
----------description----------
在美丽大兴安岭原始森林中存在数量繁多的物种，在勘察员带来的各种动物资料中有未统计数量的原始动物的名单。科学家想判断这片森林中哪种动物的数量最多，但是由于数据太过庞大，科学家终于忍受不了，想请聪明如你的ACMer来帮忙。


----------input----------
第一行输入动物名字的数量N(1<= N <=
4000000),接下来的N行输入N个字符串表示动物的名字（字符串的长度不超过10,字符串全为小写字母，并且只有一组测试数据）。  


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
struct Tire{
    int count;
    Tire *next[26];
};
Tire *root;
int Max;
char Maxs[11];
char ss[11];
void insert(char *s)
{
    if(root==NULL || *s=='\0')
        return ;
    Tire *p=root;
    int i;
    int n;
    while(*s!='\0')
    {
        n=*s-'a';
        if(p->next[n]==NULL)
        {
            Tire *temp=new Tire;
            for(i=0;i<26;i++)
                temp->next[i]=NULL;
            temp->count=0;
            p->next[n]=temp;
        }
        p=p->next[n];
        s++;
    }
    p->count++;
    if(p->count>Max){ Max=p->count; strcpy(Maxs,ss);}
}
int main()
{
    int N;
    int i;
    while(~scanf("%d",&N))
    {
        root=new Tire;
        for(i=0;i<26;i++)
            root->next[i]=NULL;
        root->count=0;
        Max=0;
        while(N--)
        {
            scanf("%s",ss);
            insert(ss);
        }
        printf("%s %d\n",Maxs,Max);
    }
    return 0;

}