#include <bits\stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int data = 0)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void InsertAtHead(Node *&Head, int data)
{
    Node *newNode = new Node(data);
    newNode->next = Head->next;
    newNode->prev = Head;
    Head->next = newNode;
}

void InsertAtTail(Node *&Head, int data)
{
    Node *newNode = new Node(data);
    if (Head->next == NULL)
    {
        newNode->next = Head->next;
        newNode->prev = Head;
        Head->next = newNode;
        return;
    }

    Node *temp = Head->next;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void InsertAtMiddle(Node *&Head, int pos, int data)
{
    Node *newNode = new Node(data);
    if (Head->next == NULL)
    {
        newNode->next = Head->next;
        newNode->prev = Head;
        Head->next = newNode;
        return;
    }

    Node *temp1 = new Node();
    Node *temp2 = new Node();
    temp1 = Head, temp2 = Head->next;
    while (pos > 1 && temp2->next != NULL)
    {
        temp1 = temp2;
        temp2 = temp2->next;
        pos--;
    }
    if (temp2->next != NULL)
    {
        temp1->next = newNode;
        newNode->prev = temp1;
        newNode->next = temp2;
        temp2->prev = newNode;
    }
    else
    {
        temp2->next = newNode;
        newNode->prev = temp2;
    }
}

void print(Node *Head)
{
    Head = Head->next;
    int cnt = 0;
    while (Head != NULL)
    {
        if (Head->next == NULL)
            cout << Head->data << endl;
        else
            cout << Head->data << " <-> ";
        Head = Head->next;
        cnt++;
    }

    cout << "Elments in the doubly LL are: " << cnt << endl;
    return;
}

int main()
{
    Node *Head = new Node();
    InsertAtTail(Head, 50);
    InsertAtTail(Head, 50);
    InsertAtTail(Head, 50);
    InsertAtMiddle(Head, 1, 60);
    print(Head);
    return 0;
}