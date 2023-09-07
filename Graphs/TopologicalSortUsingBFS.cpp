// kahn's algorithm

#include <bits\stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    vector<int> topo;
    queue<int> q;
    vector<int> adj[v], inorder(v, 0);
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0], v = edges[i][1];
        adj[u].push_back(v);
        inorder[v]++;
    }

    for (int i = 0; i < v; i++)
    {
        if (inorder[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        topo.push_back(curr);
        for (auto itr : adj[curr])
        {
            inorder[itr]--;
            if (inorder[itr] == 0)
                q.push(itr);
        }
    }
    return topo;
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<vector<int>> edges;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    vector<int> ans = topologicalSort(edges, v, e);
}