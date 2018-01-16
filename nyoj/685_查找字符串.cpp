/*
----------description----------
小明得到了一张写有奇怪字符串的纸，他想知道一些字符串出现了多少次，但这些字符串太多了，他想找你帮忙，你能帮他吗？输入字符包括所有小写字母、‘@’、‘+’。


----------input----------
第一行包含一个整数T（T<=100).表示测试数据组数。  
接下来每组数据第一行包含两个整数n，m(n，m<100000),分别表示有n个字符串，小明要问你m次。  
接下来n行，每行包含一个字符串，长度不大于15。  
接下来m行，每行包含一个字符串，表示小明要问该串出现的次数。  


----------output----------
输出每组小明询问数串出现的次数。


----------sample_input----------
1

5 3

hello

it@is+so@easy

hello

ibelieveicanac

hello

hello

icannotacit

Giveup
----------sample_putput----------
3

0

0
*/
/////////////////////////////
#include<stdio.h>//685查找字符串//字典树
struct Trie{
    int count;
    Trie *next[30];
};
Trie *root;;
int turn(char c)
{
    if(c>='a' && c<='z')
        return c-'a';
    else if(c=='@')
        return 26;//@
    else 
        return 27;//  +
}
void insert(char *s)
{
    if(root==NULL || *s=='\0')
        return ;
    int i;
    Trie *p=root;
    while(*s!='\0')
    {
        if(p->next[turn(*s)]==NULL)
        {
            Trie *temp=new Trie;
            for(i=0;i<30;i++)
                temp->next[i]=NULL;
            temp->count=0;
            p->next[turn(*s)]=temp;
        }
        p=p->next[turn(*s)];
        s++;
    }
    p->count++;
}
int Tfind(char *s)
{
    Trie *p=root;
    while(p!=NULL && *s!='\0')
    {
        p=p->next[turn(*s)];
        s++;
    }
    return p==NULL?0:p->count;
}
void del(Trie *p)
{
    int i;
    for(i=0;i<30;i++)
    {
        if(p->next[i]!=NULL)
            del(p->next[i]);
    }
    delete p;
}
int main()
{
    int T;
    int n,m;
    int i;
    char s[20];
    scanf("%d",&T);
    getchar();
    while(T--)
    {
        root=new Trie;
        for(i=0;i<30;i++)
            root->next[i]=NULL;
        root->count=0;
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%s",s);
            insert(s);
        }
        while(m--)
        {
            scanf("%s",s);
            printf("%d\n",Tfind(s));
        }
        del(root);
    }
    return 0;
}