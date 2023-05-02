#include <bits\stdc++.h>
using namespace std;

vector<int> previousSmallerElement(vector<int> &arr)
{
    int n = arr.size();
    vector<int> pse(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        int element = arr[i];
        if (st.empty())
        {
            pse[i] = -1;
            st.push(element);
        }
        else if (!st.empty() && st.top() < element)
        {
            pse[i] = st.top();
            st.push(element);
        }
        else
        {
            while (!st.empty() && st.top() >= element)
            {
                st.pop();
            }
            if (st.empty())
                pse[i] = -1;
            else
                pse[i] = st.top();
            st.push(element);
        }
    }
    return pse;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> pse = previousSmallerElement(arr);
    for (auto it : pse)
    {
        cout << it << endl;
    }
    return 0;
}

// 4 5 2 10 8