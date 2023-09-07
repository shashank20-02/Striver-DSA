#include <bits\stdc++.h>
using namespace std;

void hasPath(vector<vector<int>> graph, int source, int destination)
{
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
    int source, destination;
    cin >> source >> destination;
    hasPath(graph, source, destination);
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