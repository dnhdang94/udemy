#include <stdio.h>
#include <vector>

using namespace std;

#define MAX_ELEM    100000

int A[MAX_ELEM];
int N;

int query(int q);

int query(int q)
{
    int idx = -1;
    int left, right, mid;

    left = 0;
    right = N - 1;

    while (left <= right)
    {
        mid = (left + right) / 2;
        if (A[mid] == q)
        {
            idx = mid;
            right = mid - 1;
        }
        else if (A[mid] < q)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return idx;
}

int main()
{
    int q, t;
    vector<int> v;

    scanf("%d %d", &N, &q);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < q; i++)
    {
        scanf("%d", &t);
        printf("%d\n", query(t));
    }

    return 0;
}
