#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Node
{
    int cnt;
    Node *cd[26];
    Node()
    {
        cnt = 0;
        fill(cd, cd + 26, nullptr);
    };
};

void add(Node *root, const string &s)
{
    Node *cur = root;
    for (char c : s)
    {
        int x = c - 'a';
        if (!cur->cd[x])
            cur->cd[x] = new Node;
        cur = cur->cd[x];
        ++cur->cnt;
    }
}

int search(Node *root, const string &s)
{
    Node *cur = root;
    int m = 0, n = s.length();
    for (char c : s)
    {
        int x = c - 'a';
        if (!cur->cd[x])
            return m;
        ++m;
        cur = cur->cd[x];
        n = min(n, cur->cnt) - 1;
        if (!n)
            return m;
    }
    return m;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    while(cin >> n)
    {
        cin >> m;
        vector<string> a(n);

        Node* root = new Node;
        for (string &t : a)
            cin >> t;
        for (int i = 0; i < m; i++)
        {
            string s; cin >> s;
            add(root, s);
        }
            
        int moves = 0;
        for (string &t : a)
            moves += search(root, t);
        cout << moves << '\n';
    }

    return 0;
}