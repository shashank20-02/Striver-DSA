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

int maxSum(Node *root, int maxi)
{
    if (root == nullptr)
        return 0;

    int lh = max(0, maxSum(root->left, maxi));
    int rh = max(0, maxSum(root->right, maxi));
    maxi = max(maxi, root->data + lh + rh);
    return root->data + max(lh, rh);
}

int main()
{
    Node *rootNode = NULL;
    rootNode = CreateTree(rootNode);

    return 0;
}

// 1 3 7 -1 -1 9 -1 -1 5 11 -1 -1 13 -1 -1