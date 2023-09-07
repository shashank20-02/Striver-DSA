#include <bits\stdc++.h>
#define read(n, arr)            \
    for (int i = 0; i < n; i++) \
        cin >> arr[i];
#define array(n, i) vector<int> i(n, 0);
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int main()
{
    int n;
    cin >> n;
    array(n, start);
    array(n, end);
    read(n, start);
    read(n, end);
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; i++)
    {
        vec.push_back({start[i], end[i]});
    }

    sort(vec.begin(), vec.end(), cmp);
    int ans = 0, cEnd = 0;
    for (auto itr : vec)
    {
        if (itr.first > cEnd)
        {
            ans++;
            cout << itr.first << " , " << itr.second << endl;
            cEnd = itr.second;
        }
    }
    cout << ans << endl;
    return 0;
}