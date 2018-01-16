/*
----------description----------
我们熟悉的表达式如a+b、a+b*(c+d)等都属于中缀表达式。中缀表达式就是（对于双目运算符来说）操作符在两个操作数中间：num1 operand
num2。同理，后缀表达式就是操作符在两个操作数之后：num1 num2
operand。ACM队的“C小加”正在郁闷怎样把一个中缀表达式转换为后缀表达式，现在请你设计一个程序，帮助C小加把中缀表达式转换成后缀表达式。为简化问题，操作数均为个位数，操作符只有+-* /
和小括号。


----------input----------
第一行输入T，表示有T组测试数据（T<10）。  
每组测试数据只有一行，是一个长度不超过1000的字符串，表示这个表达式。这个表达式里只包含+-* /与小括号这几种符号。其中小括号可以嵌套使用。数据保证输入的操作数中不会出现负数。并且输入数据不会出现不匹配现象。  


----------output----------
每组输出都单独成行，输出转换的后缀表达式。


----------sample_input----------
2
1+2
(1+2)*3+4*5
----------sample_putput----------
12+
12+3*45*+
*/
/////////////////////////////
#include<stdio.h>//二叉树
#include<stdlib.h>
#include<stack>
using namespace std;
typedef struct Tree
{
	char c;
//	double n;
	Tree *liftchild,*rightchild;
}tree;
stack <tree*> ops;
stack <tree*> ovs;
tree *Root;	
char s[1005];
int p(char ch)
{
	switch(ch)
	{
	case '*':
	case '/':return 2;
	case '+':
	case '-':return 1;
	case '(':
	case ')':return 0;
	case ';':return -1;
	default :printf("%c_error!\n",ch);exit(1);
	}
}
tree *build(char ch)
{
	tree *root=new tree;
	root->c=ch;
	root->liftchild=NULL;
	root->rightchild=NULL;
	return root;
}
void visit(tree * r)
{
	if(r!=NULL)
	{
		visit(r->liftchild);
		visit(r->rightchild);
		printf("%c",r->c);
	}
}
int main()
{

	int i;
	int  N;
	scanf("%d",&N);
	while(N--)//1-2*3-4/5
	{
		scanf("%s",s);
		for(i=0;s[i]!='\0';)
		{
			if(s[i]>='0' && s[i]<='9')
			{
				ovs.push(build(s[i]));i++;
			}
			else
			{
				if(ops.empty() || s[i]=='(' || p(ops.top()->c)<p(s[i]) )
					ops.push(build(s[i])),i++;
				else if(ops.top()->c=='(' && s[i]==')')
					ops.pop(),i++;
				else//p(ops.top())>=p(s[i])
				{
					ops.top()->rightchild=ovs.top();ovs.pop();
					ops.top()->liftchild=ovs.top();ovs.pop();					
					Root=ops.top();ops.pop();	
					ovs.push(Root);
				}
			}

		}
		while(ovs.size()!=1)
		{
			ops.top()->rightchild=ovs.top();ovs.pop();
			ops.top()->liftchild=ovs.top();ovs.pop();					
			Root=ops.top();ops.pop();
			ovs.push(Root);
		}
		Root=ovs.top();ovs.pop();
		while(!ops.empty())
			ops.pop();
		visit(Root);
		printf("\n");
	}
	return 0;
}
#include<stdio.h>//栈和队列
#include<stdlib.h>
#include<queue>
#include<stack>
using namespace std;
stack <char> ops;
queue <char> ovs;
int p(char);
int main()
{
	char s[10005];
	int i,k;
	int N;
	scanf("%d",&N);
	while(N--)//   1+2*(3-4)/5=
	{
		scanf("%s",s);
		ops.push('=');
		for(i=0;;)
		{
			if(s[i]>='0' && s[i]<='9')
			{
				ovs.push(s[i]);i++;
			}
			else 
			{
				if(s[i]=='\0')
				{
					while(!ops.empty())
					{
						ovs.push(ops.top());
						ops.pop();
					}
					break;
				}
				else if(s[i]==')')
				{
					while(ops.top()!='(')
					{
						ovs.push(ops.top());ops.pop();
					}
					ops.pop();
					i++;
				}
				else if(s[i]=='(' || p(s[i]) > p(ops.top()))
				{
					ops.push(s[i]);i++;
				}
				else //(s[i]!='=' && p(s[i])<=  p(ops.top())  )
				{
					ovs.push(ops.top());
					ops.pop();
				}					
			}
		}
		while(ovs.size()!=1)
			printf("%c",ovs.front()),ovs.pop();
		printf("\n");
		ovs.pop();
		while(!ops.empty())
			ops.pop();

	}
	return 0;
	
}
int p(char c)
{
	switch(c)
	{
	case '*':
	case '/':return 2;
	case '+':
	case '-':return 1;
	case '(':
	case ')':
	case '=':return 0;
	default :printf("%c_error!",c);exit(1);
	}
}
     

