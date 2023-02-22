#include <bits/stdc++.h>
using namespace std;

void Merge(vector<int> &arr, int lo, int mid, int hi)
{
    int left = lo;
    int right = mid + 1;

    vector<int> temp;

    while (left <= mid && right <= hi)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= hi)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = lo; i <= hi; i++)
    {
        arr[i] = temp[i - lo];
    }
}

void mergeSort(vector<int> &arr, int lo, int hi)
{
    if (lo < hi)
    {
        int mid = (lo + hi) / 2;
        mergeSort(arr, lo, mid);
        mergeSort(arr, mid + 1, hi);
        Merge(arr, lo, mid, hi);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}