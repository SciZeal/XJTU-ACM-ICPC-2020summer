#include <iostream>
using namespace std;

typedef long long LL;

int A, B, C;

int pow(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = 1LL * ans * a % C;
        }
        a = 1LL * a * a % C;
        b >>= 1;
    }
    return ans;
}

#define LOCAL

int main()
{
#if defined(LOCAL)
    freopen("../../data.in", "r", stdin);
    freopen("../../data.out", "w", stdout);
#endif // LOCAL
    cin >> A >> B >> C;
    cout << pow(A, B) << endl;
    return 0;
}
