#include <bits\stdc++.h>
#define ll long long int
using namespace std;

void generate(int ind, vector<int> &arr, vector<int> &ans, int target)
{
    if (target == 0)
    {
        for (auto itr : ans)
            cout << itr << " ";
        cout << endl;
        return;
    }
    if (target < 0)
        return;
    if (ind == arr.size())
        return;

    ans.push_back(arr[ind]);
    generate(ind + 1, arr, ans, target - arr[ind]);
    ans.pop_back();
    generate(ind + 1, arr, ans, target);
}

void solve(int testCase)
{
    cout << "For Case #" << testCase << endl;
    ll n, target;
    cin >> n >> target;
    vector<int> arr(n, 0), ans;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    generate(0, arr, ans, target);
}
int main()
{
    ll t, c = 1;
    cin >> t;
    while (c <= t)
    {
        solve(c);
        c++;
    }
    return 0;
}
