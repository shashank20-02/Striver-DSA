#include <bits/stdc++.h>
using namespace std;

void recursiveInsertionSort(vector<int> &arr, int n, int i)
{
    if (i == n - 1)
        return;

    int j = i;
    while (j >= 0 && arr[j] > arr[j + 1])
    {
        swap(arr[j], arr[j + 1]);
        j--;
    }

    recursiveInsertionSort(arr, n, i + 1);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    recursiveInsertionSort(arr, n, 0);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}