#include<bits\stdc++.h>
using namespace std;

class Node{
    public:
        int data ;
        Node *next;

        Node(int data = 0){
            this->data = data;
            this->next = NULL;
        }
};

void InsertAtHead(Node* &Head , int data){
    Node *newNode = new Node(data);
    newNode->next = Head->next;
    Head = newNode;
}

void InsertAtTail(Node* &Head , int data){
    Node *newnode = new Node(data);
    Node *temp = Head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
}

void InsertAtMiddle(Node* &Head , int position , int data){
    Node *newnode = new Node(data);
    Node *temp = Head;
    while(position > 1 && temp->next != NULL){
        temp = temp->next;
        position--;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void traverse(Node* &Head){
    Node *temp = Head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    Node *Head = new Node();
    InsertAtTail(Head , 10);
    InsertAtMiddle(Head , 1 , 100);
    InsertAtTail(Head , 99);
    InsertAtHead(Head , 1);
    traverse(Head);
    return 0 ;
}