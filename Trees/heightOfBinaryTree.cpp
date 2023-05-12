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
    int data;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }

    rootNode = new Node(data);
    rootNode->left = CreateTree(rootNode->left);
    rootNode->right = CreateTree(rootNode->right);
    return rootNode;
}

int levelOrder(Node *rootNode)
{
    if (rootNode == NULL)
    {
        return 0;
    }

    int l = levelOrder(rootNode->left);
    int r = levelOrder(rootNode->right);
    return 1 + max(l, r);
}

int main()
{
    Node *rootNode = NULL;
    rootNode = CreateTree(rootNode);

    return 0;
}