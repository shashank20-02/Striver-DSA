#include <bits\stdc++.h>
using namespace std;

string prefixToInfix(string prefix)
{
    reverse(prefix.begin(), prefix.end());
    stack<string> st;
    for (auto it : prefix)
    {
        if (it == '+' || it == '-' || it == '*' || it == '/' || it == '^')
        {
            string temp = "(";
            temp += st.top();
            st.pop();
            temp += it;
            temp += st.top();
            st.pop();
            temp += ')';
            st.push(temp);
        }
        else
        {
            string temp = "";
            temp += it;
            st.push(temp);
        }
    }
    return st.top();
}

int main()
{
    string str;
    cin >> str;
    cout << prefixToInfix(str) << endl;
    return 0;
}