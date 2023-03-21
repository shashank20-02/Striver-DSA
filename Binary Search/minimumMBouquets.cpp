#include <bits\stdc++.h>
using namespace std;

bool result(long long int mid, int m, int k, vector<int> &bloomDay)
{
    int streak = 0, m_created = 0;
    for (int i = 0; i < bloomDay.size(); i++)
    {
        if (bloomDay[i] > mid)
        {
            if (streak == k)
            {
                m_created++;
                streak = 0;
            }
            else
                streak = 0;
        }
        else
        {
            streak++;
            if (streak == k)
            {
                m_created++;
                streak = 0;
            }
        }
    }
    if (m_created >= m)
        return true;
    else
        return false;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> bloomDay(n, 0);
    for (int i = 0; i < n; i++)
        cin >> bloomDay[i];

    vector<int>::iterator maxi = max_element(bloomDay.begin(), bloomDay.end());
    int index = distance(bloomDay.begin(), maxi);

    long long int lo = 1, hi = bloomDay[index], mid;
    while (hi - lo > 1)
    {
        mid = (lo + hi) / 2;
        if (result(mid, m, k, bloomDay))
        {
            hi = mid;
        }
        else
            lo = mid + 1;
    }
    if (result(hi, m, k, bloomDay))
        cout << hi << endl;
    else if (result(lo, m, k, bloomDay))
    {
        cout << lo << endl;
    }
    else
        cout << -1 << endl;
    return 0;
}
