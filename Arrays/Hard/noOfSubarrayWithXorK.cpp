#include <bits\stdc++.h>
using namespace std;

int approach2(vector<int> &arr, int k)
{
    map<int, int> freq;
    int xxor = 0, cnt = 0;
    for (auto it : arr)
    {
        xxor = it ^ xxor;
        if (xxor == k)
            cnt++;
        if (freq.find(xxor ^ k) != freq.end())
            cnt += freq[xxor ^ k];
        freq[xxor]++;
    }
    return cnt;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int currentXor = 0;
            for (int k = i; k <= j; k++)
                currentXor = currentXor ^ arr[k];

            if (currentXor == k)
                num++;
        }
    }
    cout << num << endl;
    return 0;
}