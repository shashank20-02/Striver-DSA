#include <bits\stdc++.h>
using namespace std;

void depthFirstSearch(vector<vector<int>> graph, int source)
{
    stack<int> st;
    vector<bool> visited(graph.size());
    st.push(source);
    visited[source] = 1;
    while (!st.empty())
    {
        int current = st.top();
        cout << current << " ";
        st.pop();
        vector<int> neighbors = graph[current];
        for (auto neighbor : neighbors)
        {
            if (!visited[neighbor])
            {
                st.push(neighbor);
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
    depthFirstSearch(graph, source);
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