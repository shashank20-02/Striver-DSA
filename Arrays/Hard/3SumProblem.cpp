#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSumApproach1(vector<int> &nums)
{
    set<vector<int>> s;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            for (int k = j + 1; k < nums.size(); k++)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0)
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    sort(temp.begin(), temp.end());
                    s.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(s.begin(), s.end());
    return ans;
}

vector<vector<int>> threeSumApproach2(vector<int> &nums)
{
    unordered_map<int, int> map;
    set<vector<int>> s;
    for (int i = 0; i < nums.size(); i++)
        map[nums[i]]++;

    for (int i = 0; i < nums.size(); i++)
    {
        map[nums[i]]--;
        for (int j = i + 1; j < nums.size(); j++)
        {
            map[nums[j]]--;
            if (map.find(-(nums[i] + nums[j])) != map.end())
            {
                vector<int> temp;
                temp.push_back(nums[i]);
                temp.push_back(nums[j]);
                temp.push_back(-(nums[i] + nums[j]));
                sort(temp.begin(), temp.end());
                s.insert(temp);
            }
            map[nums[j]]++;
        }
        map[nums[i]]++;
    }
    vector<vector<int>> ans(s.begin(), s.end());
    return ans;
}

vector<vector<int>> threeSumApproach3(vector<int> &nums)
{
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < (int)(nums.size()) - 2; i++)
    {
        if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
        {
            int lo = i + 1, hi = (int)(nums.size()) - 1, sum = 0 - nums[i];
            cout << nums[i] << nums[lo] << nums[hi] << endl;
            while (lo < hi)
            {
                if (nums[lo] + nums[hi] == sum)
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[lo]);
                    temp.push_back(nums[hi]);
                    ans.push_back(temp);
                    while (lo < hi && nums[lo] == nums[lo - 1])
                        lo++;
                    while (lo < hi && nums[hi] == nums[hi - 1])
                        hi--;
                    lo++;
                    hi--;
                }
                else if (nums[lo] + nums[hi] < sum)
                {
                    lo++;
                }
                else
                {
                    hi--;
                }
            }
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<vector<int>> ans = threeSumApproach3(arr);
    for (auto i : ans)
    {
        for (int j = 0; j < i.size(); j++)
            cout << i[j] << " ";
        cout << endl;
    }
    return 0;
}