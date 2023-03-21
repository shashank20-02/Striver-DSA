#include <bits\stdc++.h>
using namespace std;

bool result(long long mid, long long k, vector<int> &bananas)
{
    int sum = 0;
    for (int i = 0; i < bananas.size(); i++)
    {
        if (bananas[i] > mid)
        {
            sum += ((bananas[i] / mid) + (bananas[i] % mid == 0 ? 0 : 1));
        }
        else
            sum += 1;
    }
    if (sum <= k)
        return true;
    else
        return false;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> bananas(n, 0);

    for (int i = 0; i < n; i++)
        cin >> bananas[i];

    cout << "entered" << endl;
    vector<int>::iterator maxi = max_element(bananas.begin(), bananas.end());
    int index = distance(bananas.begin(), maxi);
    long long int lo = 1, hi = bananas[index], mid;
    while (hi - lo > 1)
    {
        cout << " entered " << endl;
        mid = (lo + hi) / 2;
        if (result(mid, k, bananas))
        {
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
    if (result(lo, k, bananas))
    {
        cout << lo << " " << endl;
    }
    else
        cout << hi << " " << endl;
    return 0;
}
// 30 11 23 4 20