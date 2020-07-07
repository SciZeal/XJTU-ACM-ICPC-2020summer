#include <iostream>
using namespace std;
typedef long long LL;

const int mxn = 100;
int T, num, m[mxn], a[mxn];

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
    for (LL i = 1, d, x, y; i < num; i++)
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
        cin >> num;
        for (int i = 0; i < num; i++)
        {
            cin >> m[i] >> a[i];
        }
        cout << exChina() << "\n";
    }
    return 0;
}
