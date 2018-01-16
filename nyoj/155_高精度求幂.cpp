/*
----------description----------
对数值很大、精度很高的数进行高精度计算是一类十分常见的问题。比如，对国债进行计算就是属于这类问题。  
  
现在要你解决的问题是：对一个实数R( 0.0 < R < 99.999 )，要求写程序精确计算 R 的 n 次方(Rn)，其中n 是整数并且 0 < =n
<= 25。


----------input----------
输入有多行，每行有两个数R和n，空格分开。R的数字位数不超过10位。


----------output----------
对于每组输入，要求输出一行，该行包含精确的 R 的 n 次方。输出需要去掉前导的 0 后不要的 0 。如果输出是整数，不要输出小数点。


----------sample_input----------
95.123 12
0.4321 20
5.1234 15
6.7592  9
98.999 10
1.0100 12
----------sample_putput----------
548815620517731830194541.899025343415715973535967221869852721
.00000005148554641076956121994511276767154838481760200726351203835429763013462401
43992025569.928573701266488041146654993318703707511666295476720493953024
29448126.764121021618164430206909037173276672
90429072743629540498.107596019456651774561044010001
1.126825030131969720661201
*/
/////////////////////////////
 
 //高精度球迷
//未通过
#include<stdio.h>
#define N 126
#include<string.h>
#include<math.h>
static int a[N]={0};
int main()
{
	char s[11];
	int shu[10];//转换后的数组
	int i,j;
	int loc=0;//记录小数点的位置
	int n,m;
	int len,l;
	int k;
	unsigned long int jw;
	unsigned long int temp;
	unsigned long int num;
	while(	scanf("%s %d",s,&n))
	{
		if(n==0)
			printf("1\n");
		else
		{
			for(i=1;i<=N;i++)
				a[i]=0;
			i=0;
			num=0;
			
			while(i<strlen(s))
			{
				if(s[i]=='.')
					loc=(strlen(s)-1-i)*n;
				else
				{
				num=num*10+s[i]-'0';
				
				}
				i++;
			}
			m=num;
			j=1;
			while(m!=0)
			{
				a[j++]=m%10;
				m/=10;
			}
			len=j-1;
			/*printf("[%d]",len);
			for(j=len;j>=1;j--)
				printf("%d",a[j]);*/
			while(--n)
			{
				jw=0;
				for(j=1;j<=len;j++)
				{
					temp=a[j]*num+jw;
					jw=temp/10;
					a[j]=temp%10;
					if(j==len && jw!=0)
						len++;
				}		
			}
		
			if(loc==0)//无小数点
			{
				for(i=len;i>=1;i--)
					printf("%d",a[i]);
				printf("\n");
			}
			else//有小数点
			{
				k=1;
				while(a[k]==0)//去掉尾部的0
				{
					k++;
				}
				if(loc<=len)
				{
					for(i=len;i>=k;i--)
					{
						if(i==loc)
							printf(".%d",a[i]);
						else
							printf("%d",a[i]);
					}
				}
				else
				{
					len=loc;
					printf(".");
					for(i=len;i>=k;i--)
						printf("%d",a[i]);
				}
				printf("\n");
			}
		}

		
	}
	return 0;
}
 
 //超短ac代码
#include<stdio.h>
double f;
int n,i,j;
int top,bottom;
int show;
int main()
{
	while(scanf("%lf%d",&f,&n)!=EOF)
	{
		if(n==0)
		{
			printf("1\n");
			continue;
		}
		int p[300]={1},tmp=0;
		f*=1e6;
		for(i=0;i++<n;)
		{
			for(j=0;j<i*9;)
			{
				tmp+=p[j]*f;
				p[j++]=tmp%10;
				tmp/=10;
			}
		}

		for(bottom=-1;!p[++bottom]&&bottom<n*6;);
		show=0;
		for(top=j;bottom<top;)
		{
			if(top--==n*6||p[top])
				show=1;
			if(show)
				printf(top==n*6-1?".%d":"%d",p[top]);
		}
		puts("");
	}
	return 0;
}                
        