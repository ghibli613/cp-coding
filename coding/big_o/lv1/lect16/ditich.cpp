#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

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

int d[2] = {-1, 1};
int n, m;
vector<vector<char>> matrix;
vector<vector<int>> ans;
int tmp;

void dfs(int i, int j)
{
    matrix[i][j] = '*';
    for(int dx : d)
    {
        if(i + dx < 0 || i + dx >= n || matrix[i + dx][j] == '*') continue;
        if(matrix[i + dx][j] == '#') tmp++;
        else dfs(i + dx, j);
    }
    for(int dy : d)
    {
        if(j + dy < 0 || j + dy >= m || matrix[i][j + dy] == '*') continue;
        if(matrix[i][j + dy] == '#') tmp++;
        else dfs(i, j + dy);
    }
}

void dfs1(int i, int j)
{
    ans[i][j] = tmp;
    matrix[i][j] = 'o';
    for(int dx : d)
    {
        if(i + dx < 0 || i + dx >= n || matrix[i + dx][j] == '#' || matrix[i + dx][j] == 'o') continue;
        else dfs1(i + dx, j);
    }
    for(int dy : d)
    {
        if(j + dy < 0 || j + dy >= m || matrix[i][j + dy] == '#' || matrix[i][j + dy] == 'o') continue;
        else dfs1(i, j + dy);
    }
}

void solve()
{
    cin >> n >> m;
    matrix.assign(n, vector<char> (m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }

    ans.assign(n, vector<int>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            if(matrix[i][j] == '#') ans[i][j] = -1;
            else if(matrix[i][j] == '.')
            {
                tmp = 0;
                dfs(i, j);
                dfs1(i, j);
                // cout << tmp << ' ';
            }
        }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while(t--)
        solve();

    return 0;
}