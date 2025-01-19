#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Node
{
    Node* child[2];
    int count;

    Node()
    {
        count = 0;
        child[0] = child[1] = nullptr;
    }
};

void add(Node* root, int x)
{
    Node* cur = root;
    for(int i = 30; i >= 0; i--)
    {
        int cur_bit = (x >> i) & 1;
        if(cur->child[cur_bit] == nullptr)
            cur->child[cur_bit] = new Node();
        cur = cur->child[cur_bit];
    }
    ++cur->count;
}

bool isEmpty(Node& temp)
{
    for(int i = 0; i < 2; i++)
        if(temp.child[i] != nullptr)
            return false;
    return true;
}

bool remove(Node* root, int x, int depth = 0)
{
    if(!root)
    {
        return false;
    }
    if(depth == 31)
    {
        if(root->count > 0)
        {
            root->count--;
            return true;
        }
        return false;
    }
    
    int c = (x >> (30 - depth)) & 1;
    // cout << c;
    if(!root->child[c])
    {
        return false;
    }
    bool isRemoved = remove(root->child[c], x, depth + 1);
    Node& temp = *(root->child[c]);
    if(isRemoved && temp.count == 0 && isEmpty(temp))
    {
        delete root->child[c];
        root->child[c] = nullptr;
    }
    return isRemoved;
}

int getMax(Node* root, int x)
{
    Node* cur = root;
    int res = 0;
    for(int i = 30; i >= 0; i--)
    {
        int cur_bit = (x >> i) & 1;
        if(cur->child[cur_bit ^ 1] != nullptr)
        {
            cur = cur->child[cur_bit ^ 1];
            res |= 1 << i;
        }
        else
        {
            cur = cur->child[cur_bit];
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Node* root = new Node;
    add(root, 0);
    int q; cin >> q;
    while(q--)
    {
        char t; cin >> t;
        int x; cin >> x;
        if(t == '+')
        {
            add(root, x);
        }
        else if(t == '-')
        {
            remove(root, x);
        }
        else
        {
            cout << getMax(root, x) << '\n';
        }
    }

    return 0;
}