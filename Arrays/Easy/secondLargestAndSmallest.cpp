#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, firstMax = INT_MIN, firstMin = INT_MAX, secondMax = -999, secondMin = 999;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        firstMax = max(arr[i], firstMax);
        firstMin = min(arr[i], firstMin);
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < firstMax && arr[i] > firstMin)
        {
            secondMax = max(secondMax, arr[i]);
            secondMin = min(secondMin, arr[i]);
        }
    }
    if (secondMax == -999)
    {
        secondMax = -1;
    }
    if (secondMin == 999)
        secondMin = -1;

    cout << secondMax << " " << secondMin << " " << endl;
    return 0;
}