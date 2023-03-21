#include <bits/stdc++.h>
using namespace std;

void findUnion(vector<int> &arr1, vector<int> &arr2, int n, int m)
{
    vector<int> ans;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (arr1[i] <= arr2[j])
        {
            if (ans.size() == 0 || ans.back() != arr1[i])
                ans.push_back(arr1[i]);
            i++;
        }
        else
        {
            if (ans.size() == 0 || ans.back() != arr2[j])
                ans.push_back(arr2[j]);
            j++;
        }
    }

    while (i < n)
    {
        if (ans.back() != arr1[i])
            ans.push_back(arr1[i]);
        i++;
    }
    while (j < m)
    {
        if (ans.back() != arr2[j])
            ans.push_back(arr2[j]);
        j++;
    }
    for (int i = 0; i < ans.size(); i++)
        cin >> ans[i];
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr1(n, 0), arr2(m, 0);

    for (int i = 0; i < n; i++)
        cin >> arr1[i];
    for (int i = 0; i < m; i++)
        cin >> arr2[i];

    findUnion(arr1, arr2, n, m);

    return 0;
}