// source: https://www.cnblogs.com/MisakaMKT/p/11626929.html

#include <cstring>
#include <iostream>
using namespace std;
typedef long long LL;

const int mxn_k = 12;
int T, k, bad, m[mxn_k], a[mxn_k];

LL exgcd(LL a, LL b, LL &x, LL &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    LL d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}

LL exChina()
{
    LL M = m[0], A = a[0];
    for (LL i = 1, d, x, y; i < k; i++)
    {
        d = exgcd(M, m[i], x, y);
        if ((A - a[i]) % d)
            return -1;
        x = x * (A - a[i]) / d % m[i];
        A -= x * M;
        M = M / d * m[i];
        A %= M;
    }
    return (A % M + M) % M;
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
        cin >> k >> bad;
        memset(m, 0, sizeof(int));
        memset(a, 0, sizeof(int));
        for (int i = 0; i < k; i++)
        {
            cin >> m[i];
            a[i] = m[i] - bad;
        }
        cout << exChina() << "\n";
    }
    return 0;
}
