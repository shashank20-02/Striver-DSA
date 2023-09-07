#include <bits\stdc++.h>
using namespace std;

bool BFS(int src, vector<vector<int>> &graph, vector<int> &color)
{
    queue<int> q;
    q.push(src);
    color[src] = 0;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (auto itr : graph[curr])
        {
            if (color[itr] == -1)
            {
                q.push(itr);
                color[itr] = !color[curr];
            }
            else if (color[itr] == color[curr])
                return false;
        }
    }
    return true;
}
bool isBipartite(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (BFS(i, graph, color) == false)
                return false;
        }
    }
    return true;
}
