#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 26;

struct Node
{
    Node* child[MAX];
    int count;

    Node()
    {
        count = 0;
        fill(child, child + MAX, nullptr);
    }
};

void add(Node* root, string s)
{
    Node* cur = root;
    for(char ch : s)
    {
        int c = ch - 'a';
        if(cur->child[c] == nullptr)
            cur->child[c] = new Node();
        cur = cur->child[c];
        cur->count++;
    }
}

int search(Node* root, string s)
{
    Node* cur = root;
    for(char ch : s)
    {
        int c = ch - 'a';
        if(cur->child[c] == nullptr)
            return 0;
        cur = cur->child[c];
    }
    return cur->count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    Node* root = new Node();
    for(int i = 0; i < n; i++)
    {
        string s; cin >> s;
        add(root, s);
    }

    for(int i = 0; i < q; i++)
    {
        string s; cin >> s;
        cout << search(root, s) << '\n';
    }

    return 0;
}