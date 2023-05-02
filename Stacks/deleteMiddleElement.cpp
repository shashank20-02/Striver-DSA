#include <bits\stdc++.h>
using namespace std;

void deleteMiddle(stack<int> &inputStack, int N)
{

    int mid = N / 2;
    stack<int> arb;
    while (mid && !inputStack.empty())
    {
        arb.push(inputStack.top());
        inputStack.pop();
        mid--;
    }
    inputStack.pop();

    while (!arb.empty())
    {
        inputStack.push(arb.top());
        arb.pop();
    }
}

void print(stack<int> st)
{
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
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
    deleteMiddle(input, n);
    print(input);
}