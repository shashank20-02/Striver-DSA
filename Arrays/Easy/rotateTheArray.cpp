#include <bits/stdc++.h>
using namespace std;

void reverseArray(int *arr, int lo, int hi)
{
    while (lo < hi)
    {
        swap(arr[lo], arr[hi]);
        lo++;
        hi--;
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
    int n, k, arr[1000] = {0};
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // TC - O(N * K) SC - O(1)
    // k = k % n;
    // while (k--)
    // {
    //     int temp = arr[0];
    //     for (int i = 1; i < n; i++)
    //     {
    //         arr[i - 1] = arr[i];
    //     }
    //     arr[n - 1] = temp;
    // }
    // arr - [1, 2, 3, 4, 5, 6, 7] - [0 , 1 , 2 ,3 ,4 ,5 ,6]
    k = k % n;
    reverseArray(arr, 0, k - 1);
    reverseArray(arr, k, n - 1);
    reverseArray(arr, 0, n - 1);
    printArray(arr, 0, n - 1);
    return 0;
}