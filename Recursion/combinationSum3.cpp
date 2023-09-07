#include <bits\stdc++.h>
#define ll long long int
using namespace std;

void generate(int ind, int start, int target, vector<int> &ds, vector<vector<int>> &ans)
{
    if (ds.size() == ind && target == 0)
    {
        ans.push_back(ds);
        return;
    }
    if (ds.size() == ind)
        return;
    for (int i = start; i <= 9; i++)
    {
        if (target < i)
            break;
        ds.push_back(i);
        generate(ind, i + 1, target - i, ds, ans);
        ds.pop_back();
    }
}

void solve(int testCase)
{
    cout << "For Case #" << testCase << endl;
    int n, k;
    cin >> k >> n;
    vector<vector<int>> ans;
    vector<int> ds;
    generate(k, 1, n, ds, ans);
    for (auto itr : ans)
    {
        for (auto it : itr)
        {
            cout << it << " ";
        }
        cout << endl;
    }
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
