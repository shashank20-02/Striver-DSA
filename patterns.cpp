#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
            cout << k++
                 << " ";
        k = 1;
        cout << endl;
    }
    return 0;
}