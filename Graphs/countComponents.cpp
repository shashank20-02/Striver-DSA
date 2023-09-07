#include <bits\stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &graph, vector<bool> &visited, int source)
{
    queue<int> q;
    q.push(source);
    visited[source] = 1;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (int i = 0; i < graph.size(); i++)
        {
            if (curr != i && graph[curr][i] == 1 && !visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

int countComponents(vector<vector<int>> &graph)
{
    int connectedComponents = 0, n = graph.size();
    vector<bool> visited(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            connectedComponents++;
            bfs(graph, visited, i);
        }
    }
    return connectedComponents;
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    cout << countComponents(graph) << endl;
}

int main()
{
    int Switch = 0;
    cout << Switch << endl;
    // solve();
}