#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    bool flag = true;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            flag = false;
            break;
        }
    }
    flag == true ? cout << "Yes" << endl : cout << "No" << endl;
    return 0;
}