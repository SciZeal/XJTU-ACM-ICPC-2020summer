# 2020 小学期 1 - Day 01

## [1-01A.czq的整型溢出](http://39.102.65.150/contest/28/problem/1)

>   整型是计算机存储数据的一种模式。一种特定的整型只能存储处于特定范围内的数据。（例如，短整型short可以存储的数字大小一般不超过32767。）当一个整型中存储的数据超过了它的容纳范围时，这个数据便不能被正确地表达出来。我们将这种情况称为整型的溢出。通俗地讲，可以将它理解为物极必反的意思。
>
>   ————《整型溢出：信息学竞赛的发展，繁荣与衰退》

给定两个使用32位有符号整型存储的数 $a,b$，判断计算`a+b`时是否会发生溢出。

### 输入格式

一行两个由空格隔开的整数 $a,b$。

### 输出格式

如果发生了溢出，输出`overflow`，否则输出`ok`。

### 样例

#### 输入

```in
2147483647 1
```

#### 输出

```out
overflow
```

### 数据范围与提示

$-2^{31}\leqslant a,b\leqslant2^{31}-1$

## [1-01B.czq的奇怪代码](http://39.102.65.150/contest/28/problem/2)

czq最近发现了许多代码，他希望你能够帮他分析一下每个函数的时间复杂度。

```c++
#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 210000
#define MAXM 410000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

//czq很喜欢lowbit函数，这个函数可以计算n二进制下的最低一位1的值 
int lowbit(int n)
{
	return n&-n; 
}

//这是最朴素的试除法判断素数 
bool checkprime1(int n)
{
	for (int i=2;i<n;i++)
		if (n%i==0)
			return false;
	return true; 
}

//试除法的一种改进 
bool checkprime2(int n)
{
	for (int i=2;i*i<=n;i++)
		if (n%i==0)
			return false;
	return true; 
}

//递归求解调和级数前n项和 
double f(int n)
{
	if (n==0)
		return 0;
	else
		return f(n-1)+1/(double)n;
} 

//统计n二进制下1的个数 
int bitcount(int n)
{
	int ans=0;
	while (n)
	{
		ans+=(n&1);
		n>>=1;
	}
	return ans;
} 

//这个递归函数用于对数组求和 
int getsum(int a[],int l,int r)
{
	if (l==r)
		return a[l];
	int mid=(l+r)>>1;
	return getsum(a,l,mid)+getsum(a,mid+1,r);
}

//排序函数。。。然而为什么有点慢？这里认为sort函数只使用快速排序。 
void mysort(int a[],int l,int r)
{
	if (l==r)
		return;
	int mid=(l+r)>>1;
	mysort(a,l,mid);
	mysort(a,mid+1,r);
	sort(a+l,a+r+1);
}


//这个代码出自寒域爷闲暇时候用来测试Node.js语言和C语言的速度差距。该函数用于求斐波那契数列的第x项
long long int fibonacci(int _Xx) {
    if (_Xx <= 2) return 1;
    return fibonacci(_Xx - 1) + fibonacci(_Xx - 2);
}

 
int main()
{
	
	return ~~(0^_^0);
}
```

你需要编写程序输出答案。具体格式见“输出格式”。

### 输入格式

没有输入

### 输出格式

如果满足多个时间复杂度，请选择最早出现的那一个。

|    时间复杂度 | 你要写的内容 |
| ------------: | :----------- |
|        $O(1)$ | 1            |
|   $O(\log n)$ | logn         |
| $O(\sqrt{n})$ | sqrt(n)      |
|        $O(n)$ | n            |
|  $O(n\log n)$ | nlogn        |
| $O(n\log^2n)$ | nlog2n       |
|      $O(n^2)$ | n2           |
|      $O(n^3)$ | n3           |
|      $O(n^4)$ | n4           |
|      $O(2^n)$ | 2n           |
|       $O(n!)$ | n!           |

你可以使用这个模板：

```c++
#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 210000
#define MAXM 410000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;


int main()
{
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	return ~~(0^_^0);
}
```

### 样例

#### 输出

```out
1
logn
sqrt(n)
n
nlogn
nlog2n
n2
n3
n4
2n
n!
```

## [1-01C.JM的无限操作](http://39.102.65.150/contest/28/problem/3)

JM有一个长为 $n$ 的数组 $a$，数组的下标为 $1,2,\cdots,n$。他可以进行任意多次如下这种操作：

-   对于两个正整数 $i$ 和 $j$，如果此时数组 $a$ 满足 $a_i+a_j$ 是偶数，则交换 $a_i$ 和 $a_j$ 的值。

现在JM想知道，他在任意次操作之后，能得到的字典序最小的数组是什么？

### 输入格式

第一行一个正整数 $n$ ，表示数组的长度。

接下来一行 $n$ 个正整数，表示数组中的元素。

### 输出格式

输出一行 $n$ 个正整数，表示能得到的字典序最小的数组。

### 样例

#### 输入

```in
3
3 2 1
```

#### 输出

```out
1 2 3
```

### 数据范围与提示

$1\leqslant n\leqslant2\cdot10^5$

$1\leqslant a_i\leqslant10^9$

## [1-01D.JM的完美集合](http://39.102.65.150/contest/28/problem/4)

JM是强迫症晚期患者，他执着于集合的完美性，他认为，如果一个集合中所有元素之和恰好为 $0$ ，那么这个集合是完美的。

给定一个大小为 $n$ 的可重复集合 $A$，判断该集合存在多少个非空子集是完美的。

>   可重复集合的意思是集合中可能有重复的元素，此时也可能存在多个相同的满足条件的子集，要按照多个来算。

### 输入格式

第一行一个正整数 $n$，表示集合大小。

第二行 $n$ 个整数，表示集合中的元素。

### 输出格式

一行一个非负整数，表示满足条件的非空子集的个数。

### 样例

#### 输入

```in
3
1 2 -1
```

#### 输出

```out
1
```

### 数据范围与提示

$1\leqslant n\leqslant35$

$-5\cdot10^7\leqslant A_i\leqslant5\cdot10^7$

## [1-01E.czq的模k异或](http://39.102.65.150/contest/28/problem/5)

给定一个长度 $n$ 为初始全为 0 的数列 $a_i$，下标从 1 开始。定义操作`模k异或v`为对所有满足 $i\equiv0(\text{mod}~k)$ 的下标 $i$，将 $a_i$ 异或上整数 $v$（即令 $a_i=a_i\oplus v$ ）。

给出 $q$ 次操作，每次操作之后输出序列的异或和，并且在操作结束之后输出整个序列。

>   序列的异或和为 $a_1\oplus a_2\oplus\cdots\oplus a_n$

### 输入格式

第一行两个整数 $n,q$。

接下来 $q$ 行，每行两个整数 $k_i,v_i$。

### 输出格式

输出共 $q+1$ 行，其中前 $q$ 行每行一个整数，为每次操作结束后的序列的异或和。

最后一行为操作结束后的序列。

### 样例

#### 输入

```in
10 3
1 1
2 2
3 4
```

#### 输出

```out
0
2
6
1 3 5 3 1 7 1 3 5 3
```

### 数据范围与提示

$1\leqslant n,q\leqslant2\times10^5$

$1\leqslant k_i,v_i\leqslant10^9$

## [1-01F.czq的疑惑矩阵](http://39.102.65.150/contest/28/problem/6)

czq获得了一个 01 矩阵。直觉告诉他，这里面蕴藏了珍贵的宝藏（~~1分~~）。然而矩阵的内容却让他十分疑惑，百思不得其解。

无敌的lhz告诉czq，他可以将矩阵的若干位置的数取反。如果矩阵的所有由 1 组成的和由 0 组成的极大连通块全部恰好为矩形，那么一切疑惑都会解开。当然，必须取反尽可能少的数才能获取宝藏。蒟蒻的czq不会做，所以他把这题抛给了你。

>   这里的联通定义为四联通，即一个元素与它上下左右四个元素相邻。

### 输入格式

第一行两个数 $n,m$，为矩阵的大小。

接下来 $n$ 行每行 $m$ 个数，为 01 矩阵。

### 输出格式

仅一个整数，为答案。

### 样例

#### 输入

```in
5 5
1 0 1 0 0
1 1 1 1 1
1 1 1 0 1
0 0 0 1 0
1 1 1 0 0
```

#### 输出

```out
4
```

#### 样例说明

```note
一种可能的答案
1 1 1 0 1
1 1 1 0 1
1 1 1 0 1
0 0 0 1 0
1 1 1 0 1
```

### 数据范围与提示

$1\leqslant n,m\leqslant24$
