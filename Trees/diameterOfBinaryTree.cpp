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

int diameter(Node *rootNode, int &maxi)
{
    if (rootNode == NULL)
        return 0;
    int lh = diameter(rootNode->left, maxi);
    int rh = diameter(rootNode->right, maxi);
    maxi = max(maxi, lh + rh);
    return 1 + max(lh, rh);
}

int diameterSolve(Node *rootNode)
{
    if (rootNode == NULL)
        return 0;

    int maxi = 0;
    diameter(rootNode, maxi);
    return maxi;
}

int main()
{
    Node *rootNode = NULL;
    rootNode = CreateTree(rootNode);

    return 0;
}