#include <bits/stdc++.h>
using namespace std;

int *solved(vector<int> &nums, int n)
{
    vector<int> freq(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        freq[nums[i]]++;
    }
    int ans[2] = {0};
    for (int i = 1; i <= n; i++)
    {
        if (freq[i] == 0)
            ans[1] = i;
        else if (freq[i] == 2)
            ans[2] = i;
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int *ans = solved(nums, n);

    for (int i = 0; i < 2; i++)
    {
        cout << ans[i] << endl;
    }

    // vector<int> ans = solved(nums, n);
    // for (int i = 0; i < ans.size(); i++)
    //     cout << ans[i] << " ";
    // cout << endl;
    return 0;
}