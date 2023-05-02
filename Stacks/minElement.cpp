#include <bits\stdc++.h>
using namespace std;

stack<int> st;
int mini = INT_MAX;

void push(int val)
{
    if (mini >= val)
    {
        st.push(mini);
        mini = val;
    }
    st.push(val);
}

void pop()
{
    if (mini == st.top())
    {
        st.pop();
        mini = st.top();
    }
    st.pop();
}

int top()
{
    return st.top();
}

int minElement()
{
    return mini;
}

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cout << "1 for push 2 for pop 3 for top 4 for minElement" << endl;
        cin >> n;
        switch (n)
        {
        case 1:
            int val;
            cin >> val;
            push(val);
            break;
        case 2:
            pop();
            break;
        case 3:
            cout << top() << endl;
            break;
        case 4:
            cout << minElement() << endl;
            break;
        }
    }
}