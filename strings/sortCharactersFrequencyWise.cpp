#include <bits\stdc++.h>
using namespace std;

string frequencySort(string s)
{
    map<char, int> mp;
    bool isCap = false;
    for (auto it : s)
    {
        mp[it]++;
        if (it - 'a' >= 'A' && it - 'a' <= 'Z')
            isCap = true;
    }

    string ans = "";
    for (auto it : mp)
    {
        for (int i = 0; i < it.second; i++)
            ans += it.first;
    }

    if (isCap == true)
        reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string str;
    cin >> str;
    cout << frequencySort(str) << endl;
}