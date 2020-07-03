#include <iostream>
using namespace std;

const int maxn = 1010000;

int arr[maxn], T[maxn];

long long cnt;

void merge_sort(int *A, int x, int y, int *T)
{
    if (y - x > 1)
    {
        int mid = x + (y - x) / 2;
        int p = x, q = mid, i = x;

        // recursion
        merge_sort(A, x, mid, T);
        merge_sort(A, mid, y, T);

        while (p < mid || q < y)
        {
            if (q >= y || (p < mid && A[p] <= A[q]))
            {
                T[i++] = A[p++];
            }
            else
            {
                T[i++] = A[q++];
                cnt += mid - p; // inverse pair
            }
        }
        for (int i = x; i < y; i++)
        {
            A[i] = T[i];
        }
    }
}

// #define LOCAL

int main()
{
#if defined(LOCAL)
    freopen("../../data.in", "r", stdin);
    freopen("../../data.out", "w", stdout);
#endif // LOCAL
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    merge_sort(arr, 0, n, T);
    cout << cnt << endl;

    return 0;
}
