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

void iterativeInorderTraversal(Node *rootNode)
{

    stack<Node *> st;
    Node *node = rootNode;
    while (true)
    {
        if (node != NULL)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            if (st.empty())
                break;
            Node *temp = st.top();
            st.pop();
            cout << temp->data << " ";
            node = temp->right;
        }
    }
    cout << endl;
}

int main()
{
    Node *rootNode = NULL;
    rootNode = CreateTree(rootNode);
    iterativeInorderTraversal(rootNode);

    return 0;
}

// 1 2 3 -1 -1 4 5 -1 -1 6 -1 -1 7 -1 -1