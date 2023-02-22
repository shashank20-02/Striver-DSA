#include <bits/stdc++.h>
using namespace std;

void reverseArr(int *arr, int lo, int hi)
{
    if (lo > hi)
        return;
    int temp = arr[lo];
    arr[lo] = arr[hi];
    arr[hi] = temp;
    reverseArr(arr, lo + 1, hi - 1);
}

int main()
{
    int n, arr[10] = {0};
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    reverseArr(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}