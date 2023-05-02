#include <bits\stdc++.h>
using namespace std;

int search(string pat, string txt)
{
    vector<int> freq1(26, 0), freq2(26, 0);
    for (auto it : pat)
    {
        freq1[it - 'a']++;
    }

    int k = pat.size(), cnt = 0;
    for (int i = 0; i < k; i++)
        freq2[txt[i] - 'a']++;

    if (freq1 == freq2)
        cnt++;
    for (int i = k; i < txt.size(); i++)
    {
        freq2[txt[i - k] - 'a']--;
        freq2[txt[i] - 'a']++;
        if (freq2 == freq1)
            cnt++;
    }
    return cnt;
}

int main()
{
    string pat, txt;
    cin >> pat >> txt;
    cout << search(pat, txt) << endl;
    return 0;
}