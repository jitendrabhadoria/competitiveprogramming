#include <bits/stdc++.h>
using namespace std;

class DSNode
{
public:
    int data;
    DSNode *parent;
    int rank;
};

class DisjointSet
{
private:
    map<int, DSNode *> hash;

    DSNode *searchInSetHelper(DSNode *node)
    {

        if (node == node->parent)
        {
            return node;
        }
        node->parent = searchInSetHelper(node->parent);
        return node->parent;
    }

public:
    void initializeSet(int data)
    {
        DSNode *node = new DSNode();
        node->data = data;
        node->parent = node;
        node->rank = 0;
        hash[data] = node;
    }

    void Union(int data1, int data2)
    {

        DSNode *node1 = hash[data1];
        DSNode *node2 = hash[data2];

        DSNode *parent1 = searchInSetHelper(node1);
        DSNode *parent2 = searchInSetHelper(node2);

        if (parent1->data == parent2->data)
        {
            return;
        }

        if (parent1->rank >= parent2->rank)
        {
            if (parent1->rank == parent2->rank)
            {
                parent1->rank = parent1->rank + 1;
            }
            parent2->parent = parent1;
        }
        else
        {
            parent1->parent = parent2;
        }
    }

    int searchInSet(int data)
    {
        return searchInSetHelper(hash[data])->data;
    }
};

int main()
{

    DisjointSet ds;

    ds.initializeSet(0);
    ds.initializeSet(1);
    ds.initializeSet(2);
    ds.initializeSet(3);
    ds.initializeSet(4);
    ds.initializeSet(5);
    ds.initializeSet(6);

    ds.Union(0, 1);
    ds.Union(1, 2);
    ds.Union(3, 4);
    ds.Union(2, 4);
    ds.Union(5, 6);
    ds.Union(4, 6);
    ds.Union(0, 1);

    cout << ds.searchInSet(0) << endl;
    cout << ds.searchInSet(1) << endl;
    cout << ds.searchInSet(2) << endl;
    cout << ds.searchInSet(3) << endl;
    cout << ds.searchInSet(4) << endl;
    cout << ds.searchInSet(5) << endl;
    cout << ds.searchInSet(6) << endl;

    return 0;
}