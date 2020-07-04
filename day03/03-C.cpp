#include <algorithm>
#include <iostream>
using namespace std;

const int INF = 1e9;
const int mxn = 10;
int T, k, arr[mxn][mxn];

int sum_2x2(int pos_x, int pos_y)
{
    return arr[pos_x][pos_y] + arr[pos_x + 1][pos_y] + arr[pos_x][pos_y + 1] + arr[pos_x + 1][pos_y + 1];
}

void rotate(int pos_x, int pos_y, int direction)
{
    int tmp = arr[pos_x][pos_y];

    // counter-clockwise
    if (direction == 1)
    {
        arr[pos_x][pos_y] = arr[pos_x][pos_y + 1];
        arr[pos_x][pos_y + 1] = arr[pos_x + 1][pos_y + 1];
        arr[pos_x + 1][pos_y + 1] = arr[pos_x + 1][pos_y];
        arr[pos_x + 1][pos_y] = tmp;
    }
    // clockwise
    else
    {
        arr[pos_x][pos_y] = arr[pos_x + 1][pos_y];
        arr[pos_x + 1][pos_y] = arr[pos_x + 1][pos_y + 1];
        arr[pos_x + 1][pos_y + 1] = arr[pos_x][pos_y + 1];
        arr[pos_x][pos_y + 1] = tmp;
    }
}

int DFS(int cur)
{
    int score;

    // end of recursion (final-defensive)
    if (cur == 2 * k)
    {
        score = INF;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                // defensive
                score = min(score, sum_2x2(i, j));
            }
        }
        return score;
    }

    // offensive
    if (cur & 1)
    {
        score = -INF;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                rotate(i, j, 1);
                score = max(score, DFS(cur + 1) + sum_2x2(i, j));
                rotate(i, j, -1);
            }
        }
        return score;
    }
    // defensive
    else
    {
        score = INF;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                rotate(i, j, 1);
                score = min(score, DFS(cur + 1) + sum_2x2(i, j));
                rotate(i, j, -1);
            }
        }
        return score;
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
    cin >> T;
    while (T--)
    {
        cin >> k;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cin >> arr[i][j];
            }
        }
        cout << DFS(1) << "\n";
    }
    return 0;
}
