#include <bits\stdc++.h>
#include "allFunction.cpp"
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    vector<int> next(n, 0), prev(n, 0);
    func f = func();
    next = f.nextSmallerElementIndex(heights);
    prev = f.previousSmallerElementIndex(heights);
    int area = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int l = heights[i];
        if (next[i] == -1)
        {
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;
        int newArea = l * b;
        area = max(area, newArea);
    }
    return area;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << largestRectangleArea(arr) << endl;
    return 0;
}

// 2 1 5 6 2 3