/*
----------description----------
为什么1小时有60分钟，而不是100分钟呢？这是历史上的习惯导致。

但也并非纯粹的偶然：60是个优秀的数字，它的因子比较多。

事实上，它是1至6的每个数字的倍数。即1,2,3,4,5,6都是可以除尽60。

  

我们希望寻找到能除尽1至n的的每个数字的最小整数m.


----------input----------
多组测试数据（少于500组）。  
每行只有一个数n(1<=n<=100).


----------output----------
输出相应的m。


----------sample_input----------
2
3
4

----------sample_putput----------
2
6
12

*/
/////////////////////////////
package ceshi;
import java.math.*;
import java.util.*;
import java.io.*;
public class Main{
	public  static BigInteger  f(int n){
		BigInteger temp=new BigInteger("1");	
		BigInteger val=new BigInteger("1");
		for(int i=1;i<=n;i++){
			temp=((temp.multiply(val)).divide(temp.gcd(val)));
		val=val.add(BigInteger.ONE);
		}
		return temp;
	}

	public static void main(String args[])  throws Exception{
		Scanner sc=new Scanner(System.in);
		BigInteger a[] = new BigInteger[105];
		for(int i=1;i<=102;i++){
			a[i]=f(i);
//			System.out.println(a[i]);
		}
		int n;
		while(sc.hasNext()){
			n=sc.nextInt();
			System.out.println(a[n]);
		}
	}
}