/*
----------description----------
家住非洲的小孩，都很黑。为什么呢？
第一，他们地处热带，太阳辐射严重。
第二，他们不经常洗澡。（常年缺水，怎么洗澡。）
现在，在一个非洲部落里，他们只有一个地方洗澡，并且，洗澡时间很短，瞬间有木有！！（这也是没有的办法，缺水啊！！）
每个小孩有一个时间段能够洗澡。并且，他们是可以一起洗的（不管你是男孩是女孩）。
那么，什么时间洗澡，谁应该来洗，由谁决定的呢？那必然是他们伟大的“澡”神啊。“澡”神有一个时间表，记录着该部落的小孩，什么时候段可以洗澡。现在，“澡”神要问你，一天内，他需要最少开启和关闭多少次洗澡的水龙头呢？因为，开启和关闭一次水龙头是非常的费力气的，即便，这也是瞬间完成的。


----------input----------
多组数据
第一行一个0 接下来n行，每行一个时间段。H1H1:M1M1-H2H2:M2M2，24小时制。
保证该时间段是在一天之内的。但是，不保证，H1H1:M1M1先于H2H2:M2M2。


----------output----------
题目描述，“澡”神最少需要开启和关闭多少次水龙头呢？


----------sample_input----------
1

00:12-12:12

3

00:12-13:14

13:13-18:00

17:00-19:14
----------sample_putput----------
1

2
*/
/////////////////////////////
#include<stdio.h>
#include<stdlib.h>
struct T {
    int lift;
    int right;
} t[101];
int comp(const void *a, const void *b) {
    return (*(T*)a).right - (*(T*)b).right;
}
int main() {
    int h1, m1, h2, m2;
    int n;
    int i;
    int count;
    int flag;
    while(scanf("%d", &n) != EOF) {
        for(i = 0; i < n; i++) {
            scanf("%d:%d-%d:%d", &h1, &m1, &h2, &m2);
            t[i].lift = h1 * 60 + m1;
            t[i].right = h2 * 60 + m2;
            if(t[i].lift > t[i].right) {
                count = t[i].right;
                t[i].right = t[i].lift;
                t[i].lift = count;
            }
        }
        qsort(t, n, sizeof(T), comp);
        count = 1;
        flag = t[0].right;
        for(i = 1; i < n; i++) {
            if(flag < t[i].lift) {
                count++;
                flag = t[i].right;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
