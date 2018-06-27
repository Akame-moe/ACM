/*
----------description----------
聪明的你帮助C小加解决了中缀表达式到后缀表达式的转换（详情请参考“郁闷的C小加（一）”），C小加很高兴。但C小加是个爱思考的人，他又想通过这种方法计算一个表达式的值。即先把表达式转换为前缀和后缀表达式，再求值。这时又要考虑操作数是小数和多位数的情况。


----------input----------
第一行输入一个整数T，共有T组测试数据（T<10)。
每组测试数据只有一行，是一个长度不超过1000的字符串，表示这个运算式，每个运算式都是以“=”结束。这个表达式里只包含+-* /与小括号这几种符号。其中小括号可以嵌套使用。数据保证输入的操作数中不会出现负数并且小于1000000。
数据保证除数不会为0。


----------output----------
对于每组测试数据输出结果包括三行，先输出转换后的前缀和后缀表达式，再输出计算结果，结果保留两位小数。


----------sample_input----------
2

1+2=

(19+21)*3-4/5=
----------sample_putput----------
+ 1 2 =

1 2 + =

3.00

- * + 19 21 3 / 4 5 =

19 21 + 3 * 4 5 / - =

119.20
*/
/////////////////////////////

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stack>
using namespace std;
typedef struct Tree {
    char c;
    char ss[25];
    double n;
    Tree *liftchild, *rightchild;
} tree;
stack <tree*> ops;
stack <tree*> ovs;
tree *Root;
char s[1005];
int p(char ch) {
    switch(ch) {
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    case '(':
    case ')':
        return 0;
    case ';':
        return -1;
    default :
        printf("%c_error!\n", ch);
        exit(1);
    }
}
tree *_build(char *s) {
    tree *root = new tree;
    strcpy(root->ss, s);
    root->liftchild = NULL;
    root->rightchild = NULL;
    return root;
}
tree *build(char ch) {
    tree *root = new tree;
    root->c = ch;
    root->liftchild = NULL;
    root->rightchild = NULL;
    return root;
}
double calcu(double n1, char op, double n2) {
    switch(op) {
    case '*':
        return n1 * n2;
    case '/':
        return n1 / n2;
    case '+':
        return n1 + n2;
    case '-':
        return n1 - n2;
    default :
        printf("%c_error!", op);
        return 0;//这里养成好习惯，把字符输出看看是哪错了。
    }
}
void visit(tree * r) {
    if(r != NULL) {
        visit(r->liftchild);
        visit(r->rightchild);
        if(r->liftchild == NULL && r->rightchild == NULL) {
            printf("%s ", r->ss);    //叶节点必定是数字
            r->n = atof(r->ss);
        } else {
            printf("%c ", r->c);    //遍历的时候计算。
            r->n = calcu(r->liftchild->n, r->c, r->rightchild->n);
        }
    }
}
void _visit(tree * r) {
    if(r != NULL) {
        if(r->liftchild == NULL && r->rightchild == NULL)
            printf("%s ", r->ss);
        else
            printf("%c ", r->c);
        _visit(r->liftchild);
        _visit(r->rightchild);
    }
}

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<windows.h>
using namespace std;
template <class T>
class mystack { //自定义栈类，方便栈的输出
    T sta[500];
    int s_top;
  public:
    mystack() {
        s_top = 0;
    }
    void push(T n) {
        if(s_top >= 499)
            printf("栈满了，进栈失败！\n");
        else
            sta[++s_top] = n;
    }
    void pop() {
        if(s_top == 0) {
            printf("栈为空，不能出栈。\n");
            exit(1);
        } else
            --s_top;
    }
    T top() {
        return sta[s_top];
    }
    void clear() {
        s_top = 0;
    }
    bool empty() {
        return s_top == 0;
    }
    int size() {
        return s_top;
    }
    void printstack() {
        int i;
        for(i = 1; i <= s_top; i++)
            cout << sta[i] << " ";
        printf("      大小是:%d\n", s_top);
    }
};
typedef struct Tree {
    char c;
    char ss[25];
    double n;
    Tree *liftchild, *rightchild;
} tree;
int comp(char);
double calculate(double, char, double);
double work(char *);
tree* creat_tree(char *);
void visit(tree *);
void _visit(tree *);
int main() {
    char s[1005];
    int n, m;
    printf("\n\n+++++++++++++++欢迎进入本程序+++++++++++++++\n\n\n\n");
    printf("请输入中缀表达式(式子以\"=\"结束):");
    scanf("%s", s);
    do {
        printf("\n+++++++++++++++请选择你的操作++++++++++++\n");
        printf("1、表达式求值\t2、输出前缀式\t3、输出后缀式\n");
        printf("4、更换表达式\t5、清屏\t\t6、退出\n\n\n请输入你的选择:");
        scanf("%d", &n);
        switch(n) {
        case 1:
            printf("\n\n%s%.2lf", s, work(s));
            break;
        case 2:
            printf("前缀式是: ");
            _visit(creat_tree(s));
            printf("=\n");
            break;
        case 3:
            printf("后缀式是: ");
            visit(creat_tree(s));
            printf("=\n");
            break;
        case 4:
            printf("请输入中缀表达式(式子以\"=\"结束):");
            scanf("%s", s);
            break;
        case 5:
            system("cls");
            break;
        case 6:
            printf("确定要退出？(1/0):");
            scanf("%d", &m);
            if(m) exit(0);
            else break;
        }
    } while(1);
    return 0;

}

mystack <tree*> ops1;
mystack <tree*> ovs1;
tree *_build(char *s) {
    tree *root = new tree;
    strcpy(root->ss, s);
    root->liftchild = NULL;
    root->rightchild = NULL;
    return root;
}
tree *build(char ch) {
    tree *root = new tree;
    root->c = ch;
    root->liftchild = NULL;
    root->rightchild = NULL;
    return root;
}
void visit(tree * r) {
    if(r != NULL) {
        visit(r->liftchild);
        visit(r->rightchild);
        if(r->liftchild == NULL && r->rightchild == NULL) {
            printf("%s ", r->ss);    //叶节点必定是数字
            r->n = atof(r->ss);
        } else {
            printf("%c ", r->c);    //遍历的时候计算。
            r->n = calculate(r->liftchild->n, r->c, r->rightchild->n);
        }
    }
}
void _visit(tree * r) {
    if(r != NULL) {
        if(r->liftchild == NULL && r->rightchild == NULL)
            printf("%s ", r->ss);
        else
            printf("%c ", r->c);
        _visit(r->liftchild);
        _visit(r->rightchild);
    }
}

tree* creat_tree(char *s) {
    tree *Root;
    int i, j;
    char w[20];
    for(i = 0; s[i] != '=';) {
        if(s[i] >= '0' && s[i] <= '9') {
            j = 0;
            while((s[i] >= '0' && s[i] <= '9') || s[i] == '.') {
                w[j++] = s[i++];
            }
            w[j] = '\0';
            //printf("[%lf]",atof(w));
            ovs1.push(_build(w));
        } else {
            if(ops1.empty() || s[i] == '(' || comp(ops1.top()->c) < comp(s[i]) )
                ops1.push(build(s[i])), i++;
            else if(ops1.top()->c == '(' && s[i] == ')')
                ops1.pop(), i++;
            else { //p(ops.top())>=p(s[i])
                ops1.top()->rightchild = ovs1.top();
                ovs1.pop();
                ops1.top()->liftchild = ovs1.top();
                ovs1.pop();
                Root = ops1.top();
                ops1.pop();
                ovs1.push(Root);
            }
        }
    }
    while(ovs1.size() != 1) {
        ops1.top()->rightchild = ovs1.top();
        ovs1.pop();
        ops1.top()->liftchild = ovs1.top();
        ovs1.pop();
        Root = ops1.top();
        ops1.pop();
        ovs1.push(Root);
    }
    Root = ovs1.top();
    ovs1.clear();
    ops1.clear();
    return Root;
}

mystack<double> ovs;//运算数栈
mystack<char> ops;//操作符栈
double work(char *s) {
    int i, j;
    double num1, num2, ans;
    char op;
    char w[20];
    ops.push('#');
    for(i = 0; s[i] != '=';) {
        printf("当前处理:");
        if(s[i] >= '0' && s[i] <= '9') { //处理数字
            j = 0;
            w[j++] = s[i++];
            while((s[i] >= '0' && s[i] <= '9') || s[i] == '.') {
                w[j++] = s[i++];
            }
            w[j] = '\0';
            printf("%s\n", w);
            ovs.push(atof(w));
        } else { //运算符

            if(s[i] == '(' || comp(ops.top()) < comp(s[i])) {
                printf("%c\n", s[i]);
                ops.push(s[i]);
                i++;
            } else if(ops.top() == '(' && s[i] == ')') {
                printf("%c\n", s[i]);
                ops.pop();
                i++;
            } else {
                num2 = ovs.top();
                ovs.pop();
                num1 = ovs.top();
                ovs.pop();
                op = ops.top();
                ops.pop();
                //printf("%lf%c%lf\n",num1,op,num2);
                cout << num1 << " " << op << " " << num2 << endl;
                ovs.push(calculate(num1, op, num2));
            }
        }
        printf("运算符当前栈为:");
        ops.printstack();
        printf("操作数当前栈为:");
        ovs.printstack();
        printf("\n");

    }
    while(ovs.size() != 1) { //最后只剩下同级运算
        printf("当前处理:");
        num2 = ovs.top();
        ovs.pop();
        num1 = ovs.top();
        ovs.pop();
        op = ops.top();
        ops.pop();
        //printf("%lf%c%lf\n",num1,op,num2);
        cout << num1 << " " << op << " " << num2 << endl;
        printf("运算符当前栈为:");
        ops.printstack();
        printf("操作数当前栈为:");
        ovs.printstack();
        printf("\n");
        ovs.push(calculate(num1, op, num2));
    }
    ans = ovs.top();
    ovs.clear();//清空
    ops.clear();//清空
    return ans;
}
int comp(char op) {
    int t;
    switch(op) {
    case '^':
        t = 4;
        break;
    case '*':
    case '/':
        t = 3;
        break;
    case '+':
    case '-':
        t = 2;
        break;
    case '(':
    case ')':
        t = 1;
        break;
    case '#':
        t = 0;
        break;
    default :
        printf("%c_error!\n", op);
        exit(1);
    }
    return t;
}
double calculate(double num1, char op, double num2) {
    double ans;
    switch(op) {
    case '^':
        ans = pow(num1, num2);
        break;
    case '*':
        ans = num1 * num2;
        break;
    case '/':
        ans = num1 / num2;
        break;
    case '+':
        ans = num1 + num2;
        break;
    case '-':
        ans = num1 - num2;
        break;
    default :
        printf("%c_error!\n", op);
        exit(1);
    }
    return ans;
}



