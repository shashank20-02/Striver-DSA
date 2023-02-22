#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, rev = 0, temp;
    cin >> n;
    temp = n;
    while (n != 0)
    {
        int rem = n % 10;
        rev = rev + (rem * rem * rem);
        n /= 10;
    }
    temp == rev ? cout << "Yes" << endl : cout << "No" << endl;
    return 0;
}