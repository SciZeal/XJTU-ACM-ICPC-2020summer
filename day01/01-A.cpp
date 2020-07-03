// #define LOCAL
#include <iostream>
using namespace std;
int main()
{
#if defined(LOCAL)
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif // LOCAL
    int a, b;
    cin >> a >> b;
    int sum = a + b;
    // cout << sum << endl;
    if ((a > 0 && b > 0 && sum <= 0) || (a < 0 && b < 0 && sum >= 0))
    {
        cout << "overflow" << endl;
    }
    else
    {
        cout << "ok" << endl;
    }
    return 0;
}
