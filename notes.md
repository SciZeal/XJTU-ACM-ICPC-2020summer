# Day 01: 绪论

>   difficulty: ⭐(by czq)

## ACM - ICPC

-   ACM: Association for Computing Machinery
-   ICPC: International Collegiate Programming Contest

### Online Judge (OJ) Feedback

-   **AC:** Accepted
-   **WA:** Wrong Answer
-   **TLE:** Time Limit Exceeded
-   **MLE:** Memory Limit Exceeded
-   **CE:** Compile Error
-   **RE:** Runtime Error

## C++ 入门

### 基础

一段示例代码:

```c++
#include <bits/stdc++.h> // 万能头文件
using namespace std;     // 使用标准命名空间
typedef long long LL;    // 定义 long long 缩写为 LL
int main()
{
    LL x, y;
    cin >> x >> y;                 // 输入
    cout << x << " " << y << endl; // 输出
    return 0;
}
```

### 引用

C 交换函数 `void swap(int *a, int *b)`

```c
void swap(int *a, int *b)
{
    int t = *b;
    *b = *a;
    *a = t;
}
```

C++ 交换函数 (<u>指针的使用更简单明了</u>)

>   不能直接命名 `swap` 因为 C++ 中已经有 `swap` 函数了.

```c++
void swap2(int &a, int &b)
{
    int t = b;
    b = a;
    a = t;
}
```

## 排序

-   冒泡排序
-   快速排序
-   桶排序

## 时间复杂度

大 $O$ 记号:

-   忽略较小项与常数
-   有退化情况

例题 (判断以下各个程序复杂度):

```c++
// O(n^2)
for (int i = 1; i <= n; i++)
{
    for (int j = 1; j <= n; j++)
        sum += i * j;
}

// O(n^2)
for (int i = 1; i <= n; i++)
{
    for (int j = i; j <= n; j++)
        sum += i * j;
}

// O(nlogn)
for (int i = 1; i <= n; i += i)
{
    for (int j = 1; j <= n; j++)
        sum += i * j;
}

// O(n)
for (int i = 1; i <= n; i += i)
{
    for (int j = i; j > 0; j--)
        sum += i * j;
}

// O(nlogn)
for (int i = 1; i <= n; i++)
{
    for (int j = 1; j <= n; j += i)
        sum += i * j;
}
```

>   递归的时间复杂度? 画出递归树

## STL 选讲

-   快速排序: `sort(arr, arr + len, cmp)`
-   容器:
    -   `pair<int, double> pr`
        -   `p.first` / `p.second`
        -   `make_pair(v1, v2)`
    -   `stack<int> s`
        -   `s.push(x)` / `s.pop()`
        -   `s.top()`
        -   `s.size()`
    -   `queue<int> q`
        -   `q.push(x)` / `q.pop()`
        -   `q.front()`
        -   `q.size()`
    -   `vector<int> vec`
        -   `vec.push_back(x)`
        -   `vec.size()`
        -   `vec[i]`
        -   `vec.begin()` / `vec.end()`
    -   `map` 映射(类似 python 字典)
    -   `string` 字符串
    -   `set` 集合
    -   `unordered_set` 无序集合(哈希映射)
    -   `deque` 双端队列
    -   `bitset` 位向量
    -   `unique` 去重
-   二分查找:
    -   `lower_bound` / `upper_bound`

## 位运算

### 按位与 &

$21 \& 19$ 即 $10101~\&~10011 = 10001$ 为 $17$

### 按位或 |

$21 \& 19$ 即 $10101~|~10011 = 10111$ 为 $23$

### 按位异或 ^

$21 \& 19$ 即 $10101 \land 10011 = 00110$ 为 $6$

**有趣性质:**

-   `a ^ a = 0`
-   `0 ^ a = a`
-   `a ^ b = b ^ a`
-   `(a ^ b) ^ c = a ^ (b ^ c)`

### 按位非 ~

每一位都要取非, 包括符号位

### 左移 << / 右移 >>

`5 << 2` 即 $00101 \Rightarrow 10100$ 为 $20$

`5 >> 2` 即 $00101 \Rightarrow 00001$ 为 $1$

## 枚举

### 二进制枚举

### 折半枚举

## 常识

### 字典序

### 模运算

### C++ 11 特性

# Day 02: 贪心与分治

>   difficulty: ⭐⭐(by cyy)

## 贪心

### 例题

### 快速幂

```c++
int pow(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = 1LL * ans * a % p;
        }
        a = 1LL * a * a % p;
        b >>= 1;
    }
    return ans;
}
```

>   矩阵快速幂: 重载乘号

#### 例题

### 二分查找

```c++
int bin_search(int left, int right, int val)
{
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (a[mid] == val)
        {
            return mid;
        }
        if (a[mid] < val)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
}
```

#### 例题

## 分治

### 归并排序与逆序对

```c++
void merge_sort(int *A, int x, int y, int *T)
{
    if (y - x > 1)
    {
        int mid = x + (y - x) / 2;
        int p = x, q = mid, i = x;

        // recursion
        merge_sort(A, x, mid, T);
        merge_sort(A, mid, y, T);

        while (p < mid || q < y)
        {
            if (q >= y || (p < mid && A[p] <= A[q]))
            {
                T[i++] = A[p++];
            }
            else
            {
                T[i++] = A[q++];
                cnt += mid - p; // inverse pair
            }
        }
        for (int i = x; i < y; i++)
        {
            A[i] = T[i];
        }
    }
}
```

# Day 03: 搜索

>   difficulty: ⭐⭐(by wch)

## DFS 和 BFS

### 深度优先搜索 (DFS)

>   Depth-First Search

用栈实现

代码框架:

```c++
int DFS(深度, 当前状态)
{
    if (结束条件)
        记录结果;
	for (节点)
    {
        操作;
        DFS(深度 + 1, 总 + 新); // 递归
        还原操作;               // 回溯
    }
    总结结果;
    return 反馈;
}
```

#### DFS 序

#### 八皇后问题

### 广度优先搜索 (BFS)

>   Breadth-First Search

用队列实现

代码框架

```c++
queue<数据类型> q;
while (!q.empty())
{
    for (节点)
    {
        q.push();
        操作;
        q.pop();
    }
}
```

### 区别

-   DFS 适合搜索所有解
-   BFS 适合搜索最短路径的解

## 剪枝

剪掉提前淘汰的情况, 降低复杂度.

## 双向搜索

类似折半枚举

## 记忆化搜索

## IDA*

BFS + 估价函数

如果搜到某一步已经不合要求, 进行剪枝.

### 埃及分数

# Day 04: 动态规划

>   difficulty: ⭐⭐⭐(by zxh)

## 动态规划理论

>   Dynamic Programming (DP)

### 走台阶问题

要走n级台阶，每次可以走一级，也可以走两级，求方案数

$F(n)=F(n-1)+F(n-2)$

### 解题方法 (三要素)

-   状态表示: 如何将实际问题用表格（即数组）的形式来表示
-   **状态转移:** 如何由已知状态得到未知状态
-   状态边界: 哪些状态不用转移就可以得到

>   复杂度 = 状态数 × 转移复杂度 = 表项个数 × 填单位格子时间

### 问题要求

使用动态规划需要满足以下三个条件

-   最优子结构: 全局最优解包含局部最优解
-   重叠子问题: 子问题出现大量重叠
-   无后效性: 每次决策不会影响之后的决策

### 例题

#### 数字三角形

#### 石子合并

## 背包问题

状态表示: `dp[i][j]`表示前 $i$ 个物品，有容量为 $j$ 时的最大价值

### 01 背包问题

状态转移: $dp[i][j]=\max(dp[i-1][j],dp[i-1][j-c]+w)$

### 满包问题

### 完全背包问题

状态转移: $\displaystyle dp[i][j]=\max_{0\leqslant k \leqslant j/c}(dp[i-1][j-kc]+kw)$

### 复杂度优化

滚动数组

## 例题

### 最长公共子序列 LCS

状态表示: `dp[i][j]`表示 $A$ 的前 $i$ 个字符与 $B$ 的前 $j$ 个字符的 LCS 长度

状态转移: $dp[i][j]=\max(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]+(A[i]==B[j]))$

### 最长上升子序列 LIS

#### 解法一

给自己排序后与自己求一个 LCS

#### 解法二

状态表示: `dp[i]` 是以 `S[i]` 为结尾的 LIS 长度

状态转移: $\displaystyle dp[i] = \max_{j<i,S[j]<S[i]}(dp[j]+1)$

**优化时间:** 二分查找

# day 05: 数据结构

>difficulty: ⭐⭐⭐⭐(by wzk)