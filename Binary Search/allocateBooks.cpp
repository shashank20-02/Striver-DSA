#include <bits\stdc++.h>
using namespace std;

bool isPossible(int arr[], int n, int m, int barrier)
{
    int allocated = 1, pages = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > barrier)
            return false;
        if (pages + arr[i] > barrier)
        {
            allocated++;
            pages = arr[i];
        }
        else
            pages += arr[i];
    }
    return (allocated <= m);
}

int findPages(int arr[], int n, int m)
{
    int index = *min_element(arr, arr + n);
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    int lo = index, hi = sum, mid, ans = -1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (isPossible(arr, n, m, mid))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int arr[n] = {0};
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << findPages(arr, n, m) << endl;
}