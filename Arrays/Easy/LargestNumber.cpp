#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, maxNumber = INT_MIN;
    cin >> n;
    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++)
    {
        maxNumber = max(arr[i], maxNumber);
    }
    cout << maxNumber << endl;
    return 0;
}