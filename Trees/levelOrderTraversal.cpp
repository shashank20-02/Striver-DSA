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

vector<vector<int>> LevelOrderTraversal(Node *root)
{
    queue<Node *> q;
    vector<vector<int>> ans;
    q.push(root);
    int level = 0;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> t;
        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
            t.push_back(temp->data);
        }
        if (level & 1 == 0)
            reverse(t.begin(), t.end());
        ans.push_back(t);

        level++;
    }
    return ans;
}

int main()
{
    Node *rootNode = NULL;
    rootNode = CreateTree(rootNode);
    vector<vector<int>> ans = LevelOrderTraversal(rootNode);

    cout << endl;
    return 0;
}

// 1 3 7 -1 -1 9 -1 -1 5 11 -1 -1 13 -1 -1