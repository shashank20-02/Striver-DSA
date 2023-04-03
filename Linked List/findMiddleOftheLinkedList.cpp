#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data = 0)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtTail(Node *&head, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = new Node();
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

Node *middle(Node *&head)
{
    Node *first = head, *second = head;
    while (second != NULL && second->next != NULL)
    {
        first = first->next;
        second = second->next->next;
    }
    return first;
}

void print(Node *head)
{
    int cnt = 0;
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
        cnt++;
    }
    cout << endl;
    cout << "No of linked list elements are: " << cnt << endl;
    return;
}

int main()
{
    Node *head = NULL;
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    insertAtTail(head, 50);
    insertAtTail(head, 60);
    print(head);
    Node *first = middle(head);
    print(first);
    return 0;
}