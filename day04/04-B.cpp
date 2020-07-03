#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;

const int HUGE = 919260817;
const int mxn = 100100;
int n, m, k;
LL trans[100];
vector<LL> dp[mxn];

// #define LOCAL

int main()
{
#if defined(LOCAL)
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif // LOCAL
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> trans[i];
    }
    for (int i = 0, M = m + 100; i <= n; i++)
    {
        dp[i].resize(M);
    }
    dp[0][0] = 1;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int car = 0; car < k; car++)
            {
                if ((i - trans[car]) >= 0)
                {
                    dp[i][j] += dp[i - trans[car]][j];
                    dp[i][j] %= HUGE;
                }
                if ((j - trans[car]) >= 0)
                {
                    dp[i][j] += dp[i][j - trans[car]];
                    dp[i][j] %= HUGE;
                }
            }
        }
    }
    cout << dp[n][m] % HUGE << endl;
    return 0;
}
