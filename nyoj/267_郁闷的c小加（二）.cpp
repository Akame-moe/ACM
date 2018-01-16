/*
----------description----------
聪明的你帮助C小加解决了中缀表达式到后缀表达式的转换（详情请参考“郁闷的C小加（一）”），C小加很高兴。但C小加是个爱思考的人，他又想通过这种方法计算一个表达式的值。即先把表达式转换为后缀表达式，再求值。这时又要考虑操作数是小数和多位数的情况。


----------input----------
第一行输入一个整数T，共有T组测试数据（T<10)。  
每组测试数据只有一行，是一个长度不超过1000的字符串，表示这个运算式，每个运算式都是以“=”结束。这个表达式里只包含+-* /与小括号这几种符号。其中小括号可以嵌套使用。数据保证输入的操作数中不会出现负数并且小于1000000。  
数据保证除数不会为0。  


----------output----------
对于每组测试数据输出结果包括两行，先输出转换后的后缀表达式，再输出计算结果，结果保留两位小数。两组测试数据之间用一个空行隔开。


----------sample_input----------
2
1+2=
(19+21)*3-4/5=
----------sample_putput----------
12+=
3.00

1921+3*45/-=
119.20
*/
/////////////////////////////
 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stack>
using namespace std;
typedef struct Tree
{
	char c;
	char ss[25];
	double n;
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
tree *_build(char *s)
{
	tree *root=new tree;
	strcpy(root->ss,s);
	root->liftchild=NULL;
	root->rightchild=NULL;
	return root;
}
tree *build(char ch)
{
	tree *root=new tree;
	root->c=ch;
	root->liftchild=NULL;
	root->rightchild=NULL;
	return root;
}
double calcu(double n1,char op,double n2)
{
	switch(op)
	{
	case '*':return n1*n2;
	case '/':return n1/n2;
	case '+':return n1+n2;
	case '-':return n1-n2;
	default :printf("%c_error!",op);return 0;//这里养成好习惯，把字符输出看看是哪错了。
	}
}
void visit(tree * r)
{
	if(r!=NULL)
	{
		visit(r->liftchild);
		visit(r->rightchild);
		if(r->liftchild==NULL && r->rightchild==NULL)
		{ printf("%s",r->ss); r->n=atof(r->ss);}//叶节点必定是数字
		else
		{ printf("%c",r->c); r->n=calcu(r->liftchild->n,r->c,r->rightchild->n);}//遍历的时候计算。
	}
}


int main()
{

	int i,j;
	int  N;
	scanf("%d",&N);
	char w[100];
	while(N--)
	{
		scanf("%s",s);//1-2*3-4/5=
		for(i=0;s[i]!='=';)
		{
			if(s[i]>='0' && s[i]<='9')
			{
				j=0;
				while((s[i]>='0' && s[i]<='9') || s[i]=='.')
				{
					w[j++]=s[i++];
				}
				w[j]='\0';
				//printf("[%lf]",atof(w));
				ovs.push(_build(w));
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
		printf("=\n%.2lf\n\n",Root->n);
	}
	return 0;
}
 
           