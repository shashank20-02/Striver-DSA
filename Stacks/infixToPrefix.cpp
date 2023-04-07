#include <bits\stdc++.h>
using namespace std;

int prec(char a)
{
    if (a == '+' || a == '-')
        return 1;
    else if (a == '*' || a == '/')
        return 2;
    else if (a == '^')
        return 3;
    else
        return -1;
}

string infixToPostfix(string str)
{
    stack<char> st;
    string postfix = "";
    for (auto it : str)
    {
        if (it >= 'a' && it <= 'z' || it >= 'A' && it <= 'Z' || it >= '0' && it <= '9')
        {
            postfix += it;
        }
        else if (it == '(')
        {
            st.push(it);
        }
        else if (it == ')')
        {
            while (st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && prec(it) <= prec(st.top()))
            {
                postfix += st.top();
                st.pop();
            }
            st.push(it);
        }
    }

    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}

string infixToPrefix(string str)
{
    reverse(str.begin(), str.end());

    for (auto it : str)
    {
        if (it == '(')
        {
            it = ')';
        }
        else if (it == ')')
            it = '(';
    }

    string prefix = infixToPostfix(str);
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main()
{
    string str;
    cin >> str;
}