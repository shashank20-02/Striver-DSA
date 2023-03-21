#include <bits\stdc++.h>
using namespace std;

void print(vector<int> &arr)
{
    for (auto it : arr)
        cout << it << " ";
    cout << endl;
}

void sorted(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    for (int i = 0; i < n; i++)
        nums1[m + i] = nums2[i];

    int gap = ceil((m + n) / 2);
    while (gap > 0)
    {
        int lo = 0, hi = gap;
        while (hi < (m + n))
        {
            if (nums1[lo] > nums1[hi])
            {
                swap(nums1[lo], nums1[hi]);
            }
            lo++;
            hi++;
        }
        if (gap == 1)
            gap = 0;
        else
            gap = (gap / 2) + (gap % 2);
    }
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<int> nums1(m + n, 0), nums2(n, 0);

    for (int i = 0; i < m; i++)
        cin >> nums1[i];
    for (int i = 0; i < n; i++)
        cin >> nums2[i];

    sorted(nums1, m, nums2, n);

    for (int i = 0; i < nums1.size(); i++)
        cout << nums1[i] << " ";
    cout << endl;
    return 0;
}