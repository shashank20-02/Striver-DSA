#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, cnt = 0;
    cin >> n;
    while (n != 0)
    {
        cnt++;
        n /= 10;
    }

    cout << cnt << endl;
    return 0;
}