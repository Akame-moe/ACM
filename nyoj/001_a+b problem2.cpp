#include<stdio.h>
#include<string.h>
int main()
{
    int N;
    char s1[1005],s2[1005];    
    int i;
    int cas=1;
    int len,len1,len2;
    scanf("%d",&N);
    while(N--)
    {
        int a1[1005]={0},a2[1005]={0};
        scanf("%s %s",s1,s2);
    
        len1=strlen(s1);
        for(i=0;i<len1;i++)
            a1[len1-i]=s1[i]-'0';
        len2=strlen(s2);
        for(i=0;i<len2;i++)
            a2[len2-i]=s2[i]-'0';
        len=len1>len2?len1:len2;    
        int jw=0,temp;
        for(i=1;i<=len;i++)
        {
            temp=a1[i]+a2[i]+jw;
            a1[i]=temp%10;
            jw=temp/10;
            if(i==len && jw!=0)
                len++;
        }
        printf("Case %d:\n%s + %s = ",cas++,s1,s2);
        for(i=len;i>=1;i--)
            printf("%d",a1[i]);
        printf("\n");
    }
    return 0;
}