#include <bits\stdc++.h>
using namespace std;
// functional Recursion
int sum(int n)
{
    if (n < 0)
        return 0;
    return n + sum(n - 1);
}

int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}
// Parameterized Recursion
void fact(int n, int factorial)
{
    if (n == 0 || n == 1)
    {
        cout << factorial << endl;
        return;
    }
    fact(n - 1, factorial * n);
}

int main()
{
    int n;
    cin >> n;
    cout << sum(n) << endl;
    cout << factorial(n) << endl;
    fact(n, 1);
    return 0;
}