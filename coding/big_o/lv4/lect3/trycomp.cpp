#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 26;

struct Node
{
    Node* child[MAX];
    int count;
    int maxx;

    Node()
    {
        count = 0;
        maxx = 0;
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
    }
    cur->count++;
    int tmp = cur->count;

    cur = root;
    for(char ch : s)
    {
        int c = ch - 'a';
        cur = cur->child[c];
        cur->maxx = max(cur->maxx, tmp);
    }
}

void search(Node* root, string s)
{
    Node* cur = root;
    for(char ch : s)
    {
        int c = ch - 'a';
        if(cur->child[c] == nullptr)
        {
            cout << -1 << '\n';
            return;
        }
        cur = cur->child[c];
    }
    cout << s;
    while(cur->count != cur->maxx)
    {
        for(int i = 0; i < 26; i++)
        {
            if(cur->child[i] != nullptr && cur->child[i]->maxx == cur->maxx)
            {
                cout << (char)(i + 'a');
                cur = cur->child[i];
                break;
            }
        }
    }
    cout << ' ' << cur->count << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    Node *root = new Node();
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        add(root, s);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        string s;
        cin >> s;
        search(root, s);
    }

    return 0;
}