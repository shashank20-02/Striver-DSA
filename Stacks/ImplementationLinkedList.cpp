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

class Stack
{
public:
    int size;
    Node *head;
    Stack()
    {
        this->size = 0;
        this->head = NULL;
    }

    void push(int data)
    {
        if (head == NULL)
        {
            Node *newNode = new Node(data);
            head = newNode;
        }
        else
        {
            Node *newNode = new Node(data);
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    int pop()
    {
        if (head == NULL)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            int x = temp->data;
            delete temp;
            size--;
            return x;
        }
    }

    int StackSize()
    {
        return size;
    }

    bool IsEmpty()
    {
        return size == 0 ? true : false;
    }

    int peekElement()
    {
        if (head == NULL)
            return -1;
        else
            return head->data;
    }

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
        return;
    }
};

int main()
{
    int q;
    Stack s = Stack();
    cin >> q;
    while (q--)
    {
        int choice;
        cout << "1 for insertion 2 for deletion 3 for display 4 for peek Element:" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            int data;
            cout << "Enter the value" << endl;
            cin >> data;
            s.push(data);
            break;

        case 2:
            cout << "The deleted element is:" << s.pop() << endl;
            break;
        case 3:
            s.display();
            break;
        case 4:
            cout << s.peekElement() << endl;
            break;
        }
    }
}