#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int sum = 0, ans = arr[0], s = arr[0], e = arr[0];
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        ans = max(sum, ans);
        if (sum < 0)
            sum = 0;
    }

    cout << ans << endl;
    return 0;
}

// -2 1 -3 4 -1 2 1 -5 4