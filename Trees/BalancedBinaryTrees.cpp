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

bool isBalanced(Node *rootNode)
{
    if (rootNode == NULL)
        return true;

    int diff = levelOrder(rootNode->left) - levelOrder(rootNode->right);
    if (abs(diff) > 1)
        return false;
    bool left = isBalanced(rootNode->left);
    bool right = isBalanced(rootNode->right);
    if (!left || !right)
        return false;
    return true;
}

int main()
{
    Node *rootNode = NULL;
    rootNode = CreateTree(rootNode);

    return 0;
}