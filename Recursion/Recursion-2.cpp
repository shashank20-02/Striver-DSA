#include <bits/stdc++.h>
using namespace std;

void reverse(int *arr, int i, int n)
{
    if (i >= n / 2)
        return;

    swap(arr[i], arr[n - 1 - i]);
    reverse(arr, i + 1, n);
}

bool palindrome(int i, string str)
{
    if (i >= str.length() / 2)
        return true;

    if (str[i] != str[str.length() - i - 1])
        return false;
    else
        return palindrome(i + 1, str);
}

int main()
{
    string str;
    cin >> str;
    bool ans = palindrome(0, str);
    ans ? cout << true << endl : cout << false << endl;
    //     int n;
    //     cin >> n;
    //     int arr[1000] = {0};
    //     for (int i = 0; i < n; i++)
    //         cin >> arr[i];
    //     cout << "Before Reverse:" << endl;
    //     for (int i = 0; i < n; i++)
    //         cout << arr[i] << " ";
    //     cout << endl;
    //     reverse(arr, 0, n);
    //     cout << "After Reverse:" << endl;
    //     for (int i = 0; i < n; i++)
    //     {
    //         cout << arr[i] << " ";
    //     }
    //     cout << endl;
}