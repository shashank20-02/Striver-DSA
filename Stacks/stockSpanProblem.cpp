#include <bits\stdc++.h>
using namespace std;

vector<int> calculateSpan(vector<int> &price, int n)
{
    vector<int> pse(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        int el = price[i];
        if (st.empty())
        {
            pse[i] = 0;
            st.push(i + 1);
        }
        else if (price[st.top() - 1] > el)
        {
            pse[i] = st.top();
            st.push(i + 1);
        }
        else
        {
            while (!st.empty() && price[st.top() - 1] <= el)
            {
                st.pop();
            }
            if (st.empty())
                pse[i] = 0;
            else
                pse[i] = st.top();
            st.push(i + 1);
        }
    }

    for (int i = 0; i < n; i++)
    {
        pse[i] = i - pse[i] + 1;
    }
    return pse;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> pse = calculateSpan(arr, n);
    for (auto it : pse)
        cout << it << " ";
    return 0;
}