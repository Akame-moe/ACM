/*
----------description----------
在某一国度里流行着一种游戏。游戏规则为：在一堆球中，每个球上都有一个整数编号i(0<=i<=100000000),编号可重复，现在说一个随机整数k(0<=k<=100000100)，判断编号为k的球是否在这堆球中（存在为"YES",否则为"NO"），先答出者为胜。现在有一个人想玩玩这个游戏，但他又很懒。他希望你能帮助他取得胜利。


----------input----------
第一行有两个整数m，n(0<=n<=100000，0<=m<=1000000)；m表示这堆球里有m个球，n表示这个游戏进行n次。
接下来输入m+n个整数，前m个分别表示这m个球的编号i，后n个分别表示每次游戏中的随机整数k


----------output----------
输出"YES"或"NO"


----------sample_input----------
6 4

23 34 46 768 343 343

2 4 23 343
----------sample_putput----------
NO

NO

YES

YES
*/
/////////////////////////////
/*
#include <stdio.h>// 找球号一
#define MAXN 3125010
int vis[MAXN] = {0} ;
int main()
{
   int m , n , x ;
   int i ;
   scanf("%d%d", &m , &n ) ;
   for( i = 0 ; i < m ; ++i )
   {
       scanf("%d", &x ) ;
       vis[ x / 32 ] |= 1 << x % 32 ;
   }
   for( i = 0 ; i < n ; ++i )
   {
       scanf("%d", &x ) ;
       if( vis[ x / 32 ] & ( 1 << x % 32 ) )
           printf("YES\n");
       else
           printf("NO\n");
   }
   return 0 ;
}
*/
/*
#include<stdio.h>//找球号二
#define N 3125010
int vis[N]={0};
int main()
{
    int n,m,i,num;
    char s[10];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s %d",s,&m);
        if(s[0]=='A')
        {
            for(i=0;i<m;i++)
            {
                scanf("%d",&num);

                vis[num/32] |= 1<<num%32;
            }
        }
        else
        {
            for(i=0;i<m;i++)
            {
                scanf("%d",&num);
                if(vis[num/32] & (1<<num%32))
                    printf("YES\n");
                else
                    printf("NO\n");
            }
        }

    }
    return 0;
}

*/