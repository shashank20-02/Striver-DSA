#include <bits\stdc++.h>
using namespace std;

bool balanced(string str)
{
    stack<int> s;
    for (auto it : str)
    {
        if (it == '(' || it == '[' || it == '{')
            s.push(it);
        else
        {
            if (!s.empty())
            {
                char a = s.top();
                if (a == '(' && it == ')' || a == '[' && a == ']' || a == '{' && a == '}')
                {
                    s.pop();
                }
                else
                    return false;
            }
            else
                s.push(it);
        }
    }
    return s.empty();
}

int main()
{
    string str;
    cin >> str;
    cout << balanced(str) << endl;
    return 0;
}