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

void InOrder(Node *rootNode)
{
    if (rootNode == NULL)
        return;

    InOrder(rootNode->left);
    cout << rootNode->data << " ";
    InOrder(rootNode->right);
}

int main()
{
    Node *rootNode = NULL;
    rootNode = CreateTree(rootNode);
    cout << endl;
    cout << "Inorder:" << endl;
    InOrder(rootNode);
    return 0;
}

// 1 2 3 -1 -1 4 5 -1 -1 6 -1 -1 7 -1 -1