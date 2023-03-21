#include <bits/stdc++.h>
using namespace std;

// Approach - Linear on rows and binary on columns T.c - O(N * log(M)) S.C - O(1)
// bool binarySearch(vector<int> &arr, int m, int x)
// {
//     long long int mid, lo = 0, hi = m - 1;
//     while (lo <= hi)
//     {
//         mid = (lo + hi) / 2;
//         if (arr[mid] == x)
//         {
//             return true;
//         }
//         else if (arr[mid] > x)
//         {
//             hi = mid - 1;
//         }
//         else
//         {
//             lo = mid + 1;
//         }
//     }
//     return false;
// }
// int matSearch(vector<vector<int>> &arr, int n, int m, int x)
// {
//     bool flag = false;
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i][0] <= x && arr[i][m - 1] >= x)
//         {
//             flag = binarySearch(arr[i], m, x);
//             if (flag == 1)
//                 break;
//         }
//     }
//     return flag;
// }
// T.c - O(n + m) S.C - O(1)
int matSearch(vector<vector<int>> &arr, int n, int m, int x)
{
    int i = 0, j = m - 1;
    while (i < n && j >= 0)
    {
        if (arr[i][j] == x)
            return true;
        else if (arr[i][j] > x)
            j--;
        else
            i++;
    }
    return false;
}

int main()
{
    int n, m, x, value;
    vector<vector<int>> arr;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < m; j++)
        {
            cin >> value;
            temp.push_back(value);
        }
        arr.push_back(temp);
    }
    cin >> x;
    cout << matSearch(arr, n, m, x) << endl;
    return 0;
}