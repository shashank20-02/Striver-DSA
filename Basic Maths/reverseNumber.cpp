#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, rev = 0;
    cin >> n;
    cout << n << " -> ";
    while (n != 0)
    {
        int rem = n % 10;
        rev = rev * 10 + rem;
        n /= 10;
    }
    cout << rev << endl;
    return 0;
}