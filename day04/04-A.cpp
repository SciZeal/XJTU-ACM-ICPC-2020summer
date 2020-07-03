#include <algorithm>
#include <iostream>
using namespace std;

const int mxn = 1010;
const int infty = 999999999;

int xp, yp, n, arr[mxn][mxn], way[mxn][mxn];
long long ans = -infty, dp[mxn][mxn];

// #define LOCAL

int main()
{
#if defined(LOCAL)
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif // LOCAL
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + arr[i][j];
            way[i][j] = dp[i - 1][j] == max(dp[i - 1][j], dp[i - 1][j - 1]) ? 0 : -1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (ans < dp[n][i])
        {
            ans = dp[n][i];
            yp = i;
        }
    }
    cout << ans << endl;

    string plan;
    while (n > 1)
    {                                   // 如果 xp==1，说明已经回到了初始位置，不需要再倒推了
        plan += way[n][yp] ? 'R' : 'L'; // 看看当前位置是怎样由上一层转移来的
        yp += way[n][yp], n--;          // 回到上一层的位置
    }
    reverse(plan.begin(), plan.end()); // 由于是倒推的，所以要翻转字符串得到正着走的路线
    cout << plan << endl;

    return 0;
}
