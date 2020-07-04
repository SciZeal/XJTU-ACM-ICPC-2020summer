#include <iostream>
using namespace std;
typedef long long LL;

const int HUGE = 998244353;
const int mxn = 200200;

int n, k, arr[mxn], zero[mxn], ans;

int rev_unit(int num)
{
    int ans = 1, HUGE_2 = HUGE - 2;
    while (HUGE_2)
    {
        if (HUGE_2 & 1)
        {
            ans = 1LL * ans * num % HUGE;
        }
        num = 1LL * num * num % HUGE;
        HUGE_2 >>= 1;
    }
    return ans;
}

int may_ans(int begin, int end)
{
    if (end < begin + k)
    {
        return 0;
    }

    int frac_ans = 0, init_end = begin + k;
    LL product = 1;
    for (int i = begin; i < init_end; i++)
    {
        product *= arr[i];
        product %= HUGE;
    }
    frac_ans = product;
    for (int i = init_end; i < end; i++)
    {
        product *= rev_unit(arr[i - k]);
        product %= HUGE;
        product *= arr[i];
        product %= HUGE;
        if (product > frac_ans)
        {
            frac_ans = product;
        }
    }

    return frac_ans;
}

// #define LOCAL

int main()
{
#if defined(LOCAL)
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif // LOCAL
    cin >> n >> k;
    int cnt = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        if (!arr[i])
        {
            zero[cnt++] = i;
        }
    }
    zero[cnt] = n + 1;

    for (int i = 0; i < cnt; i++)
    {
        int begin = zero[i] + 1, end = zero[i + 1];
        int tmp = may_ans(begin, end);
        if (tmp > ans)
        {
            ans = tmp;
        }
    }

    cout << ans << endl;
}
