#include <bits/stdc++.h>
using namespace std;

int quickPartition(vector<int> &arr, int lo, int hi)
{
    int pivot = arr[lo];
    int i = lo, j = hi;
    while (i < j)
    {
        while (arr[i] <= pivot && i <= hi - 1)
            i++;
        while (arr[j] > pivot && j >= lo)
            j--;

        if (i < j)
            swap(arr[i], arr[j]);
    }

    swap(arr[lo], arr[j]);
    return j;
}

void quickSort(vector<int> &arr, int lo, int hi)
{
    if (lo < hi)
    {
        int index = quickPartition(arr, lo, hi);
        quickSort(arr, lo, index - 1);
        quickSort(arr, index + 1, hi);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
    return 0;
}