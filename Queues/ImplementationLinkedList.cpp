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

class Queue
{
public:
    int size = 0;
    Node *front, *rear;

    Queue()
    {
        this->front = NULL;
        this->rear = NULL;
    }

    void push(int data)
    {
        if (front == NULL)
        {
            Node *newNode = new Node(data);
            front = rear = newNode;
        }
        else
        {
            Node *newNode = new Node(data);
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    int pop()
    {
        if (front == NULL)
        {
            return -1;
        }
        else if (front == rear)
        {
            int x = front->data;
            Node *temp = front;
            front = rear = NULL;
            delete temp;
            size--;
            return x;
        }
        else
        {
            int x = front->data;
            Node *temp = front;
            front = front->next;
            delete temp;
            size--;
            return x;
        }
    }

    void display()
    {
        Node *temp = front;
        while (temp != rear)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    bool isEmpty()
    {
        if (front == NULL)
            return true;
        else
            return false;
    }
    int QueueSize()
    {
        return size;
    }
};

int main()
{
    int q;
    Queue qt = Queue();
    cin >> q;
    while (q--)
    {
        int choice;
        cout << "1 for insertion 2 for deletion 3 for display 4 for size:" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            int data;
            cout << "Enter the value" << endl;
            cin >> data;
            qt.push(data);
            break;

        case 2:
            cout << "The deleted element is:" << qt.pop() << endl;
            break;
        case 3:
            qt.display();
            break;
        case 4:
            cout << qt.QueueSize() << endl;
            break;
        }
    }
}