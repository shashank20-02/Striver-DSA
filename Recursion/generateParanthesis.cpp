#include <bits\stdc++.h>
using namespace std;

void generate(int left, int right, string &str, vector<string> &ans, int n)
{
    if (left > n || right > n || right > left)
        return;
    if (str.length() == 2 * n)
    {
        ans.push_back(str);
        return;
    }
    str += '(';
    generate(left + 1, right, str, ans, n);
    str.pop_back();
    str += ')';
    generate(left, right + 1, str, ans, n);
    str.pop_back();
}

int main()
{
    int n;
    cin >> n;
    string str;
    vector<string> ans;
    generate(0, 0, str, ans, n);
    for (auto itr : ans)
    {
        cout << itr << endl;
    }
}