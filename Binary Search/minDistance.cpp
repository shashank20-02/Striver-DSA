#include <bits\stdc++.h>
using namespace std;

bool result(vector<int> &arr, int k, double mid)
{
    int stations = 0, pos = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if ((arr[i] - pos) > mid)
        {
            stations += floor((arr[i] - pos) / mid);
            cout << stations << endl;
        }
        pos = arr[i];
    }
    return (stations <= k);
}
double findSmallestMaxDist(vector<int> &arr, int k)
{
    double eps = 1e-6;
    double lo = arr[0], hi = arr[arr.size() - 1], mid, ans;
    while (hi - lo > eps)
    {
        mid = ((lo + hi) / 2.0);
        cout << mid << endl;
        if (result(arr, k, mid))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << setprecision(2) << findSmallestMaxDist(nums, k) << endl;
    return 0;
}

// 3 6 12 19 33 44 67 72 89 95