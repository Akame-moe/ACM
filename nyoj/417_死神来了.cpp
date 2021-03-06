/*
----------description----------
有一天，小王子在遨游世界时，遇到了一场自然灾害。一个人孤独的在一个岛上，没有吃的没有喝的。在他饥寒交迫将要死亡时，死神来了。由于这个死神在成神之前是一个数学家，所以他有一个习惯，会和即死之人玩一个数学游戏，来决定是否将其灵魂带走。游戏规则是死神给小王子两个整数n（100<=n<=1000000）,m(2<=m<=n)，在1~n个数中，随机取m个数,问在这m个数中是否一定存在一个数是另一个数的倍数，是则回答“YES",否则”NO"。如果小王子回答正确，将有再活下去的机会。但是他很后悔以前没有好好学习数学，小王子知道你数学学得不错，请你救他一命。


----------input----------
有多组测试数据，不多于10000;
每组有两个数n,m;
以文件结束符EOF为结束标志。


----------output----------
输出"YES"或"NO"。


----------sample_input----------
100 80

100 20
----------sample_putput----------
YES

NO
*/
/////////////////////////////
#include<stdio.h>
int main() {
    int n, m, d;
    while(~scanf("%d%d", &n, &m)) {
        d = (n + 1) / 2;
        if(m <= d)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
/*
思路：这题用到了鸽笼原理（有n+1件或n+1件以上的物品要放到n个抽屉中，那么至少有一个抽屉里有两个或两个以上物品。），在本题，我们m看作为m个鸽笼，
，我们将1到N所有数的倍数分组，最大分组数为p=N / 2 + (N & 1)，看作p只鸽子，问是否能把这p只鸽子放入到m个笼子里，保证每只笼子只有一只鸽子。
比如100的分组为，此处运用二进制的思想
A1 = {1, 1*2,1*4…1*64}
A2 = {3,3*2,3*4…3*32}
…
…
A25 = {49,49*2}
…
…
A50 = {99}


鸽笼原理应用：

1、从2、4、6、…、30这15个偶数中，至少任取几个数，其中一定有两个数之和是34？

   答案： 9

2、从1、2、3、4、…、19、20这20个自然数中，至少任选几个数，就可以保证其中一定包括两个数，它们的差是12？

   答案：13

3、 从1到20这20个数中，至少任取多少个数，必有两个数，其中一个数是另一个数的倍数？

   答案：11

4、某校校庆，来了n位校友，彼此认识的握手问候.请你证明无论什么情况，在这n个校友中至少有两人握手的次数一样多？

   答案：共有n位校友，每个人握手的次数最少是0次，即这个人与其他校友都没有握过手；最多有n-1次，即这个人与每位到会校友都握了手.然而，如果有一个校友握手的次数是0次，那么握手次数最多的不能多于n-2次；如果有一个校友握手的次数是n-1次，那么握手次数最少的不能少于1次.不管是前一种状态0、1、2、…、n-2，还是后一种状态1、2、3、…、n-1，握手次数都只有n-1种情况.把这n-1种情况看成n-1个抽屉，到会的n个校友每人按照其握手的次数归入相应的“抽屉”，根据抽屉原理，至少有两个人属于同一抽屉，则这两个人握手的次数一样多。

5、15个网球分成数量不同的4堆，数量最多的一堆至少有多少个球？

   答案：此题实际是求出15可分拆多少种4个互不相同的整数之和，而15=1+2+3+9=1+2+4+8=1+2+5+7=1+3+4+7=1+3+5+6=2+3+4+6，所以最多一堆的球数可能是9、8、7、6，其中至少有6个。

整除问题

1、任取8个自然数，必有两个数的差是7的倍数。

   解析：在与整除有关的问题中有这样的性质，如果两个整数a、b，它们除以自然数m的余数相同，那么它们的差a-b是m的倍数.根据这个性质，本题只需证明这8个自然数中有2个自然数，它们除以7的余数相同.我们可以把所有自然数按被7除所得的7种不同的余数0、1、2、3、4、5、6分成七类.也就是7个抽屉.任取8个自然数，根据抽屉原理，必有两个数在同一个抽屉中，也就是它们除以7的余数相同，因此这两个数的差一定是7的倍数。

2、对于任意的五个自然数，证明其中必有3个数的和能被3整除。

   解析：

3、任意给定7个不同的自然数，求证其中必有两个整数，其和或差是10的倍数.

   解析：注意到这些数除以10的余数即个位数字，以0，1，…，9为标准制造10个抽屉，标以[0]，[1]，…，[9].若有两数落入同一抽屉，其差是10的倍数，只是仅有7个自然数，似不便运用抽屉原则，再作调整：[6]，[7]，[8]，[9]四个抽屉分别与[4]，[3]，[2]，[1]合并，则可保证至少有一个抽屉里有两个数，它们的和或差是10的


*/