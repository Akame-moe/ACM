/*
----------description----------
Given a list of phone numbers, determine if it is consistent in the sense that
no number is the prefix of another. Let's say the phone catalogue listed these
numbers:

  * Emergency 911
  * Alice 97 625 999
  * Bob 91 12 54 26

In this case, it's not possible to call Bob, because the central would direct
your call to the emergency line as soon as you had dialled the first three
digits of Bob's phone number. So this list would not be consistent.


----------input----------
The first line of input gives a single integer, 1 ≤ t ≤ 10, the number of test
cases. Each test case starts with n, the number of phone numbers, on a
separate line, 1 ≤ n ≤ 100000. Then follows n lines with one unique phone
number on each line. A phone number is a sequence of at most ten digits.


----------output----------
For each test case, output "YES" if the list is consistent, or "NO" otherwise.


----------sample_input----------
2

3

911

97625999

91125426

5

113

12340

123440

12345

98346
----------sample_putput----------
NO

YES
*/
/////////////////////////////
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node {
    int count;
    Node *next[11];
};
Node *Root;
char a[100005][11];
bool insert(char *s) {
    if(Root == NULL || *s == '\0')
        return 0;
    Node *p = Root;
    int  i;
    bool exist = false;
    while(*s != '\0') {

        if(p->next[*s - '0'] == NULL) {
            Node *temp = new Node;
            temp->count = 0;
            for(i = 0; i < 10; i++)
                temp->next[i] = NULL;
            p->next[*s - '0'] = temp;
        }
        p = p->next[*s - '0'];
        if(p->count > 0) exist = true;
        s++;
    }
    p->count++;
    return exist;
}
int comp(const void *c, const void *d) {
    return strlen((char *)c) - strlen((char *)d);
}
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, i;
        int flag = 0;
        scanf("%d", &n);
        for(i = 0; i < n; i++)
            scanf("%s", a[i]);
        qsort(a, n, sizeof(a[0]), comp);
        Root = new Node;
        Root->count = 0;
        for(i = 0; i < 10; i++)
            Root->next[i] = NULL;
        for(i = 0; i < n; i++) {
            //printf("%s\n",a[i]);
            if(flag == 0 && insert(a[i])) {
                flag = 1;
            }
        }
        printf("%s\n", flag == 0 ? "YES" : "NO");
    }
    return 0;
}



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node {
    int count;
    Node *next[11];
};
Node *Root;
//char a[100005][11];
bool insert(char *s) {
    if(Root == NULL || *s == '\0')
        return 0;
    Node *p = Root;
    int  i;
    bool exist = false;
    while(*s != '\0') {

        if(p->next[*s - '0'] == NULL) {
            Node *temp = new Node;
            temp->count = 0;
            for(i = 0; i < 10; i++)
                temp->next[i] = NULL;
            p->next[*s - '0'] = temp;
        }
        p = p->next[*s - '0'];
        if(p->count > 0) exist = true;
        s++;
    }
    for(i = 0; i < 10; i++)
        if(p->next[i] != NULL) exist = true;
    p->count++;
    return exist;
}
/*
int comp(const void *c,const void *d)
{
    return strlen((char *)c)-strlen((char *)d);
}*/
int main() {
    int T;
    scanf("%d", &T);
    char s[15];
    while(T--) {
        int n, i;
        int flag = 0;
        scanf("%d", &n);
//        for(i=0;i<n;i++)
//            scanf("%s",a[i]);
//        qsort(a,n,sizeof(a[0]),comp);
        Root = new Node;
        Root->count = 0;
        for(i = 0; i < 10; i++)
            Root->next[i] = NULL;
        for(i = 0; i < n; i++) {
            //printf("%s\n",a[i]);
            scanf("%s", s);
            if(flag == 0 && insert(s)) {
                flag = 1;
                //break;
            }
        }
        printf("%s\n", flag == 0 ? "YES" : "NO");
    }
    return 0;
}
