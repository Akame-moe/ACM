/*
----------description----------
现在，有一行括号序列，请你检查这行括号是否配对。


----------input----------
第一行输入一个数N（0<N<=100）,表示有N组测试数据。后面的N行输入多组输入数据，每组输入数据都是一个字符串S(S的长度小于10000，且S不是空串），测试数据组数少于5组。数据保证S中只含有"[",
"]", "(", ")" 四种字符


----------output----------
每组输入数据的输出占一行，如果该字符串中所含的括号是配对的，则输出Yes,如果不配对则输出No


----------sample_input----------
3

[(])

(])

([[]()])
----------sample_putput----------
No

No

Yes
*/
/////////////////////////////
#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    int len;
    char s1[10001];
    char s2[10001];
    int i,j;
    int flag;
    int head;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",s1);
        len=strlen(s1);
        if((len%2)!=0)
        {
            flag=0;
        }
        else
        {
            flag=1;
            head=0;
            j=-1;
            for(i=0;i<len;i++)
            {
                if(s1[i]=='[' || s1[i]=='(')
                    s2[++j]=s1[i];
                else
                {
                //    if((s1[i]==']'&& s2[head]=='[') || (s1[i]==')' && s2[head]=='('))
                //        head++;
                    //else 
                        if((s1[i]==']' && s2[j]=='[') || (s1[i]==')' && s2[j]=='('))
                        j--;
                    else
                    {
                        flag=0;
                        break;
                    }
                }
            }
        }
        printf("%s\n",flag?"Yes":"No");


    
    }
    return 0;
}  
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
    int N;
    cin>>N;
    while(N--)
    {
        string a;
        stack<char> s;
        cin>>a;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]=='('||a[i]=='[')
                s.push(a[i]);
            else if(a[i]==')')
            {
                if(!s.empty()&&s.top()=='(')
                    s.pop();
                else s.push(a[i]);
            }
            else if(a[i]==']')
            {
                if(!s.empty()&&s.top()=='[')
                    s.pop();
                else s.push(a[i]);
            }
        }
        if(s.empty())
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}        
      