#include <iostream>
using namespace std;
typedef long long LL;

LL X, Y, A, B, b;

void exgcd(LL a, LL b, LL &d, LL &x, LL &y)
{
    if (b == 0)
    {
        d = a, x = 1, y = 0;
    }
    else
    {
        exgcd(b, a % b, d, y, x);
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

    LL d, x, y;
    x = y = 1;
    exgcd(b, a, d, x, y);
    if (c % d)
    {
        cout << -1 << endl;
        return 0;
    }
    else
    {
        x *= (c / d);
        y *= (c / d);
        y = (y % (b / d) + b / d) % (b / d);
        cout << y << endl;
    }
    return 0;
}
