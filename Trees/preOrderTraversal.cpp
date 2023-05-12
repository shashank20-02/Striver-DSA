#include <bits\stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

Node *CreateTree(Node *rootNode)
{
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }

    rootNode = new Node(data);
    cout << "Enter the data for leftNode for " << rootNode->data << ":" << endl;
    rootNode->left = CreateTree(rootNode->left);
    cout << "Enter the data for rightNode for " << rootNode->data << ":" << endl;
    rootNode->right = CreateTree(rootNode->right);
    return rootNode;
}

void PreOrder(Node *rootNode)
{
    if (rootNode == NULL)
        return;
    cout << rootNode->data << " ";
    PreOrder(rootNode->left);
    PreOrder(rootNode->right);
}

int main()
{
    Node *rootNode = NULL;
    rootNode = CreateTree(rootNode);
    cout << "Preorder:" << endl;
    PreOrder(rootNode);
}