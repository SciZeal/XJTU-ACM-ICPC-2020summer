#include <algorithm>
#include <iostream>
using namespace std;

int arr[101000];

// #define LOCAL

int main()
{
#if defined(LOCAL)
    freopen("../../data.in", "r", stdin);
    freopen("../../data.out", "w", stdout);
#endif // LOCAL

    int n, money;
    cin >> n >> money;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    int ans;
    for (ans = 0; ans < n && money >= 0; ans++)
    {
        money -= arr[ans];
    }
    cout << ans - 1 << endl;
    return 0;
}
