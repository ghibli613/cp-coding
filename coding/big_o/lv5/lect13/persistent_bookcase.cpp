#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int N = 1e5 + 7;

struct Node
{
    int books, no_books;
    bool is_inver;
    Node *left, *right;

    Node()
    {
        books = no_books = is_inver = 0;
        left = right = nullptr;
    }

    Node(Node *v)
    {
        books = v->books;
        no_books = v->no_books;
        is_inver = v->is_inver;
        left = v->left;
        right = v->right;
    }
};

Node *build(int L, int R)
{
    Node *root = new Node;
    if (L == R)
    {
        root->no_books = 1;
        root->books = 0;
        return root;
    }

    int M = (L + R) / 2;
    root->left = build(L, M);
    root->right = build(M + 1, R);

    root->no_books = root->left->no_books + root->right->no_books;
    root->books = 0;

    return root;
}

int sum(Node *n)
{
    if (n->is_inver)
        return n->no_books;
    return n->books;
}

int sum_no(Node *n)
{
    if (n->is_inver)
        return n->books;

    return n->no_books;
}

void updateAdd(Node *&cur, int L, int R, int pos, int val)
{
    if (L == R)
    {
        if (val == 1)
        {
            cur->books = 1;
            cur->no_books = 0;
        }
        else
        {
            cur->books = 0;
            cur->no_books = 1;
        }
        cur->is_inver = 0;
        return;
    }

    cur->left = new Node(cur->left);
    cur->left->is_inver ^= cur->is_inver;
    cur->right = new Node(cur->right);
    cur->right->is_inver ^= cur->is_inver;
    cur->is_inver = 0;

    int M = (L + R) / 2;
    if (pos <= M)
    {
        updateAdd(cur->left, L, M, pos, val);
    }
    else
    {
        updateAdd(cur->right, M + 1, R, pos, val);
    }

    cur->books = sum(cur->left) + sum(cur->right);
    cur->no_books = sum_no(cur->left) + sum_no(cur->right);
}

void updateInver(Node *&cur, int L, int R, int row_l, int row_r)
{

    if (L > row_r || R < row_l)
        return;
    if (L >= row_l && R <= row_r)
    {
        cur->is_inver ^= 1;
        return;
    }

    cur->left = new Node(cur->left);
    cur->left->is_inver ^= cur->is_inver;
    cur->right = new Node(cur->right);
    cur->right->is_inver ^= cur->is_inver;
    cur->is_inver = 0;

    int M = (L + R) / 2;
    updateInver(cur->left, L, M, row_l, row_r);
    updateInver(cur->right, M + 1, R, row_l, row_r);

    cur->books = sum(cur->left) + sum(cur->right);
    cur->no_books = sum_no(cur->left) + sum_no(cur->right);
}

Node *tr[100007];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;

    vector<pair<int, int>> shelfs(n + 1);
    int id = 1;
    for (int i = 1; i <= n * m; i += m)
    {
        shelfs[id].first = i;
        shelfs[id++].second = i + m - 1;
    }

    tr[0] = build(1, n * m);
    for (int i = 1; i <= q; i++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x, y;
            cin >> x >> y;
            tr[i] = new Node(tr[i - 1]);
            updateAdd(tr[i], 1, n * m, (x - 1) * m + y, 1);
        }
        else if (t == 2)
        {
            int x, y;
            cin >> x >> y;
            tr[i] = new Node(tr[i - 1]);
            updateAdd(tr[i], 1, n * m, (x - 1) * m + y, 0);
        }
        else if (t == 3)
        {
            int row;
            cin >> row;
            tr[i] = new Node(tr[i - 1]);
            updateInver(tr[i], 1, n * m, shelfs[row].first, shelfs[row].second);
        }
        else if (t == 4)
        {
            int k;
            cin >> k;
            tr[i] = tr[k];
        }
        cout << sum(tr[i]) << '\n';
    }

    return 0;
}