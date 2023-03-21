#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Spiral Print" << endl;
    int top = 0, bottom = n - 1, left = 0, right = m - 1;
    while (top <= bottom && left <= right)
    {
        for (int col = left; col <= right; col++)
            cout << matrix[top][col] << " ";
        top++;
        for (int row = top; row <= bottom; row++)
            cout << matrix[row][right] << " ";
        right--;
        for (int col = right; col >= left; col--)
            cout << matrix[bottom][col] << " ";
        bottom--;
        for (int row = bottom; row >= top; row--)
            cout << matrix[row][left] << " ";
        left++;
    }
    cout << endl;
    return 0;
}