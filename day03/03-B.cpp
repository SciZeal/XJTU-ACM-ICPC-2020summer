#include <iostream>
using namespace std;

int n, tot, ans[15], former = -3;
bool dead[10][50];

void queen(int cur)
{
    if (cur == n)
    {
        tot++;

        // output `former` times
        if (former)
        {
            former++;
            for (int i = 0; i < n; i++)
            {
                cout << ans[i] + 1 << " ";
            }
            cout << endl;
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            // dead[0][i] <=> line i
            // dead[1][i] <=> \ diagonal i
            // dead[2][i] <=> / diagonal i
            if (!dead[0][i] && !dead[1][i + cur] && !dead[2][-i + (n + cur)])
            {
                if (former)
                {
                    ans[cur] = i;
                }
                dead[0][i] = dead[1][i + cur] = dead[2][-i + (n + cur)] = true;
                queen(cur + 1);

                // back-tracking
                dead[0][i] = dead[1][i + cur] = dead[2][-i + (n + cur)] = false;
            }
        }
    }
}

// #define LOCAL

int main()
{
#if defined(LOCAL)
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif // LOCAL
    cin >> n;
    queen(0);
    cout << tot << endl;
    return 0;
}
