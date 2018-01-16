/*
----------description----------
编写一个程序实现将字符串中的所有"you"替换成"we"


----------input----------
输入包含多行数据  
  
每行数据是一个字符串，长度不超过1000  
数据以EOF结束


----------output----------
对于输入的每一行，输出替换后的字符串


----------sample_input----------
you are what you do
----------sample_putput----------
we are what we do
*/
/////////////////////////////
 
#include<stdio.h>
#include<string.h>
int main()
{
    char s[1001];
    int i=0;
    int d;
    while(gets(s))
    {
        d=strlen(s);
        for(i=0;i+3<d;)
        {
            if(s[i]=='y' && s[i+1]=='o' && s[i+2]=='u')
            {

                printf("we");
                i+=3;
            }
            else
            {
                printf("%c",s[i]);
                i++;
            }
        }
        if(s[i]=='y' && s[i+1]=='o' && s[i+2]=='u')
            printf("we");
        else
        {
            for(;i<d;i++)
                printf("%c",s[i]);
            printf("\n");
        }
    }
    return 0;    
}
#include<algorithm>
#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s, s1, s2;
    while(getline(cin,s))
    {
        int flag;
        s1 = "you";
        s2 = "we";
        flag = s.find(s1,0);
        while(flag != string::npos)
        {
            s.replace(flag, 3, s2);
            flag = s.find(s1, flag + 1);
        }
        cout << s << endl;
    }
    return 0;
}
        