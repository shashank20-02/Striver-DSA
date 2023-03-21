#include <bits/stdc++.h>
using namespace std;

int main()
{
    int nRows;
    cin >> nRows;
    vector<vector<int>> ans;
    for (int i = 0; i < nRows; i++)
    {
        vector<int> temp;
        temp[0] = 1;
        temp[i] = 1;
        for (int j = 1; j < i; j++)
        {
            temp[j] = ans[i - 1][j] + ans[i - 1][j - 1];
        }
        ans.push_back(temp);
    }

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}