#include <bits\stdc++.h>
using namespace std;

// stack<int> pushAtBottom(stack<int> &myStack, int x)
// {
//     stack<int> arb;
//     while (!myStack.empty())
//     {
//         arb.push(myStack.top());
//         myStack.pop();
//     }
//     myStack.push(x);
//     while (!arb.empty())
//     {
//         myStack.push(arb.top());
//         arb.pop();
//     }
//     return myStack;
// }

void recursive(stack<int> &myStack, int x)
{
    if (myStack.empty())
    {
        myStack.push(x);
        return;
    }

    int num = myStack.top();
    myStack.pop();
    recursive(myStack, x);
    myStack.push(num);
}

stack<int> pushAtBottom(stack<int> &myStack, int x)
{
    recursive(myStack, x);
    return myStack;
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
    stack<int> input;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        input.push(val);
    }
    print(input);
    input = pushAtBottom(input, 9);
    print(input);
}