#include <bits\stdc++.h>
using namespace std;

int countSubarrays(vector<int> &arr, int k)
{
    unordered_map<int, int> mp;
    int sum = 0, ans = 0;
    mp[0]++;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (mp.find(sum - k) != mp.end())
            ans += mp[sum - k];
        mp[sum]++;
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

    cout << countSubarrays(arr, k) << endl;
    return 0;
}