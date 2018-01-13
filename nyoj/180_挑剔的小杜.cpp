/*
----------description----------
小杜一直都不喜欢数学，但是他特爱语文，所以对英语也非常感兴趣。所以他也就有个习惯，一看到字母里面插有数字，一定要把他全部划去。

现在给你纸，纸上有很多既含有字母，又含有数字的句子（还包括一些标点符号）。你需要将数字找出来放在一边，并组成一个最大的数。然后逆序输出所有字母，和那个最大的数。


----------input----------
第一行：N表示有多少组数据。  
接下来的N行，每行有一句话，长度不超过1000。  


----------output----------
每句话对应输出两行。  
第一行输出字母的总个数及其所有的字母（按原来输入的相反的顺序输出），中间需要一个空格分开。  
第二行输出那个数字的总个数及最大的数,中间需要一个空格分开。  
（如果没有字母或数字，则对应只需要输出一个0）


----------sample_input----------
2
abcabc123abc.
aaa
----------sample_putput----------
9 cbacbacba
3 321
3 aaa
0
*/
/////////////////////////////
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int comp10(const void *a,const void *b)
{
	return *(char *)b-*(char *)a;
}
int len_ss;
int main()
{
	char *strr(char *);
	char s[1005];
	char ss[1005],s1[1005];
	int N,i,j,k;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%s",s);
		for(k=0,i=0,j=0;s[k]!='\0';k++)
		{
			if(s[k]>='0' && s[k]<='9')
				s1[j++]=s[k];
			if((s[k]>='a' && s[k]<='z') || (s[k]>='A' && s[k]<='Z'))
				ss[i++]=s[k];
		}
		s1[j]='\0';
		ss[i]='\0';
		int len_s1=strlen(s1);
		len_ss=strlen(ss);
		qsort(s1,len_s1,sizeof(s1[0]),comp10);
		if(len_ss==0)
			printf("0\n");
		else
			printf("%d %s\n",len_ss,strr(ss));
		if(len_s1==0)
			printf("0\n");
		else
			printf("%d %s\n",len_s1,s1);

	}
	return 0;
}
char* strr(char *s)
{
	int i,j;
	char ss[1005];
	for(j=len_ss-1,i=0;j>=0;j--,i++)
	{
		ss[i]=s[j];
	}
	ss[i]='\0';
	return ss;
}