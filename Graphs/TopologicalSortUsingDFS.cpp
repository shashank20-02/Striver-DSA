// Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u v, vertex u comes before v in the ordering.

#include <bits\stdc++.h>
using namespace std;

void dfs(int src, vector<int> adj[], vector<bool> &visited, stack<int> &st)
{
    visited[src] = 1;
    for (auto itr : adj[src])
    {
        if (!visited[itr])
        {
            dfs(itr, adj, visited, st);
        }
    }
    st.push(src);
}

vector<int> TopoSort(int v, vector<int> adj[])
{
    stack<int> st;
    vector<int> ans;
    vector<bool> visited(v, 0);
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfs(i, adj, visited, st);
        }
    }

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<int> adj[v];
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> ans = TopoSort(v, adj);
    for (auto itr : ans)
    {
        cout << itr << " ";
    }
    return 0;
}