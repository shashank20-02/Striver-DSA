#include <bits\stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr)
{
    int n = arr.size();
    vector<int> nse(n, 0);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        int element = arr[i];
        if (st.empty())
        {
            nse[i] = -1;
            st.push(element);
        }
        else if (!st.empty() && st.top() < element)
        {
            nse[i] = st.top();
            st.push(element);
        }
        else
        {
            while (!st.empty() && st.top() >= element)
            {
                st.pop();
            }
            if (st.empty())
                nse[i] = -1;
            else
                nse[i] = st.top();
            st.push(element);
        }
    }
    return nse;
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
    vector<int> nse = nextSmallerElement(arr);
    for (auto it : nse)
    {
        cout << it << endl;
    }
    return 0;
}