#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5;
int a[maxn];

int odd[maxn];
int even[maxn];

// #define LOCAL

int main()
{
#if defined(LOCAL)
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif // LOCAL
    int n, cnt_odd = 0, cnt_even = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] & 1)
        {
            odd[cnt_odd++] = a[i];
        }
        else
        {
            even[cnt_even++] = a[i];
        }
    }
    sort(odd, odd + cnt_odd);
    sort(even, even + cnt_even);
    int cnt_a = 0, cnt_b = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] & 1)
        {
            cout << odd[cnt_a++] << " ";
        }
        else
        {
            cout << even[cnt_b++] << " ";
        }
    }
    return 0;
}
