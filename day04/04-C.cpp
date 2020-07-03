#include <algorithm>
#include <iostream>
using namespace std;

const int mxn = 100100;
const int INF = 1e9;

int n, arr[mxn];
int inserting_up_arr[mxn], len;

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
        cin >> arr[i];
    }

    inserting_up_arr[0] = -INF;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] >= inserting_up_arr[len])
        {
            len++;
            inserting_up_arr[len] = arr[i];
        }
        else
        {
            int index = lower_bound(inserting_up_arr + 1, inserting_up_arr + len + 1, arr[i]) - inserting_up_arr;
            inserting_up_arr[index] = arr[i];
        }
    }
    cout << len << endl;
}
