#include <bits\stdc++.h>
using namespace std;

int longestSubstring(string str)
{
    unordered_map<char, int> mp;
    int s = 0, e = 0, ans = 0;
    while (e < str.length())
    {
        mp[str[e]]++;
        if (mp.size() == e - s + 1)
        {
            ans = max(ans, e - s + 1);
        }
        else
        {
            while (mp.size() < e - s + 1)
            {
                mp[str[s]]--;
                if (mp[str[s]] == 0)
                    mp.erase(str[s]);
                s++;
            }
        }
        e++;
    }
    return ans;
}

int main()
{
    string str;
    cin >> str;
    cout << longestSubstring(str) << endl;
    return 0;
}