// Code Breaker
// Send Feedback
// Jack Ryan is one of the world’s most famous cryptographers. He has been recently tasked with breaking a code with which our country’s enemies are communicating. He has thought of a possible break in the code, using a very complex system of strings, which thankfully, you have nothing to do with. You are tasked with a little problem. Jack will give you n strings, labelled S1, S2, …. Sn, along with q queries.
// In each query, you have an integer X and a string CODE. You will take into consideration strings S1 to SX. Among these selected strings, consider all the strings such that their longest common prefix with CODE is the maximum possible. Now, from these strings, print the lexicographically smallest one. This would give Jack tremendous insight into further breaking the code. Can you help him?
// Input Format:
// The first line of the input contains a single integer N.
// N lines follow. For each valid i, the i-th of these lines contains Chef's string Si.
// The next line contains a single integer Q.
// The following Q lines describe queries. Each of these lines contains an interger R, followed by a space and a string P
// Constraints:
// 1 ≤ n ≤ 100,000
// 1 ≤ |Si| ≤ 10 for each valid i
// 1 ≤ q ≤ 100,000
// 1 ≤ X ≤ n
// 1 ≤ |CODE| ≤ 10
// Output Format:
// For each query, print a single line containing the string that satisfies the required conditions — the answer to that query.
// Sample Input 1:
// 4
// abcd
// abce
// abcdex
// abcde
// 3
// 3 abcy
// 3 abcde
// 4 abcde
// Sample Output 1:
// abcd
// abcdex
// abcde

#include <bits/stdc++.h>
using namespace std;

typedef struct Query
{
    int r;
    int index;
    string s;
    string answer;
} Query;

bool sort_by_r(const Query &a, const Query &b)
{
    return a.r < b.r;
}

bool sort_by_index(const Query &a, const Query &b)
{
    return a.index < b.index;
}

class Trie
{
#define preset 'a'
public:
    struct Node
    {
        Node *next[26];
        bool is_terminal_node;
        Node()
        {
            for (int i = 0; i < 26; i++)
            {
                next[i] = NULL;
            }
            is_terminal_node = false;
        }
    };
    Node *root;
    Trie()
    {
        root = new Node();
    }

    void insert(string &s)
    {
        Node *node = root;
        for (int i = 0; i < (int)s.length(); i++)
        {
            int ch = s[i] - preset;
            if (node->next[ch] == NULL)
            {
                node->next[ch] = new Node();
            }
            node = node->next[ch];
        }
        node->is_terminal_node = true;
    }

    void find_prefix(const string &s, string &answer)
    {
        Node *node = root;
        for (int i = 0; i < (int)s.length(); i++)
        {
            int ch = s[i] - preset;
            if (node->next[ch] == NULL)
            {
                break;
            }
            else
            {
                answer.push_back(s[i]);
                node = node->next[ch];
            }
        }
        while (node != NULL && !(node->is_terminal_node))
        {
            for (int i = 0; i < 26; i++)
            {
                if (node->next[i] != NULL)
                {
                    answer.push_back(i + preset);
                    node = node->next[i];
                    break;
                }
            }
        }
    }

    void solve(vector<string> &words, vector<Query> &queries)
    {
        sort(queries.begin(), queries.end(), sort_by_r);
        int index = 0;
        for (Query &query : queries)
        {
            int r = query.r - 1;
            while (index <= r)
            {
                insert(words[index++]);
            }
            find_prefix(query.s, query.answer);
        }
        sort(queries.begin(), queries.end(), sort_by_index);
        for (Query &query : queries)
        {
            cout << query.answer << '\n';
        }
    }
};

int main()
{

    int N = 0;
    cin >> N;
    vector<string> words(N);
    for (int i = 0; i < N; i++)
    {
        cin >> words[i];
    }
    int q = 0;
    cin >> q;
    vector<Query> queries(q);
    for (int i = 0; i < q; i++)
    {
        cin >> queries[i].r >> queries[i].s;
        queries[i].index = i;
    }
    Trie trie;
    trie.solve(words, queries);
    return 0;
}