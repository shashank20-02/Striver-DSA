#include <bits\stdc++.h>
using namespace std;
#define ll long long
vector<long long> printFirstNegativeInteger(vector<long long> &arr, long long int N, long long int K)
{
    deque<ll> dq;
    vector<ll> ans;
}

int main()
{
    long long n, k;
    cin >> n >> k;
    vector<long long> arr(n, 0);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<long long> ans = printFirstNegativeInteger(arr, n, k);
}