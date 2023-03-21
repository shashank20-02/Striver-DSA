#include <bits\stdc++.h>
using namespace std;

bool result(long long int mid, int threshold, vector<int> &nums)
{
    int sum = 0;
    for (auto it : nums)
    {
        sum += ((it / mid) + (it % mid != 0));
        cout << sum << endl;
    }
    if (sum <= threshold)
        return true;
    else
        return false;
}
int smallestDivisor(vector<int> &nums, int threshold)
{
    vector<int>::iterator maxi = max_element(nums.begin(), nums.end());
    long long int lo = 1, hi = nums[distance(nums.begin(), maxi)], mid;
    while (hi - lo > 1)
    {
        mid = (lo + hi) / 2;
        if (result(mid, threshold, nums))
        {
            hi = mid;
        }
        else
            lo = mid + 1;
    }

    return (result(lo, threshold, nums)) ? lo : hi;
}

int main()
{
    int n, threshold;
    cin >> n >> threshold;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << smallestDivisor(nums, threshold) << endl;
    return 0;
}