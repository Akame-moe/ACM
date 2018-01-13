/*
----------description----------
ACM队的mdd想做一个计算器，但是，他要做的不仅仅是一计算一个A+B的计算器，他想实现随便输入一个表达式都能求出它的值的计算器，现在请你帮助他来实现这个计算器吧。  
比如输入：“1+2/4=”，程序就输出1.50（结果保留两位小数）


----------input----------
第一行输入一个整数n，共有n组测试数据（n<10)。  
每组测试数据只有一行，是一个长度不超过1000的字符串，表示这个运算式，每个运算式都是以“=”结束。这个表达式里只包含+-*/与小括号这几种符号。其中小括号可以嵌套使用。数据保证输入的操作数中不会出现负数。  
数据保证除数不会为0


----------output----------
每组都输出该组运算式的运算结果，输出结果保留两位小数。


----------sample_input----------
2
1.000+2/4=
((1+2)*5+1)/4=
----------sample_putput----------
1.50
4.00
*/
/////////////////////////////
#include<stdio.h>
#include<stdlib.h>
#include<stack>
using namespace std;
stack<double> ovs;
stack<char> ops;
char s[1005];
bool comp(char ,char);
double calculate(double ,char ,double);
int main()
{
	int N;
	int i,j;
	double num1,num2,ans;
	char op;
	scanf("%d",&N);
	char w[100];
	while(N--)
	{
		ops.push('#');
		scanf("%s",s);
		for(i=0;s[i]!='=';)
		{			
			if(s[i]>='0' && s[i]<='9')
			{
				j=0;
				w[j++]=s[i++];
				while((s[i]>='0' && s[i]<='9') || s[i]=='.')
				{
					w[j++]=s[i++];
				}
				w[j]='\0';
				ovs.push(atof(w));
				//printf("[ovs=%lf]\n",ovs.top());
			}
			else
			{
				if(comp(ops.top(),s[i]) || s[i]=='(')
				{
					ops.push(s[i]);
					i++;
				}
				else if(ops.top()=='(' && s[i]==')')
				{
					ops.pop();
					i++;
				}
				else
				{
					num2=ovs.top();	ovs.pop();				
					num1=ovs.top();	ovs.pop();				
					op=ops.top(); ops.pop();				
					ovs.push(calculate(num1,op,num2));
				}
			}

		}
		//printf("size=%d\n",ovs.size());
		while(ovs.size()!=1)
		{			
			num2=ovs.top();	ovs.pop();				
			num1=ovs.top();	ovs.pop();				
			op=ops.top(); ops.pop();			
			ovs.push(calculate(num1,op,num2));			
		}
		printf("%.2lf\n",ovs.top());
		while(!ovs.empty())
			ovs.pop();
		while(!ops.empty())
			ops.pop();
	}
	return 0;
	
}
bool comp(char op_top ,char op)
{
	int top,_op;
	switch(op_top)
	{
	case '*':
	case '/':top=3;break;
	case '+':
	case '-':top=2;break;
	case '(':
	case ')':top=1;break;
	case '#':top=0;break;
	default :printf("1_error!\n");exit(1);
	}
	switch(op)
	{
	case '*':
	case '/':_op=3;break;
	case '+':
	case '-':_op=2;break;
	case '(':
	case ')':_op=1;break;
	case '#':_op=0;break;
	default :printf("2_error!\n");exit(1);
	}
	return top<_op;
}
double calculate(double num1,char op,double num2)
{
	double ans;
	switch(op)
	{
	case '*':ans=num1*num2;break;
	case '/':ans=num1/num2;break;
	case '+':ans=num1+num2;break;
	case '-':ans=num1-num2;break;
	default :printf("3_error!\n");exit(1);
	}
	return ans;
}