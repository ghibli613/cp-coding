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
            break;
        cur = cur->child[cur_bit];
        if(!i) return;
    }
    cur = root;
    for(int i = 30; i >= 0; i--)
    {
        int cur_bit = (x >> i) & 1;
        if(cur->child[cur_bit] == nullptr)
            cur->child[cur_bit] = new Node();
        cur = cur->child[cur_bit];
        cur->count++;
    }
}

int getCnt(Node* cur)
{
    if(cur == nullptr) 
        return 0;
    else return cur->count;
}

int search(Node* root, int x)
{
    Node* cur = root;
    int mex = 0;
    for(int i = 30; i >= 0; i--)
    {
        int cur_bit = (x >> i) & 1;
        if(getCnt(cur->child[cur_bit]) < (1 << i))
            cur = cur->child[cur_bit];
        else
        {
            cur = cur->child[cur_bit ^ 1];
            mex |= (1 << i);
        }
        if(cur == nullptr)
            return mex;
    }
    return mex;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    Node* root = new Node();
    for(int i = 0; i < n; i++)
    {
        int ai; cin >> ai;
        add(root, ai);
    }

    int x = 0;
    while(m--)
    {
        int y; cin >> y;
        x ^= y;
        cout << search(root, x) << '\n';
    }

    return 0;
}