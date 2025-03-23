#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const int N = 1e6 + 7;

struct Node
{
    ll count;
    int leftNum, rightNum;
    int leftPos, rightPos;
    Node(ll c = 0, int ln = 0, int rn = 0, int lp = 0, int rp = 0)
    {
        count = c;
        leftNum = ln;
        rightNum = rn;
        leftPos = lp;
        rightPos = rp;
    }
} ST[4 * N];

int x[N];
int n;

Node unionNode(Node a, Node b)
{
    if (a.count == 0)
        return b;
    if (b.count == 0)
        return a;
    Node c;
    c.leftNum = a.leftNum;
    if (a.leftNum == a.rightPos - a.leftPos + 1 && x[a.rightPos] + 1 == x[b.leftPos])
        c.leftNum += b.leftNum;
    c.rightNum = b.rightNum;
    if (b.leftNum == b.rightPos - b.leftPos + 1 && x[a.rightPos] + 1 == x[b.leftPos])
        c.rightNum += a.rightNum;
    c.leftPos = a.leftPos;
    c.rightPos = b.rightPos;
    c.count = (a.count + b.count) % MOD;
    if (x[a.rightPos] + 1 == x[b.leftPos])
        c.count = (c.count + 1LL * a.rightNum * b.leftNum) % MOD;
    return c;
}

void build(int id, int left, int right)
{
    if (left == right)
    {
        ST[id] = Node(1, 1, 1, left, right);
        return;
    }
    int m = (left + right) / 2;
    build(id * 2 + 1, left, m);
    build(id * 2 + 2, m + 1, right);
    ST[id] = unionNode(ST[id * 2 + 1], ST[id * 2 + 2]);
}

void update(int id, int left, int right, int p)
{
    if (left == right)
    {
        return;
    }
    int m = (left + right) / 2;
    if (p <= m)
        update(id * 2 + 1, left, m, p);
    else
        update(id * 2 + 2, m + 1, right, p);
    ST[id] = unionNode(ST[id * 2 + 1], ST[id * 2 + 2]);
}

Node get(int id, int left, int right, int u, int v)
{
    if (u <= left && right <= v)
        return ST[id];
    if (left > v || u > right)
        return Node();
    int m = (left + right) / 2;
    return unionNode(get(id * 2 + 1, left, m, u, v),
                     get(id * 2 + 2, m + 1, right, u, v));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    int testcase = 1;
    while (T--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> x[i];
        
        build(0, 0, n - 1);
        int m;
        cin >> m;
        int res = 0;
        while (m--)
        {
            int op;
            cin >> op;
            if (op == 0)
            {
                int p, k;
                cin >> p >> k;
                x[p] = k;
                update(0, 0, n - 1, p);
            }
            else
            {
                int L, R;
                cin >> L >> R;
                res = (res + get(0, 0, n - 1, L, R).count) % MOD;
            }
        }
        cout << "Case #" << testcase++ << ": " << res << '\n';
    }
}