#include <algorithm>
#include <iostream>
using namespace std;

int n;
pair<int, int> pr[1010000];

bool cmpfunc(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int left_min(int point)
{
    for (int i = 0; i < n; i++)
    {
        if (pr[i].first > point)
        {
            return i;
        }
    }
    return -1;
}

// #define LOCAL

int main()
{
#if defined(LOCAL)
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif // LOCAL

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> pr[i].first >> pr[i].second;
    }
    sort(pr, pr + n, cmpfunc);
    int left_point, ans = 0, point = pr[0].second;
    while (true)
    {
        left_point = left_min(point);
        if (left_point)
        {
            ans++;
            point = pr[left_point].second;
        }
        else
        {
            break;
        }
    }
    cout << ans << endl;

    return 0;
}
