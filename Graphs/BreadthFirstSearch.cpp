#include <bits\stdc++.h>
using namespace std;

void BreadthFirstSearch(vector<vector<int>> graph, int source)
{
    if (source >= graph.size())
        return;
    queue<int> q;
    vector<bool> visited(graph.size());
    q.push(source);
    visited[source] = 1;
    while (!q.empty())
    {
        int current = q.front();
        cout << current << " ";
        q.pop();
        vector<int> neighbors = graph[current];
        for (auto neighbor : neighbors)
        {
            if (!visited[neighbor])
            {
                q.push(neighbor);
                visited[neighbor] = 1;
            }
        }
    }
}

void solve(int testCase)
{
    cout << "# " << testCase << " Case" << endl;
    int v, e;
    cin >> v >> e;
    vector<vector<int>> graph(v + 1);
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int source;
    cin >> source;
    BreadthFirstSearch(graph, source);
}

int main()
{
    int t, cases = 1;
    cin >> t;
    while (cases <= t)
    {
        solve(cases);
        cases++;
    }
}