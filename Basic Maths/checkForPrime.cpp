#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, cnt = 0;
    cin >> n;
    for (int i = 2; i <= sqrt(n); i++)
    {

        if (n % i == 0)
        {
            cnt++;
            break;
        }
    }
    cnt == 0 ? cout << "Yes" << endl : cout << "No" << endl;
    return 0;
}