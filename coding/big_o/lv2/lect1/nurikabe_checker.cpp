#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

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
        if(Rank[pu] > Rank[pv]) parent[pv] = pu;
        else if(Rank[pu] < Rank[pv]) parent[pu] = pv;
        else
        {
            parent[pv] = pu;
            Rank[pu]++;
        }
        return true;
    }
};

void solve(int test)
{
    int n, m, k; cin >> n >> m >> k;
    vector<vector<bool>> isWhite(n, vector<bool>(m));
    vector<int> row(k), col(k), number(k);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            char ch; cin >> ch;
            if(ch == '.') isWhite[i][j] = true;
            else isWhite[i][j] = false;
        }

    bool isCorrect = true;

    // Check 1
    for(int i = 0; i < k; i++)
    {
        cin >> row[i] >> col[i] >> number[i];
        row[i]--; col[i]--;
        if(!isWhite[row[i]][col[i]]) isCorrect = false;
    }

    DisjointSet djs(n * m);
    vector<int> parents(n * m);
    vector<int> setCount(n * m);
    vector<bool> taken(n * m);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            if(i + 1 < n && isWhite[i][j] == isWhite[i + 1][j])
                djs.unionSet(i * m + j, (i + 1) * m + j);
            if(j + 1 < m && isWhite[i][j] == isWhite[i][j + 1])
                djs.unionSet(i * m + j, i * m + j + 1);
        }

    for(int i = 0; i < n * m; i++)
    {
        parents[i] = djs.findSet(i);
        setCount[parents[i]] += 1;
    }

    // Check 4
    for (int i = 0; i < n - 1; i++) 
        for (int j = 0; j < m - 1; j++)
            if (!isWhite[i][j] && !isWhite[i + 1][j] && !isWhite[i][j + 1] && !isWhite[i + 1][j + 1]) 
            {
                isCorrect = false;
                break;
            }
    
    // Check 2
    for (int i = 0; i < k; i++) 
    {
        int index = row[i] * m + col[i];
        if (taken[parents[index]]) 
        {
            isCorrect = false;
            break;
        } 
        else taken[parents[index]] = true;
        
        if (setCount[parents[index]] != number[i]) 
        {
            isCorrect = false;
            break;
        }
    }
    
    int blackRoot = -1;
    for (int r = 0; r < n; r++) 
    {
        for (int c = 0; c < m; c++) 
        {
            int index = r * m + c;
            if (isWhite[r][c]) {
                if (!taken[parents[index]]) 
                {
                    isCorrect = false;
                    break;
                }
            } else 
            {
                if (blackRoot == -1) blackRoot = parents[index];
                if (parents[index] != blackRoot) {
                    isCorrect = false;
                    break;
                }
            }
        }
    }

    cout << "Puzzle #" << test << ": ";
    if (isCorrect) cout << "Correct\n";
    else cout << "Incorrect\n";
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