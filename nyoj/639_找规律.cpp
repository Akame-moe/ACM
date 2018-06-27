/*
----------description----------
xiaod
在小学时最喜欢上数学课了，有一次上课，数学老师布置了一道题目：给你一组有规律的整数，而且只给出前5项，让你求出后面5项。比如：1,2,3,4,5,__,__,__,__,__。显然这是等差数列，所以答案应该是6,7,8,9,10。为了简化题目，老师规定规律只有三种：等差数列、等比数列、斐波那契数列（f[i]=f[i-2]+f[i-1]）；且公差、公比均为整数，所有出现的数字不会超出
int 范围。怎么样，很简单吧？聪明的你，来比一比你和 xiaod 谁算的快吧。


----------input----------
有多组测试数据。
每行5个整数，代表题目给出的前5项。


----------output----------
如果能找到符合条件的规律，则输出5个整数，代表后5项的值。
否则，请输出"None"。（引号不用输出）


----------sample_input----------
1 2 3 4 5

2 3 5 8 13
----------sample_putput----------
6 7 8 9 10

21 34 55 89 144
*/
/////////////////////////////
#include<cstdio>
#include<cmath>
int a[15];
int main() {
    int dengcha();
    int dengbi();
    int fbnq();
    int i;
    while(~scanf("%d%d%d%d%d", &a[0], &a[1], &a[2], &a[3], &a[4])) {
        if(dengcha()) {
            for(i = 1; i <= 5; i++)
                printf("%d ", a[4] + i * (a[1] - a[0]));
        } else if(fbnq()) {
            for(i = 5; i <= 9; i++) {
                a[i] = a[i - 1] + a[i - 2];
                printf("%d ", a[i]);
            }
        } else if(dengbi()) {
            for(i = 1; i <= 5; i++)
                printf("%d ", a[4] * (int)(pow(a[1] / a[0], i)));
        } else
            printf("None");
        printf("\n");
    }
    return 0;
}
int dengcha() {
    int i;
    for(i = 1; i <= 3; i++) {
        if((a[i] - a[i - 1]) != (a[i + 1] - a[i]))
            break;
    }
    if(i > 3)
        return 1;
    else
        return 0;
}
int dengbi() {
    if(a[0] == 0 || a[1] == 0 || a[2] == 0 || a[3] == 0 || a[4] == 0)
        return 0;
    int i;
    for(i = 1; i <= 3; i++) {
        if((a[i] * 1.0 / a[i - 1]) != (a[i + 1] * 1.0 / a[i]))
            break;
    }
    if(i > 3)
        return 1;
    else
        return 0;
}
int fbnq() {
    int i;
    for(i = 2; i <= 4; i++) {
        if(a[i] != a[i - 1] + a[i - 2])
            break;
    }
    if(i > 4)
        return 1;
    else
        return 0;
}
