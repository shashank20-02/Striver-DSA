#include <bits\stdc++.h>
using namespace std;

int characterReplacement(string str, int k)
{
    vector<int> mp(26, 0);
    int s = 0, e = 0, ans = 0, maxf = 0;
    while (e < str.length())
    {
        mp[str[e] - 'A']++;
        maxf = max(maxf, mp[str[e] - 'A']);
        if ((e - s + 1) - maxf <= k)
            ans = max(ans, e - s + 1);
        else
        {
            while ((e - s + 1) - maxf > k)
            {
                mp[str[s] - 'A']--;
                s++;
                maxf = *(max_element(mp.begin(), mp.end()));
            }
        }
        e++;
    }
    return ans;
}

int main()
{
    string str;
    int k;
    cin >> str >> k;

    cout << characterReplacement(str, k) << endl;
    return 0;
}