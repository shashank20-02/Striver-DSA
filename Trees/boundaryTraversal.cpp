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

bool isLeaf(Node *root)
{
    if (!root->left && !root->right)
        return true;
    return false;
}

void AddLeftNodes(Node *root, vector<int> &ans)
{
    while (root)
    {
        if (!isLeaf(root))
            ans.push_back(root->data);
        if (root->left)
            root = root->left;
        else
            root = root->right;
    }
}
void AddRightNodes(Node *root, vector<int> &ans)
{
    if (isLeaf(root))
        return;
    stack<int> st;
    while (root)
    {
        if (!isLeaf(root))
            st.push(root->data);
        if (root->right)
            root = root->right;
        else
            root = root->left;
    }
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
}
void AddLeafNodes(Node *root, vector<int> &ans)
{
    if (isLeaf(root))
    {
        ans.push_back(root->data);
        return;
    }
    if (root->left)
        AddLeafNodes(root->left, ans);
    if (root->right)
        AddLeafNodes(root->right, ans);
}

vector<int> boundary(Node *root)
{
    vector<int> ans;
    if (!root)
        return ans;
    if (!isLeaf(root))
        ans.push_back(root->data);
    AddLeftNodes(root->left, ans);
    AddLeafNodes(root, ans);
    AddRightNodes(root->right, ans);
    return ans;
}

int main()
{
    Node *rootNode = NULL;
    rootNode = CreateTree(rootNode);

    return 0;
}