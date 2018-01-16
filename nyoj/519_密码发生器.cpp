/*
----------description----------
在对银行账户等重要权限设置密码的时候，我们常常遇到这样的烦恼：如果为了好记用生日吧，容易被破解，不安全；如果设置不好记的密码，又担心自己也会忘记；如果写在纸上，担心纸张被别人发现或弄丢了...

这个程序的任务就是把一串拼音字母转换为6位数字（密码）。我们可以使用任何好记的拼音串(比如名字，王喜明，就写：wangximing)作为输入，程序输出6位数字。

变换的过程如下：

第一步. 把字符串6个一组折叠起来，比如wangximing则变为：  
wangxi  
ming

第二步. 把所有垂直在同一个位置的字符的ascii码值相加，得出6个数字，如上面的例子，则得出：  
228 202 220 206 120 105

第三步. 再把每个数字“缩位”处理：就是把每个位的数字相加，得出的数字如果不是一位数字，就再缩位，直到变成一位数字为止。例如: 228 =>
2+2+8=12 => 1+2=3

上面的数字缩位后变为：344836, 这就是程序最终的输出结果！

要求程序从标准输入接收数据，在标准输出上输出结果。


----------input----------
第一行是一个整数n（<100），表示下边有多少输入行，接下来是n行字符串，就是等待变换的字符串(长度小于100)。


----------output----------
变换后的6位密码


----------sample_input----------
5

zhangfeng

wangximing

jiujingfazi

woaibeijingtiananmen

haohaoxuexi
----------sample_putput----------
772243

344836

297332

716652

875843
*/
/////////////////////////////
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int main()
{
    int trun(int);
    int N;
    char s[105];
    int len,i;
    scanf("%d",&N);
    while(N--)
    {
        int a[6]={0};
        scanf("%s",s);
        len=strlen(s);
        for(i=0;i<len;i++)
        {
            a[i%6]+=(int)s[i];
        }
        for(i=0;i<6;i++)
            cout<<trun(a[i]);
        cout<<endl;
    }
    return 0;
}
int trun(int n)
{
    int m=0;
    while(n>0)
    {
        m+=n%10;
        n/=10;
    }
    if(m>=10)
        trun(m);
    else
        return m;
}