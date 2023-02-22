#include <bits/stdc++.h>
using namespace std;

bool palindrome(string str, int lo, int hi)
{
    if (lo > hi)
        return true;

    if (str[lo] == str[hi])
        palindrome(str, lo + 1, hi - 1);
    else
        return false;
}

int main()
{
    string str;
    cin >> str;
    if (palindrome(str, 0, str.length() - 1))
        cout << "Yes" << endl;
    else
        cout << "NO" << endl;
    return 0;
}