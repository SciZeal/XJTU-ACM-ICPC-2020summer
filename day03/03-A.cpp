#include <iostream>
#include <unordered_set>
using namespace std;

int arr[2020000];
long long ans;
unordered_set<int> prime;

bool is_prime(int num)
{
    if (prime.count(num))
    {
        ans++;
        return true;
    }
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    ans++;
    prime.insert(num);
    return true;
}

// #define LOCAL

int main()
{
#if defined(LOCAL)
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif // LOCAL
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int sum, tot = (1 << n) - 1;
    for (int i = 1; i <= tot; i++)
    {
        sum = 0;
        for (int j = 0; j < n; j++)
        {
            if ((i >> j) & 1)
            {
                sum += arr[j];
            }
        }
        is_prime(sum);
    }

    cout << ans << endl
         << prime.size() << endl;
    return 0;
}
