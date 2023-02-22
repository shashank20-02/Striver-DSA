#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n] = {0};

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (arr[i] != arr[j])
        {
            i++;
            arr[i] = arr[j];
        }
    }

    for (int k = 0; k <= i; k++)
        cout << arr[k] << endl;

    cout << i + 1 << endl;
    return 0;
}