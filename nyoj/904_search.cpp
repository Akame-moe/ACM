/*
----------description----------
游戏积分的排行榜出来了，小z想看看得某个积分的人是谁。但是由于人数很多，他自己找很浪费时间，所以他想请你帮忙写一个程序，能快速的帮他找到他想要找的人


----------input----------
多组测试数据，第一行有一个数T，表示有T组测试数据(T<=50)
第二行有两个数n和m(1<=n,m<=10000)，n表示有n个人，m表示有m次查询
接下来n行，输入每个人的名字(长度小于10)和积分num(0<=num<=10^8)，
接下来m行，每个数表示要查询的积分(每次查询一定有结果)


----------output----------
输出对应积分的人的名字（如果有多个人的积分相同，则输出最前面的那个）


----------sample_input----------
1

5 3

zhangsan 2

qianxiao 5

liuqiang 2

wangwu 1

lisi 3

2

1

3
----------sample_putput----------
zhangsan

wangwu

lisi
*/
/////////////////////////////
/*
#include<cstdio>//ac
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct N
{
    char name[12];
    int fen;
}p[10005];
int comp(N a,N b)
{
    return a.fen<b.fen;
}
int n,m,i,t;
int Bsearch(int);
int main()
{
    int T;

    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%s %d",p[i].name,&p[i].fen);
        }
        stable_sort(p,p+n,comp);//稳定排序算法
        for(i=0;i<m;i++)
        {
            scanf("%d",&t);
            printf("%s\n",p[Bsearch(t)].name);
        }
    }
    return 0;

}
int Bsearch(int fen)
{
    int i=0,j=n,mid;
    while(i<j)
    {
        mid=(i+j)/2;
        if(p[mid].fen<fen)
            i=mid+1;
        else if(p[mid].fen>fen)
            j=mid;
        else
        {
            if(p[mid].fen==p[mid-1].fen)
                j=mid;
            else
                return mid;
        }
    }
}
*/
//超时
#include<cstdio>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct N {
    char name[12];
    int fen;
} p[10005];
int comp(N a, N b) {
    return a.fen < b.fen;
}
int n, m, i, t;
int Bsearch(int);
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        for(i = 0; i < n; i++) {
            scanf("%s %d", p[i].name, &p[i].fen);
        }
        stable_sort(p, p + n, comp); //稳定排序算法
        for(i = 0; i < m; i++) {
            scanf("%d", &t);
            int tt = Bsearch(t);
            while(p[tt - 1].fen == t) //找到相等的并且最先输入的
                tt--;
            printf("%s\n", p[tt].name);
        }
    }
    return 0;
}
int Bsearch(int fen) {
    int i = 0, j = n - 1, mid;
    while(i <= j) {
        mid = (i + j) / 2;
        if(p[mid].fen == fen)
            break;
        if(p[mid].fen > fen)
            j = mid;
        else
            i = mid;
    }
    return mid;
}
