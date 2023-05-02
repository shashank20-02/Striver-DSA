#include <bits\stdc++.h>
using namespace std;

void print(vector<int> &arr)
{
    for (auto it : arr)
        cout << it << " ";

    cout << endl;
}

int sumofMin(vector<int> &arr)
{
    int n = arr.size();
    vector<int> prev(n, 0), next(n, 0);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
            st.pop();

        if (st.empty())
            prev[i] = i + 1;
        else
            prev[i] = i - st.top();
        st.push(i);
    }
    print(prev);

    while (st.size())
        st.pop();

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
            st.pop();
        if (st.empty())
            next[i] = n - i;
        else
            next[i] = st.top() - i;
        st.push(i);
    }
    print(next);

    int ans = 0, mod = 1e9 + 7;
    for (int i = 0; i < n; i++)
        ans += (arr[i] * prev[i] * next[i]) % mod;

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << sumofMin(arr) << endl;
    return 0;
}