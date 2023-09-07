#include <bits\stdc++.h>
using namespace std;

struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

vector<int> JobScheduling(Job arr[], int n)
{
    sort(arr, arr + n, [](Job a, Job b)
         { return a.profit > b.profit; });
    int maxi = -1;
    for (int i = 0; i < n; i++)
    {
        maxi = max(arr[i].dead, maxi);
    }
    vector<int> vis(maxi + 1, -1);
    int noDone = 0, profit = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].dead; j >= 1; j--)
        {
            if (vis[j] == -1)
            {
                vis[j] = arr[i].id;
                noDone++;
                profit += arr[i].profit;
                break;
            }
        }
    }

    vector<int> ans(2, 0);
    ans[0] = noDone, ans[1] = profit;
    return ans;
}
