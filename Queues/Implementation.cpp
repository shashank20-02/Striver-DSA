#include <bits\stdc++.h>
using namespace std;

class Queue
{
    int front;
    int rear;
    int size;
    int *arr;

public:
    Queue(int size)
    {
        this->size = size;
        this->arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push(int element)
    {
        if (rear == size - 1)
        {
            cout << "Queue is full" << endl;
            return;
        }
        else if (front == -1)
        {
            front++;
            rear++;
            arr[rear] = element;
            return;
        }
        else
        {
            rear++;
            arr[rear] = element;
            return;
        }
    }

    int pop()
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        else if (front == rear)
        {
            int x = arr[front];
            front = rear = -1;
            return x;
        }
        else
        {
            int x = arr[front];
            front++;
            return x;
        }
    }

    void display()
    {
        if (front == -1)
            return;
        else
        {

            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << endl;
            }
        }
    }

    int QueueSize()
    {
        if (front == -1)
            return 0;
        else
            return rear - front + 1;
    }

    bool isEmpty()
    {
        return front == -1 ? true : false;
    }
};

int main()
{
    Queue q(10);
    q.push(10);
    q.push(20);
    q.push(30);
    cout << "The size of the queue is:" << q.QueueSize() << endl;
    q.pop();
    cout << "The size of the queue is:" << q.QueueSize() << endl;
    q.pop();
    cout << "The size of the queue is:" << q.QueueSize() << endl;
    q.pop();
    cout << "The size of the queue is:" << q.QueueSize() << endl;
    cout << "The queue is:" << endl;
    cout << q.isEmpty() << endl;
    return 0;
}