#include <bits\stdc++.h>
using namespace std;

int maxConsecutive1s(vector<int> &arr, int k)
{
    vector<int> freq(2, 0);
    int s = 0, e = 0, ans = 0;
    while (e < arr.size())
    {
        freq[arr[e]]++;
        if (freq[0] <= k)
        {
            ans = max(ans, e - s + 1);
        }
        else
        {
            while (freq[0] > k)
            {
                freq[arr[s]]--;
                s++;
            }
        }
        e++;
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

    cout << maxConsecutive1s(arr, k) << endl;
    return 0;
}

// 0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1