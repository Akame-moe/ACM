/*
----------description----------
题目很简单，给你一棵二叉树的后序和中序序列，求出它的前序序列（So easy!）。


----------input----------
输入有多组数据（少于100组），以文件结尾结束。
每组数据仅一行，包括两个字符串，中间用空格隔开，分别表示二叉树的后序和中序序列（字符串长度小于26，输入数据保证合法）。


----------output----------
每组输出数据单独占一行，输出对应得先序序列。


----------sample_input----------
ACBFGED ABCDEFG

CDAB CBAD
----------sample_putput----------
DBACEGF

BCAD
*/
/////////////////////////////
#include<stdio.h>
#include<string.h>
typedef struct Tree {
    char c;
    Tree *lc, *rc;
} tree;
int len_mid;
tree *build(char ch) {
    tree *r = new tree;
    r->c = ch;
    r->lc = NULL;
    r->rc = NULL;
    return r;
}
char *find(char *s, char ch) {
    while(*s != ch && *s != '\0')
        s++;
    return s;
}
void visit(tree *r) {
    if(r != NULL) {
        printf("%c", r->c);
        visit(r->lc);
        visit(r->rc);
    }
}
void  creat(tree **root, char *last, char *mid, int len) {
    if(len == 0) {
        *root = NULL;
        return ;
    }
    tree *r = build(last[len - 1]);
    *root = r;
    char *p = find(mid, r->c);
    int leftlen = strlen(mid) - strlen(p);
    int rightlen = len - leftlen - 1;
    creat(&(r->lc), last, mid, leftlen);
    creat(&(r->rc), last + leftlen, p + 1, rightlen);
}
int main() {
    char last[30], mid[30];
    while(~scanf("%s %s", last, mid)) {
        tree *root = NULL;
        len_mid = strlen(mid);
        creat(&root, last, mid, len_mid);
        visit(root);
        printf("\n");

    }
    return 0;
}

#include<stdio.h>
#include<string.h>
void ReBuild(char *pre, char *in, char *post, int len) {
    if(len > 0) {
        int n = strchr(in, post[len - 1]) - in;
        ReBuild(pre + 1, in, post, n);
        ReBuild(pre + n + 1, in + n + 1, post + n, len - n - 1);
        pre[0] = post[len - 1];
    }
}
int main() {
    char pre[30], in[30], post[30];
    int len;
    while(~scanf("%s%s", post, in)) {
        len = strlen(post);
        ReBuild(pre, in, post, len);
        pre[len] = 0;
        puts(pre);
    }
}
