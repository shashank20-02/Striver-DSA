#include <bits\stdc++.h>
using namespace std;

void bfs(vector<vector<char>> &grid, int src1, int src2, vector<vector<bool>> &visited)
{
    visited[src1][src2] = 1;
    queue<pair<int, int>> q;
    q.push({src1, src2});

    while (!q.empty())
    {
        int cr1 = q.front().first, cr2 = q.front().second;
        q.pop();
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                if (i != 0 && j != 0)
                {
                    int r1 = cr1 + i;
                    int r2 = cr2 + j;
                    if (!visited[r1][r2])
                    {
                        q.push({r1, r2});
                        visited[r1][r2] = 1;
                    }
                }
            }
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{
    int components = 0;
    int m = grid.size(), n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && grid[i][j] == '1' && !visited[i][j])
            {
                components++;
                bfs(grid, i, j, visited);
            }
        }
    }
    return components;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<char>> adj(m, vector<char>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];
    }

    cout << numIslands(adj) << endl;
}