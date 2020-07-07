// luogu-P4720: https://www.luogu.com.cn/problem/P4720
// solution: https://blog.csdn.net/hqddm1253679098/article/details/82897638

#include <algorithm>
#include <iostream>
using namespace std;
typedef long long LL;

LL n, m, in_n, in_m;
int T, p;

/**
 * @author zxh
 */
LL exgcd(LL a, LL b, LL &x, LL &y)
{
    if (!b)
    {
        x = 1;
        y = 0;
        return a;
    }
    LL d = exgcd(b, a % b, y, x);
    y = y - a / b * x;
    return d;
}

/**
 * @author cyy
 */
LL quick_pow(LL a, LL b, LL mod)
{
    LL ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = ans * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

LL inv(LL a, LL p)
{
    LL x, y;
    exgcd(a, p, x, y);
    if (x + p > p)
        return x;
    return x + p;
}

LL crt(LL n, LL mod)
{
    return n * (p / mod) % p * inv(p / mod, mod) % p;
}

LL fac(LL n, LL p, LL k)
{ // k = p^x
    if (!n)
        return 1;
    LL ans = 1;
    for (int i = 2; i <= k; i++)
    {
        if (i % p)
            ans = ans * i % k;
    }
    ans = quick_pow(ans, n / k, k);
    for (int i = 2; i <= n % k; i++)
    {
        if (i % p)
            ans = ans * i % k;
    }
    return ans * fac(n / p, p, k) % k;
}

LL C(LL n, LL m, LL p, LL k)
{ // k = p^x
    if (n < m)
        return 0;
    LL a = fac(n, p, k), b = fac(m, p, k), c = fac(n - m, p, k);
    LL cnt = 0;
    for (LL i = p; i <= n; i *= p)
        cnt += n / i;
    for (LL i = p; i <= m; i *= p)
        cnt -= m / i;
    for (LL i = p; i <= n - m; i *= p)
        cnt -= (n - m) / i;
    return a * inv(b, k) % k * inv(c, k) % k * quick_pow(p, cnt, k) % k;
}

LL exlucas()
{
    LL t = p, ans = 0;
    for (LL i = 2; i * i <= t; i++)
    {
        if (t % i)
            continue;
        LL tmp = 1;
        while (t % i == 0)
        {
            tmp *= i;
            t /= i;
        }
        ans = (ans + crt(C(n, m, i, tmp), tmp)) % p;
    }
    if (t > 1)
        ans = (ans + crt(C(n, m, t, t), t)) % p;
    return ans % p;
}

// #define LOCAL

int main()
{
#if defined(LOCAL)
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif // LOCAL
    cin >> T;
    while (T--)
    {
        cin >> in_n >> in_m >> p;
        m = max(in_n, in_m);
        n = in_n + in_m;
        cout << exlucas() << endl;
    }
    return 0;
}
