#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

int n, m, ans;
vector<bool> rowState, colState, rowAns, colAns;
vector<vector<int>> a;

int countCol(int j)
{
    int res = 0;
    for(int i = 0; i < n; i++)
        res += a[i][j];
    return res;
}

void findMaxState()
{
    int currLight = 0;
    colState = vector<bool>(m, 0);
    for(int j = 0; j < m; j++)
    {
        int cnt = countCol(j);
        if(cnt < n - cnt)
        {
            colState[j] = true;
            currLight += n - cnt;
        }
        else
        {
            currLight += cnt;
        }
    }
    if(currLight > ans)
    {
        ans = currLight;
        rowAns = rowState;
        colAns = colState;
    }
}

void backtracking(int i)
{
    if(i == n)
    {
        findMaxState();
        return;
    }
    backtracking(i + 1);
    rowState[i] = 1 - rowState[i];
    for(int j = 0; j < m; j++) a[i][j] = 1 - a[i][j];
    backtracking(i + 1);
}

int numberOfAction()
{
    int ans = 0;
    for(int i = 0; i < n; i++) ans += rowAns[i];
    for(int j = 0; j < m; j++) ans += colAns[j];
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    rowState.assign(n, 0);
    a.assign(n, vector<int>(m));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    
    ans = 0;
    backtracking(0);

    cout << ans << '\n';
    cout << numberOfAction() << '\n';

    for(int i = 0; i < n; i++)
    {
        if(rowAns[i]) cout << 'R' << i + 1 << '\n';
    }
    for(int j = 0; j < m; j++)
        if(colAns[j]) cout << 'C' << j + 1 << '\n';

    return 0;
}