#include <bits\stdc++.h>
using namespace std;

class Node
{
public:
    int key, value;
    Node *next, *prev;
    Node(int key = -1, int value = -1)
    {
        this->key = key;
        this->value = value;
        next = prev = NULL;
    }
};

class LRUCache
{
public:
    int cap;
    Node *head = new Node();
    Node *tail = new Node();
    unordered_map<int, Node *> mp;
    LRUCache(int cap)
    {
        this->cap = cap;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node *&newNode)
    {
        Node *temp = head->next;
        newNode->prev = head;
        newNode->next = temp;
        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(Node *&delNode)
    {
        Node *delprev = delNode->prev;
        Node *delnext = delNode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            Node *res = mp[key];
            mp.erase(key);
            deleteNode(res);
        }

        if (mp.size() == cap)
        {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        Node *newNode = new Node(key, value);
        addNode(newNode);
        mp[key] = newNode;
    }

    int get(int key)
    {
        if (mp.find(key) != mp.end())
        {
            Node *res = mp[key];
            int resp = res->value;
            deleteNode(res);
            mp.erase(key);
            addNode(res);
            mp[key] = res;
            return resp;
        }
        else
            return -1;
    }
};

int main()
{
}