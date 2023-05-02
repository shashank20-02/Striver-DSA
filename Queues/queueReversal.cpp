#include <bits\stdc++.h>
using namespace std;

void reverseQueue(queue<int> &q)
{
    if (!q.size())
        return;
    int front = q.front();
    q.pop();
    reverseQueue(q);

    q.push(front);
}

queue<int> reverse(queue<int> q)
{
    reverseQueue(q);
    return q;
}

void print(queue<int> q)
{
    while (q.size())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    queue<int> q;
    int n;
    cin >> n;
    while (n--)
    {
        int val;
        cin >> val;
        q.push(val);
    }

    q = reverse(q);
    print(q);
}