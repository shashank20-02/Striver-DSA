#include <bits\stdc++.h>
using namespace std;
class func
{
public:
    vector<int> nextSmallerElementIndex(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> nse(n, 0);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            int el = heights[i];
            while (!st.empty() && heights[st.top()] > el)
            {
                st.pop();
            }
            nse[i] = st.size() ? st.top() : -1;
            st.push(i);
        }
        return nse;
    }
    vector<int> previousSmallerElementIndex(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> pse(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            int el = heights[i];
            while (!st.empty() && heights[st.top()] > el)
                st.pop();
            pse[i] = st.size() ? st.top() : -1;
            st.push(i);
        }
        return pse;
    }
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
};