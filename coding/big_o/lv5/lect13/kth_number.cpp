#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val, cnt;
    Node *left, *right;

    Node(int _val, int _cnt, Node *_left, Node *_right)
    {
        val = _val;
        cnt = _cnt;
        left = _left;
        right = _right;
    }
};

Node *rootVer[100005];
int nVer = 0;

Node *build(int l, int r)
{
    if (l == r)
        return new Node(0, 0, NULL, NULL);

    int mid = (l + r) / 2;

    Node *curNode = new Node(
        0, // val
        0, // cnt
        build(l, mid),
        build(mid + 1, r));

    return curNode;
}

Node *update(Node *oldNode, int l, int r, int u, int val)
{
    if (l == r)
        return new Node(val, 1, NULL, NULL);

    int mid = (l + r) / 2;

    Node *curNode = new Node(0, 0, NULL, NULL);

    if (u <= mid)
    {
        curNode->left = update(oldNode->left, l, mid, u, val);
        curNode->right = oldNode->right;
    }
    else
    {
        curNode->left = oldNode->left;
        curNode->right = update(oldNode->right, mid + 1, r, u, val);
    }

    if (curNode->left)
        curNode->cnt += curNode->left->cnt;
    if (curNode->right)
        curNode->cnt += curNode->right->cnt;

    return curNode;
}

int get(Node *node, int l, int r, int k)
{
    if (l == r)
        return node->val;

    int mid = (l + r) / 2;

    if (node->left->cnt >= k)
        return get(node->left, l, mid, k);
    else
        return get(node->right, mid + 1, r, k - node->left->cnt);
}

const int MAXVAL = 1e5;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, Q;
    cin >> n >> Q;
    vector<vector<int>> pos(MAXVAL + 1, vector<int>());
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        pos[x].push_back(i);
    }
    rootVer[0] = build(1, n);

    vector<int> verX(MAXVAL + 1);
    for (int x = MAXVAL; x >= 1; x--)
    {
        for (int i : pos[x])
        {
            nVer++;
            rootVer[nVer] = update(rootVer[nVer - 1], 1, n, i, x);
        }

        verX[x] = nVer;
    }

    while (Q--)
    {
        int L, K;
        cin >> L >> K;

        cout << get(rootVer[verX[L]], 1, n, K) << '\n';
    }

    return 0;
}