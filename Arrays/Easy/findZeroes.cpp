#include <bits/stdc++.h>
using namespace std;

int findZeroes(int arr[], int n, int m)
{
    int i = 0, last_flipped_pointer = 0, answer = 0, tempM = m, currentAnswer = 0;
    while (i <= n - 1)
    {
        if (arr[i] == 0 && m != 0)
        {
            currentAnswer++;
            m--;
            last_flipped_pointer = i;
            i++;
        }
        else if (arr[i] == 0 && m == 0)
        {
            answer = max(answer, currentAnswer);
            currentAnswer = 0;
            m = tempM;
            i = last_flipped_pointer + 1;
        }
        else
        {
            currentAnswer++;
            i++;
        }
    }

    return answer;
}

int main()
{
    int n, m, arr[1000] = {0};
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> m;

    cout << findZeroes(arr, n, m);
    return 0;
}