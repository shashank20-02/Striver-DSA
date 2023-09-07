#include <bits\stdc++.h>
using namespace std;

void generate(int ind, int n, vector<int> &ans)
{
    if (ind == n)
    {
        for (auto itr : ans)
            cout << itr << " ";
        cout << endl;
        return;
    }
    ans[ind] = 1;
    generate(ind + 1, n, ans);
    ans[ind] = 0;
    generate(ind + 1, n, ans);
}

int main()
{
    int n;
    cin >> n;
    vector<int> ans(n, 0);
    generate(0, n, ans);
    return 0;
}