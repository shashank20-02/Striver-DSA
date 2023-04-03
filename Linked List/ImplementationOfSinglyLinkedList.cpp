#include <bits\stdc++.h>
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

// Insert at head
void insertAtHead(Node *&head, int data)
{
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

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

void insertAtMiddle(Node *&head, int pos, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    else if (pos == 0)
    {
        return insertAtHead(head, data);
    }
    Node *temp = head;
    while (pos > 1 && temp->next != NULL)
    {
        temp = temp->next;
        pos--;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtHead(Node *&head)
{
    if (head == NULL)
    {
        cout << "No elements" << endl;
        return;
    }

    Node *temp = head;
    head = head->next;
    delete temp;
}

void deleteAtTail(Node *&head)
{
    if (head == NULL)
    {
        cout << "No elements" << endl;
        return;
    }
    Node *temp1 = head;
    Node *temp2 = head->next;
    while (temp2->next != NULL)
    {
        temp1 = temp2;
        temp2 = temp2->next;
    }
    temp1->next = NULL;
    delete temp2;
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
    insertAtTail(head, 50);
    insertAtTail(head, 60);
    insertAtTail(head, 70);
    print(head);
    return 0;
}