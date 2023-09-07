#include <bits\stdc++.h>
#define ll long long int
using namespace std;

bool ispal(int i, int j, string &str)
{
    while (i < j)
    {
        if (str[i] != str[j])
            return false;
        i++;
        j--;
    }
    return true;
}

void generate(string &str, int ind, vector<string> &ds, vector<vector<string>> &ans)
{
    if (ind == str.length())
    {
        ans.push_back(ds);
        return;
    }

    for (int i = ind; i < str.length(); i++)
    {
        if (ispal(ind, i, str))
        {
            ds.push_back(str.substr(ind, (i - ind + 1)));
            generate(str, i + 1, ds, ans);
            ds.pop_back();
        }
    }
}

void solve(int testCase)
{
    cout << "For Case #" << testCase << endl;
    string str;
    cin >> str;
    vector<vector<string>> ans;
    vector<string> ds;
    generate(str, 0, ds, ans);
    for (auto itr : ans)
    {
        for (auto it : itr)
            cout << it << " ";
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
