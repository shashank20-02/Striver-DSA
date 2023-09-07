#include <bits\stdc++.h>
using namespace std;
bool bfs(int source, vector<int> adj[], vector<bool> &visited)
{
    queue<int> q;
    vector<bool> bfsvis(visited.size(), 0);
    q.push(source);
    visited[source] = bfsvis[source] = 1;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (auto itr : adj[curr])
        {
            if (!visited[itr] && !bfsvis[itr])
            {
                visited[itr] = bfsvis[itr] = 1;
                q.push(itr);
            }
            else if (visited[itr] && bfsvis[itr])
                return true;
        }
    }
    return false;
}

bool dfs(int source, vector<int> adj[], vector<bool> &visited, vector<bool> &dfsvis)
{
    visited[source] = dfsvis[source] = 1;
    for (auto itr : adj[source])
    {
        if (!visited[itr] && !dfsvis[itr])
        {
            bool ans = dfs(itr, adj, visited, dfsvis);
            if (ans)
            {
                cout << itr << endl;
                return true;
            }
        }
        else if (visited[itr] && dfsvis[itr])
            return true;
    }
    dfsvis[source] = 0;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    vector<bool> visited(n + 1, 0);
    vector<bool> dfsvis(n + 1, 0);
    vector<int> adj[n + 1];

    for (auto itr : edges)
    {
        adj[itr.first].push_back(itr.second);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, adj, visited, dfsvis))
                return true;
        }
    }
    return false;
}

int main()
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
    cout << detectCycleInDirectedGraph(v, edges) << endl;
}