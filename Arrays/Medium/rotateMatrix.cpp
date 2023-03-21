#include <bits/stdc++.h>
using namespace std;

int main()
{

    int m;
    cin >> m;
    vector<vector<int>> matrix(m, vector<int>(m, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        swap(matrix[i][0], matrix[0][i]);
    }
    for (int i = 1; i < m; i++)
    {
        swap(matrix[m - 1][i], matrix[i][m - 1]);
    }

    

    int i = 0, j = m - 1;
    while (i < j)
    {
        for (int row = 0; row < m; row++)
        {
            swap(matrix[row][i], matrix[row][j]);
        }
        i++;
        j--;
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}