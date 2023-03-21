#include <bits/stdc++.h>
using namespace std;
double long eps = 1e-6;
double long nthRoot(double long n, double long m)
{
    double long lo = 1, hi = m, mid;
    while (hi - lo > eps)
    {
        mid = lo + (hi - lo) / 2;
        double long sq = pow(mid, n);
        if (sq > m)
            hi = mid;
        else
            lo = mid;
    }

    return lo;
}

int main()
{
    double long n, m;
    cin >> n >> m;

    double long ans = nthRoot(n, m);
    cout << ans << endl;
    return 0;
}