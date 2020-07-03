#include <algorithm>
#include <iostream>
using namespace std;

int K, a[4][4];

void rotate(int i, int j, int type)
{
    int tmp;
    if (type == -1)
    {
        tmp = a[i][j];
        a[i][j] = a[i + 1][j];
        a[i + 1][j] = a[i + 1][j + 1];
        a[i + 1][j + 1] = a[i][j + 1];
        a[i][j + 1] = tmp;
    }
    else
    {
        tmp = a[i][j];
        a[i][j] = a[i][j + 1];
        a[i][j + 1] = a[i + 1][j + 1];
        a[i + 1][j + 1] = a[i + 1][j];
        a[i + 1][j] = tmp;
    }
}

int DFS(int p, int k)
{
    if (k == 2 * K)
    {
        int Min = 0x3f3f3f3f;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int res = a[i][j] + a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1];
                Min = min(Min, res);
            }
        }
        return Min;
    }
    int Min = 0x3f3f3f3f, Max = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int res = a[i][j] + a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1];
            rotate(i, j, 1);
            if (p == 0)
            {
                Max = max(Max, DFS(1, k + 1) + res);
            }
            else
            {
                Min = min(Min, DFS(0, k + 1) + res);
            }
            rotate(i, j, -1);
        }
    }
    return (p ? Min : Max);
}

#define LOCAL

int main()
{
#if defined(LOCAL)
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif // LOCAL

    int t;
    cin >> t;
    while (t--)
    {
        cin >> K;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cin >> a[i][j];
            }
        }
        cout << DFS(0, 1) << endl;
    }
    return 0;
}
