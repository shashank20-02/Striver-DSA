#include <bits\stdc++.h>
#include "allfunction.cpp"
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

int maximalRectangle(vector<vector<char>> &matrix)
{
    vector<int> histogram(matrix[0].size(), 0);
    int ans = INT_MIN;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == '1')
                histogram[j] += 1;
            else
                histogram[j] = 0;
        }
        ans = max(ans, largestRectangleArea(histogram));
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> arr(m, vector<char>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }

    cout << maximalRectangle(arr) << endl;
    return 0;
}