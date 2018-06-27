/*
----------description----------
小珂今天刚学了编译原理，老师给她了一个作业。让他求出一段程序中给定的关键字的个数。请你帮她写一个程序，计算出结果并输出。


----------input----------
第一行有一个整数1 随后的n组数据的每一行有一个整数0


----------output----------
输出n行，统计出要求统计的关键字出现的总次数。


----------sample_input----------
2

4

char

int

double

float

int  main()

{

    int a=10;

    cout<<a<<endl;

}

@

1

int

int main()

{

   int* p;

}

@
----------sample_putput----------
2

2
*/
/////////////////////////////
#include<stdio.h>
#include<string.h>
int N;
int main() {
    char s[10][10];
    int n;
    scanf("%d", &N);
    while(N--) {
        int i;
        scanf("%d", &n);
        for(i = 0; i < n; i++)
            scanf("%s", s[i]);
        char ch;
        int j = 0;
        char w[10];
        int count = 0;
        while(scanf("%c", &ch), ch != '@') {
            if((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9') || ch == '_')
                w[j++] = ch;
            else {
                w[j] = '\0';
                j = 0;
                for(i = 0; i < n; i++) {
                    if(strcmp(w, s[i]) == 0)
                        count++;//printf("[%s]\n",w);
                }
            }
        }
        printf("%d\n", count);
    }
    return 0;

}