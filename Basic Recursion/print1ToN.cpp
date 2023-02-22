#include <bits/stdc++.h>
using namespace std;

int recursive(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n + recursive(n - 1);
}

int main()
{
    int n;
    cin >> n;
    cout << recursive(n) << endl;
    return 0;
}