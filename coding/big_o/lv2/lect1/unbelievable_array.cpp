#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#define dbg(...) cerr<<__func__<<":"<<__LINE__<<" [" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__);

const int MOD = 1000000007;

int set_of_color[100001], set_to_color[100001];

struct DisjointSet
{
    vector<int> parent, Rank;
    DisjointSet(int n): parent(n + 1), Rank(n + 1, 0)
    {
        for (int i=1; i<=n; i++) parent[i] = i;
    }
    int findSet(int u)
    {
        if (parent[u] != u) parent[u] = findSet(parent[u]);
        return parent[u];
    }
    bool unionSet(int u, int v)
    {
        int pu = findSet(u), pv = findSet(v);
        if(pu == pv) return false;
        if(Rank[pu] > Rank[pv]) 
        {
            parent[pv] = pu;
        }
        else if(Rank[pu] < Rank[pv]) 
        {
            parent[pu] = pv;
        }
        else
        {
            parent[pv] = pu;
            Rank[pu]++;
        }
        return true;
    }
};

void solve(int tc)
{
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    DisjointSet s(100000);
    for(int i = 1; i <= 100000; i++) set_of_color[i] = -1, set_to_color[i] = -1;

    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(set_of_color[a[i]] == -1)
        {
            set_of_color[a[i]] = i;
            set_to_color[i] = a[i];
        }
        else
        {
            int x = set_of_color[a[i]];
            s.unionSet(x, i);
            x = s.findSet(i);
            set_of_color[a[i]] = x;
            set_to_color[x] = a[i];
        }
    }

    cout << "Case " << tc << ":\n";
    for(int i = 0; i < q; i++)
    {
        int t; cin >> t;
        if(t == 1)
        {
            int x, y; cin >> x >> y;
            if(set_of_color[x] != -1)
            {
                if(set_of_color[y] != -1)
                {
                    s.unionSet(set_of_color[x], set_of_color[y]);
                    int sx = s.findSet(set_of_color[x]);
                    set_of_color[x] = -1;
                    set_of_color[y] = s.findSet(sx);
                    set_to_color[set_of_color[y]] = y;
                }
                else
                {
                    int sx = s.findSet(set_of_color[x]);
                    set_of_color[x] = -1;
                    set_of_color[y] = sx;
                    set_to_color[sx] = y;
                }
            }
        }
        else
        {
            int idx; cin >> idx;
            cout << set_to_color[s.findSet(idx)] << '\n';
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    for(int tc = 1; tc <= t; tc++)
        solve(tc);

    return 0;
}