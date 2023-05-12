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

void iterativePostOrderTraversal(Node *rootNode)
{
    stack<Node *> st1, st2;
    st1.push(rootNode);
    while (!st1.empty())
    {
        Node *temp = st1.top();
        st1.pop();
        if (temp->left)
            st1.push(temp->left);
        if (temp->right)
            st1.push(temp->right);
        st2.push(temp);
    }

    while (!st2.empty())
    {
        cout << st2.top()->data << " ";
        st2.pop();
    }
    cout << endl;
}

int main()
{
    Node *rootNode = NULL;
    rootNode = CreateTree(rootNode);
    iterativePostOrderTraversal(rootNode);
    return 0;
}

// 1 2 3 -1 -1 4 5 -1 -1 6 -1 -1 7 -1 -1