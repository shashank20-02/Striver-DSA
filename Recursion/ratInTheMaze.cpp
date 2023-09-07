#include <bits\stdc++.h>
#define ll long long int
using namespace std;

void generate(int i, int j, int n, vector<vector<int>> &m, vector<vector<int>> &mat, string &ds, vector<string> &ans)
{
    if (i == n - 1 && j == n - 1 && m[i][j] == 1)
    {
        ans.push_back(ds);
        return;
    }
    if (i >= n || i < 0 || j >= n || j < 0)
        return;
    if (m[i][j] == 1 && mat[i][j] == 0)
    {
        mat[i][j] = 1;
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        char cz[] = {'D', 'U', 'R', 'L'};
        for (int k = 0; k < 4; k++)
        {
            ds.push_back(cz[k]);
            generate(i + dx[k], j + dy[k], n, m, mat, ds, ans);
            ds.pop_back();
        }
        mat[i][j] = 0;
    }
}

void solve(int testCase)
{
    cout << "For Case #" << testCase << endl;
    int n;
    cin >> n;
    vector<vector<int>> m(n, vector<int>(n, 0)), mat(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> m[i][j];
        }
    }
    vector<string> ans;
    string ds;
    generate(0, 0, n, m, mat, ds, ans);
    for (auto itr : ans)
        cout << itr << endl;
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
