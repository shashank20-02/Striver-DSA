#include <bits/stdc++.h>
using namespace std;

bool result(vector<int> &nums, int k, int mid)
{
    long long int sum = nums[0], subarray = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if ((sum + nums[i]) > mid)
        {
            subarray++;
            sum = nums[i];
        }
        else
            sum += nums[i];
    }
    cout << subarray << endl;
    return (subarray == k);
}
int splitArray(vector<int> &nums, int k)
{
    if (nums.size() == k)
    {
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            ans = max(ans, nums[i]);
        }
        return ans;
    }
    int sum = 0, ans = nums[0];
    for (auto it : nums)
        sum += it;
    int lo = nums[0], hi = sum, mid;

    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        cout << mid << lo << hi << endl;
        if (result(nums, k, mid))
        {
            cout << ans << endl;
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

    cout << splitArray(nums, k) << endl;
    return 0;
}

// 2 3 1 2 4 3