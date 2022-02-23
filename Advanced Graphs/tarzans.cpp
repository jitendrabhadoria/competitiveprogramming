#include <bits/stdc++.h>
#define NIL -1
using namespace std;

vector<vector<int>> components;

class Graph
{
    int V;
    list<int> *adj;

    // A Recursive DFS based function used by SCC()
    void SCCUtil(int u, int disc[], int low[], stack<int> *st, bool stackMember[])
    {
        // A static variable is used for simplicity, we can avoid use
        // of static variable by passing a pointer.
        static int time = 0;

        // Initialize discovery time and low value
        disc[u] = low[u] = ++time;
        st->push(u);
        stackMember[u] = true;

        // Go through all vertices adjacent to this
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = *i; // v is current adjacent of 'u'

            // If v is not visited yet, then recur for it
            if (disc[v] == -1)
            {
                SCCUtil(v, disc, low, st, stackMember);

                // Check if the subtree rooted with 'v' has a
                // connection to one of the ancestors of 'u'
                // Case 1 (per above discussion on Disc and Low value)
                low[u] = min(low[u], low[v]);
            }

            // Update low value of 'u' only of 'v' is still in stack
            // (i.e. it's a back edge, not cross edge).
            // Case 2 (per above discussion on Disc and Low value)
            else if (stackMember[v] == true)
                low[u] = min(low[u], disc[v]);
        }

        // head node found, pop the stack and print an SCC
        int w = 0; // To store stack extracted vertices
        vector<int> temp;
        if (low[u] == disc[u])
        {
            while (st->top() != u)
            {
                w = (int)st->top();
                temp.push_back((w));
                stackMember[w] = false;
                st->pop();
            }
            w = (int)st->top();
            temp.push_back(w);
            stackMember[w] = false;
            st->pop();
        }
        components.push_back(temp);
    }

public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    } // Constructor
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    } // function to add an edge to graph
    void SCC()
    {
        int *disc = new int[V];
        int *low = new int[V];
        bool *stackMember = new bool[V];
        stack<int> *st = new stack<int>();

        // Initialize disc and low, and stackMember arrays
        for (int i = 0; i < V; i++)
        {
            disc[i] = NIL;
            low[i] = NIL;
            stackMember[i] = false;
        }

        // Call the recursive helper function to find strongly
        // connected components in DFS tree with vertex 'i'
        for (int i = 0; i < V; i++)
            if (disc[i] == NIL)
                SCCUtil(i, disc, low, st, stackMember);
    } // prints strongly connected components
};

// Driver program to test above function
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        Graph g1(n);
        for (int i = 0; i < m; i++)
        {
            int a, b;
            g1.addEdge(a, b);
            g1.addEdge(b, a);
        }
        g1.SCC();

        for (int i = 0; i < components.size(); i++)
        {
            for (int j = 0; j < components[i].size(); j++)
            {
                cout << components[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
