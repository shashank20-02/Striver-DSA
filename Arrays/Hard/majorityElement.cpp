#include <bits\stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<int> ans;
    int num1 = -1, num2 = -1, c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++)
    {
        int value = nums[i];
        if (value == num1)
            c1++;
        else if (value == num2)
            c2++;
        else if (c1 == 0)
        {
            num1 = value;
            c1 = 1;
        }
        else if (c2 == 0)
        {
            num2 = value;
            c2 = 1;
        }
        else
        {
            c1--;
            c2--;
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == num1)
            count++;
    }
    if (count > floor(n / 3))
        ans.push_back(num1);
    count = 0;
    for (int i = 0; i < n; i++)
        if (nums[i] == num2)
            count++;
    if (count > floor(n / 3))
        ans.push_back(num2);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}