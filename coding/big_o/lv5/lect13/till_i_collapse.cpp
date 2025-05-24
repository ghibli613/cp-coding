#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int cnt;
    Node *left, *right;

    Node(int _cnt, Node *_left, Node *_right)
    {
        cnt = _cnt;
        left = _left;
        right = _right;
    }
};

Node *rootVer[200005];
int nVer = 0;

Node *build(int l, int r)
{
    if (l == r)
        return new Node(0, NULL, NULL);

    int mid = (l + r) / 2;

    Node *curNode = new Node(
        0, // cnt
        build(l, mid),
        build(mid + 1, r));

    return curNode;
}

Node *update(Node *oldNode, int l, int r, int u, int val)
{
    if (l == r)
        return new Node(val, NULL, NULL);

    int mid = (l + r) / 2;

    Node *curNode = new Node(0, NULL, NULL);

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
    {    
        if(node->cnt > k) return l - 1;
        return l;
    }

    int mid = (l + r) / 2;

    if (node->left->cnt > k)
        return get(node->left, l, mid, k);
    else
        return get(node->right, mid + 1, r, k - node->left->cnt);
}

int n, a[100005];
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
 
    rootVer[0] = build(1, n);
 
    vector<int> nearestPos(n + 1, -1);
    vector<int> verIndex(n + 1);
    for (int i = n; i >= 1; i--)
    {
        if (nearestPos[a[i]] != -1)
        {
            nVer++;
            rootVer[nVer] = update(rootVer[nVer - 1], 1, n, nearestPos[a[i]], 0);
        }
 
        nVer++;
        rootVer[nVer] = update(rootVer[nVer - 1], 1, n, i, 1);
 
        nearestPos[a[i]] = i;
 
        verIndex[i] = nVer;
    }
 
    for (int k = 1; k <= n; k++)
    {
        int cur = 0;
        int cntPart = 0;
        while (cur < n)
        {
            cur = get(rootVer[verIndex[cur + 1]], 1, n, k);
            cntPart++;
        }
 
        cout << cntPart << ' ';
    }
 
    return 0;
}