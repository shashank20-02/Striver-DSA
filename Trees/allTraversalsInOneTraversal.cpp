#include <bits\stdc++.h>
using namespace std;

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

vector<vector<int>> allTraversals(Node *rootNode)
{
    vector<int> preOrder;
    vector<int> inOrder;
    vector<int> postOrder;
    stack<pair<Node *, int>> st;
    st.push({rootNode, 1});
    while (!st.empty())
    {
        Node *temp = st.top().first;
        if (st.top().second == 1)
        {
            preOrder.push_back(temp->data);
            st.top().second++;
            if (temp->left)
                st.push({temp->left, 1});
        }
        else if (st.top().second == 2)
        {
            inOrder.push_back(temp->data);
            st.top().second++;
            if (temp->right)
                st.push({temp->right, 1});
        }
        else
        {
            postOrder.push_back(temp->data);
            st.pop();
        }
    }

    vector<vector<int>> ans;
    ans.push_back(preOrder);
    ans.push_back(inOrder);
    ans.push_back(postOrder);
    return ans;
}

int main()
{
    Node *rootNode = NULL;
    rootNode = CreateTree(rootNode);
    vector<vector<int>> ans = allTraversals(rootNode);
    cout << "All Traversals" << endl;
    for (auto it : ans)
    {
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}

// 1 3 7 -1 -1 9 -1 -1 5 11 -1 -1 13 -1 -1