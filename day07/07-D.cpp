#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;

const int mxn = 5e5;
int n, phi[mxn];
LL ans;
vector<int> ps;

void Euler(int rge)
{
    phi[1] = 1;
    for (int i = 2; i <= rge; i++)
    {
        if (phi[i] == 0)
            phi[i] = i - 1, ps.push_back(i);
        for (int j = 0; j < ps.size() && ps[j] <= rge / i; j++)
            if (i % ps[j])
                phi[i * ps[j]] = phi[i] * (ps[j] - 1);
            else
            {
                phi[i * ps[j]] = phi[i] * ps[j];
                break;
            }
    }
}

// #define LOCAL

int main()
{
#if defined(LOCAL)
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif // LOCAL
    cin >> n;
    Euler(n);
    for (int i = 1; i <= n; i++)
    {
        ans += phi[i];
    }
    ans *= 6;
    cout << ans << endl;
}
