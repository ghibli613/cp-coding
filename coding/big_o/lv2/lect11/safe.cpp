#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

int n, m, ans = 0;
vector<string> s;
vector<int> t;
vector<bool> pos(35);

void check()
{
    string password = "";
    for(int i = 0; i < n; i++)
    {
        if(pos[i])
            password.push_back(s[0][i]);
        else password.push_back('0' + '1' - s[0][i]);
    }
    for(int i = 1; i < m; i++)
    {
        int correct = 0; 
        for(int j = 0; j < n; j++) correct += (s[i][j] == password[j]);
        if(correct != t[i]) return;
    }
    ans += 1;
}

void choose(int st, int cnt)
{
    if(!cnt)
    {
        check();
        return;
    }
    for(int i = st; i <= n - cnt; i++)
    {
        pos[i] = 1;
        choose(i + 1, cnt - 1);
        pos[i] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    t.assign(m, 0);
    s.assign(m, "");

    for(int i = 0; i < m; i++) cin >> s[i] >> t[i];

    choose(0, t[0]);
    cout << ans;

    return 0;
}