#include <bits\stdc++.h>
using namespace std;

vector<int> previousGreaterElement(vector<int> &arr)
{
    int n = arr.size();
    vector<int> pge(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        int element = arr[i];
        if (st.empty())
        {
            pge[i] = -1;
            st.push(element);
        }
        else if (!st.empty() && st.top() > element)
        {
            pge[i] = st.top();
            st.push(element);
        }
        else
        {
            while (!st.empty() && st.top() <= element)
            {
                st.pop();
            }
            if (st.empty())
                pge[i] = -1;
            else
                pge[i] = st.top();
            st.push(element);
        }
    }
    return pge;
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
    vector<int> pge = previousGreaterElement(arr);
    for (auto it : pge)
    {
        cout << it << endl;
    }
    return 0;
}