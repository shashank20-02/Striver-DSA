#include <bits/stdc++.h>
using namespace std;

void moveZeroes(int *arr, int lo, int hi)
{
    int i = lo, j = lo + 1;
    while (i <= hi && j <= hi)
    {
        cout << arr[i] << " " << arr[j] << " " << endl;
        if (arr[i] == 0 && arr[j] != 0)
        {
            swap(arr[i], arr[j]);
            i++;
            j++;
        }
        else if (arr[i] == 0 && arr[j] == 0)
        {
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }
}

void printArray(int *arr, int lo, int hi)
{
    for (int i = lo; i <= hi; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n, arr[1000] = {0};
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    moveZeroes(arr, 0, n - 1);
    printArray(arr, 0, n - 1);

    return 0;
}