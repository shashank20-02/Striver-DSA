#include <bits/stdc++.h>
using namespace std;

void recursiveBubbleSort(vector<int> &arr, int n, int i)
{
    if (i == n - 1)
        return;

    for (int j = 0; j < n - i - 1; j++)
    {
        if (arr[j] > arr[j + 1])
            swap(arr[j], arr[j + 1]);
    }
    recursiveBubbleSort(arr, n, i + 1);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    recursiveBubbleSort(arr, n, 0);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}