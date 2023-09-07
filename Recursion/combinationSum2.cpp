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

    for (int i = ind; i < arr.size(); i++)
    {
        if (target < arr[i])
            break;
        if (i == ind || (i > ind && arr[i] != arr[i - 1]))
        {
            ans.push_back(arr[i]);
            generate(i + 1, arr, ans, target - arr[i]);
            ans.pop_back();
        }
    }
}

void solve(int testCase)
{
    cout << "For Case #" << testCase << endl;
    ll n, target;
    cin >> n >> target;
    vector<int> arr(n, 0), ans;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
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
