// source: https://blog.csdn.net/sodacoco/article/details/81461864

#include <iostream>
using namespace std;
typedef long long LL;

LL X, Y, A, B, b;

void exgcd(LL a, LL b, LL &gcd_ab, LL &x, LL &y)
{
    if (b == 0)
    {
        gcd_ab = a, x = 1, y = 0;
    }
    else
    {
        exgcd(b, a % b, gcd_ab, y, x);
        y -= x * (a / b);
    }
}

// #define LOCAL

int main()
{
#if defined(LOCAL)
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif // LOCAL

    cin >> X >> A >> Y >> B >> b;

    if (A < B)
    {
        swap(A, B);
        swap(X, Y);
    }
    else if (A == B)
    {
        if (X % b == Y % b)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << -1 << endl;
        }
        return 0;
    }

    LL a = A - B, c = (Y - X) % b;

    LL gcd, x, y;
    x = y = 1;
    exgcd(b, a, gcd, x, y);
    if (c % gcd)
    {
        cout << -1 << endl;
        return 0;
    }
    else
    {
        x *= (c / gcd);
        y *= (c / gcd);
        y = (y % (b / gcd) + b / gcd) % (b / gcd);
        cout << y << endl;
    }
    return 0;
}
