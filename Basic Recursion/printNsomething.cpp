#include <bits/stdc++.h>
using namespace std;

void recursive(int n, string name)
{
    if (n == 0)
        return;
    cout << name << endl;
    recursive(n - 1, name);
}

int main()
{
    int n;
    cin >> n;
    recursive(n, "shashank");
    return 0;
}