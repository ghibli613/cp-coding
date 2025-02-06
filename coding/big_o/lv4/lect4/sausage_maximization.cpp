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
        fill(child, child + 2, nullptr);
    }
};

void add(Node* root, ll x)
{
    Node* cur = root;
    for(int i = 40; i >= 0; i--)
    {
        int bit = (x >> i) & 1ll;
        if(cur->child[bit] == nullptr)
            cur->child[bit] = new Node();
        cur = cur->child[bit];
    }
}

ll search(Node* root, ll x)
{
    Node* cur = root;
    ll res = 0;
    for(int i = 40; i >= 0; i--)
    {
        int bit = (x >> i) & 1ll;
        if(cur->child[bit ^ 1] != nullptr)
        {
            bit ^= 1;
            res |= (1ll << i);
        }
        cur = cur->child[bit];
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    ll prefix = 0, suffix = 0;
    vector<ll> a(n);
    for(ll &x : a)
    {
        cin >> x;
        suffix ^= x;
    }

    ll ans = suffix;
    Node *root = new Node;
    add(root, 0);
    for(ll x : a)
    {
        suffix ^= x;
        prefix ^= x;
        add(root, prefix);
        ans = max(ans, search(root, suffix));
    }
    cout << ans << '\n';

    return 0;
}