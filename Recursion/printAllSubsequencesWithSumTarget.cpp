#include <bits/stdc++.h>
using namespace std;

void generate(int ind, int n, int sum, int target, vector<int> &arr, vector<int> &ans)
{
    if (sum == target)
    {
        for (auto itr : ans)
            cout << itr << " ";
        cout << endl;
        return;
    }
    if (ind == n)
        return;
    ans.push_back(arr[ind]);
    generate(ind + 1, n, sum + arr[ind], target, arr, ans);
    ans.pop_back();
    generate(ind + 1, n, sum, target, arr, ans);
}
int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> arr(n, 0), ans;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    generate(0, n, 0, target, arr, ans);
    return 0;
}