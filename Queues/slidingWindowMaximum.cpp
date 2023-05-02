#include <bits\stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    deque<int> dq;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        if (!dq.empty() && i - k >= dq.front())
            dq.pop_front();

        while (!dq.empty() && nums[dq.back()] <= nums[i])
            dq.pop_back();
        dq.push_back(i);

        if (i >= k - 1)
            ans.push_back(nums[dq.front()]);
    }
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> ans = maxSlidingWindow(arr, k);
    for (auto it : ans)
        cout << it << " ";
    cout << endl;
    return 0;
}