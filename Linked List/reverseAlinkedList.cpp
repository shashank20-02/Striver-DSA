#include <bits\stdc++.h>
#define ln Node *
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

Node *reverseLL(Node *&head)
{
    ln dummy = NULL;
    while (head != NULL)
    {
        ln next = head->next;
        head->next = dummy;
        dummy = head;
        head = next;
    }
    return dummy;
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
    ln head = NULL;
    for (int i = 10; i < 60; i += 10)
    {
        insertAtTail(head, i);
    }
    print(head);
    head = reverseLL(head);
    print(head);
    return 0;
}