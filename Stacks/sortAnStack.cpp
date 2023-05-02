#include <bits\stdc++.h>
using namespace std;

void insertAtPosition(stack<int> &stack, int top)
{
    if (stack.empty() || stack.top() < top)
    {
        stack.push(top);
        return;
    }

    int temp = stack.top();
    stack.pop();
    insertAtPosition(stack, top);
    stack.push(temp);
}

void sortStack(stack<int> &stack)
{
    if (stack.empty())
    {
        return;
    }
    int top = stack.top();
    stack.pop();
    sortStack(stack);

    insertAtPosition(stack, top);
}

void print(stack<int> st)
{
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        st.push(val);
    }
    print(st);
    sortStack(st);
    print(st);
    return 0;
}
