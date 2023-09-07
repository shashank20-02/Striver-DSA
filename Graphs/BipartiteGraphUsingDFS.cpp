#include <bits\stdc++.h>
using namespace std;

bool DFS(int src, int col, vector<int> adj[], vector<int> &color)
{
    color[src] = col;
    for (auto itr : adj[src])
    {
        if (color[itr] == -1)
        {
            if (!DFS(itr, !col, adj, color))
                return false;
        }
        else if (color[itr] == col)
            return false;
    }
    return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges)
{
    int n = edges.size();
    vector<int> adj[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (edges[i][j] == 1)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (!DFS(i, 0, adj, color))
                return false;
        }
    }
    return true;
}

int main()
{
    int e;
    cin >> e;
    vector<vector<int>> edges;
    for (int i = 0; i < e; i++)
    {
        vector<int> temp;
        for (int i = 0; i < e; i++)
        {
            int val;
            cin >> val;
            temp.push_back(val);
        }
        edges.push_back(temp);
    }
    cout << isGraphBirpatite(edges) << endl;
    return 0;
}