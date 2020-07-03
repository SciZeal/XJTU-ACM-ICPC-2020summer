#include <iostream>
#include <map>
using namespace std;

int A[20];
map<int, int> mapA;

// #define LOCAL

int main()
{
#if defined(LOCAL)
    freopen("../../data.in", "r", stdin);
    freopen("../../data.out", "w", stdout);
#endif // LOCAL
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    int sum, tot = 1 << (n / 2);
    for (int j = 0; j < tot; j++)
    {
        sum = 0;
        for (int i = 0; i < n / 2; i++)
        {
            if ((j >> i) & 1)
            {
                sum += A[i];
            }
        }
        mapA[sum]++;
    }

    long long ans = -1; // non-empty set

    tot = 1 << (n - n / 2);
    for (int j = 0; j < tot; j++)
    {
        sum = 0;
        for (int i = 0; i < n - n / 2; i++)
        {
            if ((j >> i) & 1)
            {
                sum += A[i + n / 2];
            }
        }
        ans += mapA[-sum];
    }

    cout << ans << endl;
    return 0;
}
