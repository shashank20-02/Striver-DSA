#include <bits\stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> &arr)
{
    int n = arr.size();
    vector<int> nge(n, 0);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        int element = arr[i];
        if (st.empty())
        {
            nge[i] = -1;
            st.push(element);
        }
        else if (!st.empty() && st.top() > element)
        {
            nge[i] = st.top();
            st.push(element);
        }
        else
        {
            while (!st.empty() && st.top() <= element)
            {
                st.pop();
            }
            if (st.empty())
                nge[i] = -1;
            else
                nge[i] = st.top();
            st.push(element);
        }
    }
    return nge;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> nge(n, 0);
    nge = nextGreaterElement(arr);

    for (auto it : nge)
        cout << it << endl;
    return 0;
}