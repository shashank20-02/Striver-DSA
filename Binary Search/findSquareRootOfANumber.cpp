#include <bits/stdc++.h>
using namespace std;

double precision = 1e-6;
double long squareRoot(double long n)
{
    double long lo = 1, hi = n, mid;
    while (hi - lo > precision)
    {
        mid = lo + (hi - lo) / 2;
        if (mid * mid > n)
            hi = mid;
        else
            lo = mid;
    }
    return lo;
}

int main()
{
    double long n;
    cin >> n;
    double long ans = squareRoot(n);
    cout << ans << endl;
    return 0;
}