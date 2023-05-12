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

void preOrderTraversal(Node *rootNode)
{
    stack<Node *> st;
    st.push(rootNode);
    while (!st.empty())
    {
        Node *temp = st.top();
        st.pop();
        if (temp->right)
            st.push(temp->right);
        if (temp->left)
            st.push(temp->left);
        cout << temp->data << " ";
    }
}

int main()
{
    Node *rootNode = NULL;
    rootNode = CreateTree(rootNode);
    preOrderTraversal(rootNode);
    return 0;
}

// 1 3 7 -1 -1 9 -1 -1 5 11 -1 -1 13 -1 -1
// 1 2 3 -1 -1 4 5 -1 -1 6 -1 -1 7 -1 -1