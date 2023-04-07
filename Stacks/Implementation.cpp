#include <bits\stdc++.h>
using namespace std;

class Stack
{
    int top;
    int size;
    int *arr;

public:
    Stack(int size)
    {
        this->top = -1;
        this->size = size;
        this->arr = new int[size];
    }

    void push(int element)
    {
        if (top == size - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        else
        {
            top++;
            arr[top] = element;
            return;
        }
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        else
        {
            int x = arr[top];
            top--;
            return x;
        }
    }
    void display()
    {
        int temp = top;
        while (temp >= 0)
        {
            cout << arr[temp] << endl;
            temp--;
        }
    }

    int peekElement()
    {
        if (top == -1)
            return -1;
        else
            return arr[top];
    }

    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
};

int main()
{
    Stack s(10);
    s.display();
}