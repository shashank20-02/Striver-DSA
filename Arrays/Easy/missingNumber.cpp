#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0), temp(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        temp[arr[i]]++;
    }

    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i] == 0)
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}

// 9 6 4 2 3 5 7 0 1