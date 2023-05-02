#include <bits\stdc++.h>
using namespace std;

int LargestSumKSubarray(vector<int> A, int K)
{
    int i = 0, j = 0, sum = 0;
    int maxLen = INT_MIN;

    while (j < A.size())
    {
        sum += A[j]; // calculation
        if (sum == K)
        {
            maxLen = max(maxLen, j - i + 1); // taking results
            j++;
        }
        else if (sum < K)
        { // adjusting window
            j++;
        }
        else if (sum > K)
        { // adjusting window
            while (sum > K)
            {
                sum -= A[i];
                i++;
            }
            if (sum == K)
            {
                maxLen = max(maxLen, j - i + 1);
            }
            j++;
        }
    }
    return maxLen;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << LargestSumKSubarray(arr, k) << endl;
    return 0;
}