#include <bits\stdc++.h>
using namespace std;

void Subsequences(vector<int> arr, int index, vector<int> &ans)
{
    if (index >= arr.size())
    {
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
        return;
    }
    ans.push_back(arr[index]);
    Subsequences(arr, index + 1, ans);
    ans.pop_back();
    Subsequences(arr, index + 1, ans);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> ans;
    Subsequences(arr, 0, ans);
    return 0;
}