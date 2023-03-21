#include <bits\stdc++.h>
using namespace std;

int solve(vector<int> &nums, int n)
{
    int sum = 0, maxi = -1;
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        if (sum == 0)
            maxi = i + 1;
        else
        {

            if (map.find(sum) != map.end())
            {
                maxi = max(maxi, i - map[sum]);
            }
            else
            {
                map[sum] = i;
            }
        }
    }
    return maxi;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n, 0);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int maxi = solve(nums, n);
    cout << maxi << endl;

    return 0;
}