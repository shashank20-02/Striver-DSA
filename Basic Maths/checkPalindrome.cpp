#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, temp, rev = 0;
    cin >> n;
    temp = n;
    while (n != 0)
    {
        int rem = n % 10;
        cout << temp << " -> " << rev << endl;
        rev = rev * 10 + rem;
        n /= 10;
    }
    temp == rev ? cout << "Yes" << endl : cout << "No" << endl;
    return 0;
}