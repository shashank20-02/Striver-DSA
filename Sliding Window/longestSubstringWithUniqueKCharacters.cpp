#include <bits\stdc++.h>
using namespace std;

int longestSubstring(string str, int k)
{
    unordered_map<char, int> mp;
    int start = 0, end = 0, ans = -1;
    while (end < str.length())
    {
        mp[str[end]]++;
        if (mp.size() == k)
        {
            ans = max(ans, (end - start) + 1);
            end++;
        }
        else if (mp.size() < k)
        {
            end++;
        }
        else
        {
            while (mp.size() > k)
            {
                mp[str[start]]--;
                if (mp[str[start]] == 0)
                    mp.erase(str[start]);
                start++;
            }
            end++;
        }
    }
    return ans;
}

int main()
{
    string str;
    int k;
    cin >> str >> k;

    cout << longestSubstring(str, k) << endl;
    return 0;
}