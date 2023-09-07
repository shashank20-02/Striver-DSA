#include <bits\stdc++.h>
using namespace std;

bool DetectUsingBfs(int source, vector<bool> &visited, vector<int> adj[])
{
    queue<pair<int, int>> q;
    q.push({source, -1});
    visited[source] = 1;
    while (!q.empty())
    {
        int parent = q.front().second;
        int curr = q.front().first;
        q.pop();
        for (auto itr : adj[curr])
        {
            if (!visited[itr])
            {
                visited[itr] = 1;
                q.push({itr, curr});
            }
            else if (itr != parent)
                return true;
        }
    }
    return false;
}

bool isCycle(int v, int e, vector<pair<int, int>> &edges)
{
    vector<int> adj[v + 1];
    vector<bool> visited(v + 1, 0);
    for (auto itr : edges)
    {
        adj[itr.first].push_back(itr.second);
        adj[itr.second].push_back(itr.first);
    }

    for (int i = 1; i <= v; i++)
    {
        if (!visited[i])
        {
            if (DetectUsingBfs(i, visited, adj))
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
        int i1, i2;
        cin >> i1 >> i2;
        edges.push_back({i1, i2});
    }
    if (isCycle(v, e, edges))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}