#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int n, a[N], last[N], preLast[N];

struct SegmentTree
{
    struct SNode
    {
        int val, lazy, idx;
        SNode() { val = lazy = 0; }
        SNode(int _val, int _lazy, int _idx)
        {
            val = _val;
            lazy = _lazy;
            idx = _idx;
        }
    } node[4 * N];

    void push(int id)
    {
        int &t = node[id].lazy;

        node[id << 1].val += t;
        node[id << 1].lazy += t;

        node[id << 1 | 1].val += t;
        node[id << 1 | 1].lazy += t;

        t = 0;
    }

    SNode join(SNode &A, SNode &B)
    {
        SNode res;

        if (A.val <= B.val)
        {
            res.val = A.val;
            res.idx = A.idx;
        }
        else
        {
            res.val = B.val;
            res.idx = B.idx;
        }

        return res;
    }

    void reset()
    {
        for (int i = 1; i <= 4 * n; i++)
            node[i].val = node[i].lazy = 0;
    }

    void build(int id = 1, int low = 1, int high = n)
    {
        if (low > high)
            return;
        if (low == high)
        {
            node[id].lazy = 0;
            node[id].val = 0;
            node[id].idx = low;
            return;
        }
        int mid = (low + high) >> 1;
        build(id << 1, low, mid);
        build(id << 1 | 1, mid + 1, high);
        node[id] = join(node[id << 1], node[id << 1 | 1]);
    }

    void update(int l, int r, int w, int id = 1, int low = 1, int high = n)
    {
        if (low > r || high < l)
            return;
        if (l <= low && high <= r)
        {
            node[id].val += w;
            node[id].lazy += w;
            return;
        }
        push(id);
        int mid = (low + high) >> 1;
        update(l, r, w, id << 1, low, mid);
        update(l, r, w, id << 1 | 1, mid + 1, high);
        node[id] = join(node[id << 1], node[id << 1 | 1]);
    }

    SNode DUMP = SNode(n + 1, 0, 0);
    SNode get(int l, int r, int id = 1, int low = 1, int high = n)
    {
        if (low > r || high < l)
            return DUMP;
        if (l <= low && high <= r)
            return node[id];
        push(id);
        int mid = (low + high) >> 1;
        SNode lef = get(l, r, id << 1, low, mid);
        SNode rig = get(l, r, id << 1 | 1, mid + 1, high);
        return join(lef, rig);
    }

} IT;

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        for (int i = 1; i <= n; i++)
        {
            last[a[i]] = 0;
            preLast[a[i]] = -1;
        }

        IT.reset();

        IT.build();

        int resRarity = n + 1, resLen = 1;
        for (int i = 1; i <= n; i++)
        {
            if (preLast[a[i]] != -1)
                IT.update(preLast[a[i]] + 1, last[a[i]], -1);
            IT.update(last[a[i]] + 1, i, 1);

            SegmentTree::SNode getNode = IT.get(1, i);
            int rarity = getNode.val;
            int len = i - getNode.idx + 1;

            if (rarity < resRarity)
            {
                resRarity = rarity;
                resLen = len;
            }
            if (resRarity == rarity)
                resLen = max(resLen, len);

            preLast[a[i]] = last[a[i]];
            last[a[i]] = i;
        }

        cout << resRarity << ' ' << resLen << '\n';
    }

    return 0;
}