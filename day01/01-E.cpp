#include <map>
#include <stdio.h>
using namespace std;

int arr[202000];
map<int, int> mp;

// #define LOCAL

int main()
{
#if defined(LOCAL)
    freopen("../../data.in", "r", stdin);
    freopen("../../data.out", "w", stdout);
#endif // LOCAL

    int n, q, k, v, sum = 0;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < q; i++)
    {
        // sum
        scanf("%d%d", &k, &v);
        if ((n / k) & 1)
        {
            sum ^= v;
        }
        printf("%d\n", sum);

        mp[k] ^= v;
    }

    // final arr[n]
    for (auto p : mp)
    {
        for (int i = p.first - 1; i < n; i += p.first)
        {
            arr[i] ^= p.second;
        }
    }

    // output arr[n]
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
