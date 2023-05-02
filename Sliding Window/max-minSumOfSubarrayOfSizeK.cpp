#include <bits\stdc++.h>
using namespace std;

int MaxSubarraySum(vector<int> arr, int k)
{
    int sum = 0, ans = INT_MIN;
    for (int i = 0; i < k; i++)
        sum += arr[i];
    ans = max(sum, ans);
    for (int i = k; i < arr.size(); i++)
    {
        sum = sum + arr[i] - arr[i - k];
        ans = max(sum, ans);
    }
    return ans;
}

int MinSubarraySum(vector<int> arr, int k)
{
    int sum = 0, ans = INT_MAX;
    for (int i = 0; i < k; i++)
        sum += arr[i];
    ans = min(sum, ans);
    for (int i = k; i < arr.size(); i++)
    {
        sum = sum + arr[i] - arr[i - k];
        ans = min(ans, sum);
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
    cout << MaxSubarraySum(arr, k) << endl;
    cout << MinSubarraySum(arr, k) << endl;
    return 0;
}