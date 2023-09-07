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

vector<vector<int>> verticalOrderTraversal(Node *root)
{
    vector<vector<int>> ans;
    if (!root)
        return ans;
    // pair.first = vertical , pair.second = level
    queue<pair<Node *, pair<int, int>>> todo;
    map<int, map<int, multiset<int>>> mp;
    todo.push({root, {0, 0}});
    while (!todo.empty())
    {
        auto a = todo.front();
        todo.pop();
        Node *node = a.first;
        int x = a.second.first, y = a.second.second;
        mp[x][y].insert(node->data);
        if (node->left)
            todo.push({node->left, {x - 1, y + 1}});
        if (node->right)
            todo.push({node->right, {x + 1, y + 1}});
    }

    for (auto it : mp)
    {
        vector<int> col;
        for (auto p : it.second)
        {
            col.insert(col.end(), p.second.begin(), p.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}