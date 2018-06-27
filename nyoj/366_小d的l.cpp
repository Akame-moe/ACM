/*
----------description----------
一天TC的匡匡找ACM的小L玩三国杀，但是这会小L忙着哩，不想和匡匡玩但又怕匡匡生气，这时小L给匡匡出了个题目想难倒匡匡(小L很D吧![](http://59.69.128.200/JudgeOnline/admin/kind/plugins/emoticons/44.gif))，有一个数n(0，，，聪明的你能帮匡匡解围吗？


----------input----------
第一行输入一个数N（0<N<10）,表示有N组测试数据。后面的N行输入多组输入数据，每组输入数据都是一个整数x(0<x<10)


----------output----------
按特定顺序输出所有组合。
特定顺序：每一个组合中的值从小到大排列，组合之间按字典序排列。


----------sample_input----------
2

2

3
----------sample_putput----------
12

21

123

132

213

231

312

321
*/
/////////////////////////////

//366

#include<algorithm>
#include<stdio.h>
#include<iostream>
using namespace std;
int n;
int main() {
    int a[11];
    int N, i;
    scanf("%d", &N);
    while(N--) {
        scanf("%d", &n);
        for(i = 1; i <= n; i++)
            a[i] = i;
        do {
            for(i = 1; i <= n; i++)
                printf("%d", a[i]);
            printf("\n");
        } while(next_permutation(a + 1, a + n + 1));
    }
    return 0;
}
#include<stdio.h>
int n;
int a[11];
int vis[11];
void dfs(int cur) {
    int k, i;
    if(cur == (n + 1)) {
        for(k = 1; k <= n; k++)
            printf("%d", a[k]);
        printf("\n");
    }
    for(i = 1; i <= n; i++) {
        if(!vis[i]) {
            a[cur] = i;
            vis[i] = 1;
            dfs(cur + 1);
            vis[i] = 0;
        }
    }

}


int main() {

    int N, i;
    scanf("%d", &N);
    while(N--) {
        for(i = 1; i <= 10; i++)
            vis[i] = 0;
        scanf("%d", &n);
        dfs(1);
    }
    return 0;
}

这是一个求一个排序的下一个排列的函数，可以遍历全排列, 要包含头文件<algorithm>
下面是以前的笔记    与之完全相反的函数还有prev_permutation


(1) int 类型的next_permutation

int main() {
    int a[3];
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    do {
        cout << a[0] << " " << a[1] << " " << a[2] << endl;
    } while (next_permutation(a, a + 3)); //参数3指的是要进行排列的长度

//如果存在a之后的排列，就返回true。如果a是最后一个排列没有后继，返回false，每执行一次，a就变成它的后继


}

输出：

1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1


如果改成 while(next_permutation(a, a + 2));
则输出：
1 2 3
2 1 3

只对前两个元素进行字典排序
显然，如果改成 while(next_permutation(a, a + 1));
则只输出：1 2 3



若排列本来就是最大的了没有后继，则next_permutation执行后，会对排列进行字典升序排序, 相当于循环

int list[3] = {3, 2, 1};
next_permutation(list, list + 3);
cout << list[0] << " " << list[1] << " " << list[2] << endl;

//输出: 1 2 3





(2) char 类型的next_permutation

int main() {
    char ch[205];
    cin >> ch;

    sort(ch, ch + strlen(ch) );
//该语句对输入的数组进行字典升序排序。如输入9874563102 cout<<ch; 将输出0123456789,这样就能输出全排列了

    char *first = ch;
    char *last = ch + strlen(ch);

    do {
        cout << ch << endl;
    } while(next_permutation(first, last));
    return 0;
}

//这样就不必事先知道ch的大小了，是把整个ch字符串全都进行排序
//若采用 while(next_permutation(ch,ch+5)); 如果只输入1562，就会产生错误，因为ch中第五个元素指向未知
//若要整个字符串进行排序，参数5指的是数组的长度，不含结束符






(3) string 类型的next_permutation

int main() {
    string line;
    while(cin >> line && line != "#") {
        if(next_permutation(line.begin(), line.end())) //从当前输入位置开始
            cout << line << endl;
        else cout << "Nosuccesor\n";
    }
}



int main() {
    string line;
    while(cin >> line && line != "#") {
        sort(line.begin(), line.end()); //全排列
        cout << line << endl;
        while(next_permutation(line.begin(), line.end()))
            cout << line << endl;
    }
}






next_permutation 自定义比较函数


#include<iostream> //poj 1256 Anagram
#include<string>
#include<algorithm>
using namespace std;
int cmp(char a, char b) { //'A'<'a'<'B'<'b'<...<'Z'<'z'.
    if(tolower(a) != tolower(b))
        return tolower(a) < tolower(b);
    else
        return a < b;
}
int main() {
    char ch[20];
    int n;
    cin >> n;
    while(n--) {
        scanf("%s", ch);
        sort(ch, ch + strlen(ch), cmp);
        do {
            printf("%s\n", ch);
        } while(next_permutation(ch, ch + strlen(ch), cmp));
    }
    return 0;
}