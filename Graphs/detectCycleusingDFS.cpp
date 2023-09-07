#include <bits\stdc++.h>
using namespace std;

bool detectCycleUsingDFS(int source, int parent, vector<int> adj[], vector<bool> &visited)
{
    visited[source] = 1;
    for (auto itr : adj[source])
    {
        if (!visited[itr])
        {
            if (detectCycleUsingDFS(itr, source, adj, visited))
                ;
            return true;
        }
        else if (itr != parent)
            return true;
    }
    return false;
}

bool isCycle(int v, int e, vector<pair<int, int>> &edges)
{
    vector<bool> visited(v + 1, 0);
    vector<int> adj[v + 1];
    for (auto itr : edges)
    {
        adj[itr.first].push_back(itr.second);
        adj[itr.second].push_back(itr.first);
    }

    for (int i = 1; i <= v; i++)
    {
        if (!visited[i])
        {
            if (detectCycleUsingDFS(i, -1, adj, visited))
                return true;
        }
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int v, e;
        cin >> v >> e;
        vector<pair<int, int>> edges;
        for (int i = 0; i < e; i++)
        {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        cout << isCycle(v, e, edges) << endl;
    }
    return 0;
}