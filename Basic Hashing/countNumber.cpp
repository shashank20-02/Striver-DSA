#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, answer = -999;
    cin >> n;
    unordered_map<int, int> map;
    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        map[arr[i]]++;
    }
    for (auto it : map)
    {
        answer = max(answer, it.second);
    }
    cout << answer << endl;
    return 0;
}