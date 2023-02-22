#include <bits/stdc++.h>
using namespace std;

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

    k = k % n;
    int temp[k] = {0};
    for (int i = 0; i < k; i++)
        temp[i] = arr[i];

    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    int j = 0;
    for (int i = n - k; i < n; i++)
        arr[i] = temp[j++];
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}