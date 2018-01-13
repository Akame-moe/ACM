/*
----------description----------
求一个字符串的最长递增子序列的长度  
如：dabdbf最长递增子序列就是abdf，长度为4


----------input----------
第一行一个整数0 随后的n行，每行有一个字符串，该字符串的长度不会超过10000


----------output----------
输出字符串的最长递增子序列的长度


----------sample_input----------
3
aaa
ababc
abklmncdefg
----------sample_putput----------
1
3
7
*/
/////////////////////////////
#include<stdio.h>//0  228
int length(char * s)
{
	int len[128] = {0}, i, t;
	for(; *s != '\0' && (t = len[*s - 1] + 1); s++)
	for(i = *s; i < 128 && len[i] < t; len[i++] = t);
	return len[127];
}
int main()
{
	int n;
	char s[10001];
	for(scanf("%d\n", &n); n--;)
	printf("%d\n", length(gets(s)));
	return 0;
}
#include<stdio.h>
#include<string.h>
int Bsearch(char* list,int n,char e);  //二分查找
int main()
{
    int N,n,i,j,ans;
    char ss[12000];
    char d[12000];
    scanf("%d",&N);
    while(N--)
    {
        ans=1;
        scanf("%s",ss);
        d[ans-1]=ss[0];
        n=strlen(ss);
        for(i=1;i<n;i++)
        {
            if(ss[i]>d[ans-1])
            {
                d[ans++]=ss[i];
            }
            else
            {
                int ind=Bsearch(d,ans,ss[i]);
                d[ind+1]=ss[i];
            }

        }
        printf("%d\n",ans);
    }
    return 0;
}
int Bsearch(char* list,int n,char e)
{
    int left=0,right=n-1;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(list[mid]<e)
        {
            if(mid==n-1||e<=list[mid+1])
            return mid;
            else left=mid+1;
        }
        else
        {
            if(mid==0||list[mid-1]<e)
            return mid-1;
            else right=mid-1;
        }
    }
    return -1;
}
/*
#include<stdio.h>
#include<stdlib.h>
#define MAX 1005
#define max(a,b) a>b?a:b
typedef struct Ju
{
	int c,k;
}R; 
int comp(const void *a,const void *b)
{
	//struct Ju 
	R *e=(Ju *)a;
	//struct Ju 
	R *f=(Ju *)b;
	if(e->c!=f->c)
		return e->c-f->c;
	else
		return e->k-f->k;
}
int main()
{
	R a[MAX];
	int f[MAX];
	int N,n,i,j;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d",&n);
		int tt;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&a[i].c,&a[i].k);
			if(a[i].k>a[i].c)
			{
				tt=a[i].c;
				a[i].c=a[i].k;
				a[i].k=tt;
			}
		}
		qsort(a,n,sizeof(a[0]),comp);
	//	for(i=0;i<n;i++)
		//	printf("[%d %d]\n",a[i].c,a[i].k);
		for(i=0;i<=n;i++)
		{
			f[i]=1;
			for(j=0;j<i;j++)
			{
				if(i==n || (a[i].c>a[j].c && a[i].k>a[j].k))
					f[i]=max(f[i],f[j]+1);
			}
		}
		printf("%d\n",f[n]-1);
	}
	return 0;
}
*/
/*

#include<stdio.h>
#include<string.h>
#define max(a,b) a>b?a:b
const int MAX=10010;

int main()
{
	int N;
	scanf("%d",&N);
	int f[MAX];
	char s[MAX];
	while(N--)
	{
		int len,i,j;	
		scanf("%s",s);
		len=strlen(s);
		for(i=0;i<=len;i++)
		{
			f[i]=1;
			for(j=0;j<i;j++)
			{
				if(i==len || s[i]>s[j])
					f[i]=max(f[i],f[j]+1);
			}
		}
		printf("%d\n",f[len]-1);
	}
	return 0;
} 

*/
/*  
#include<stdio.h>
#include<string.h>
int Bsearch(int* list,int n,int e);  //二分查找
int main()
{
    int n,i,j,ans;
    //char ss[12000];
    //char d[12000];
	int ss[100010];
	int d[100010];
    
    while(~scanf("%d",&n))
    {
        ans=1;
        //scanf("%s",ss);
		for(i=0;i<n;i++)
			scanf("%d",&ss[i]);
        d[ans-1]=ss[0];
        //n=strlen(ss);
        for(i=1;i<n;i++)
        {
            if(ss[i]>d[ans-1])
            {
                d[ans++]=ss[i];
            }
            else
            {
                int ind=Bsearch(d,ans,ss[i]);
                d[ind+1]=ss[i];
            }

        }
        printf("%d\n",ans);
    }
    return 0;
}
int Bsearch(int* list,int n,int e)
{
    int left=0,right=n-1;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(list[mid]<e)
        {
            if(mid==n-1||e<=list[mid+1])
            return mid;
            else left=mid+1;
        }
        else
        {
            if(mid==0||list[mid-1]<e)
            return mid-1;
            else right=mid-1;
        }
    }
    return -1;
}

*/
 /*
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX=100100;
int num[MAX],top=0;
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		scanf("%d",&num[0]);
		top=1;
		for(int i=1;i!=n;i++)
		{
			scanf("%d",&num[i]);
			int * p=lower_bound(num,num+top,num[i]);
			if(p-num==top) ++top;
			*p=num[i];
		}
		printf("%d\n",top);
	}
	
}        
   */
                   
   