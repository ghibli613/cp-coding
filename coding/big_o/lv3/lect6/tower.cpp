#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n;
vector<pair<int , pii>> blocks; 
vector<pii> A;

void LIS()
{
    vector<int> lis, lis_index;
    vector<int> dp(n);
    
    for(int i = 0; i < n; i++) dp[i] = A[i].second;

    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(A[j].first <= A[i].first && dp[i] < dp[j] + A[i].second)
                dp[i] = dp[j] + A[i].second;
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) ans = max(ans, dp[i]);

    cout << ans;
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a, b, g; cin >> a >> b >> g;
        if(b > a) swap(a, b);
        blocks.push_back({a, {b, g}});
    }

    sort(blocks.begin(), blocks.end());

    for(int i = 0; i < n; i++)
    {
        A.push_back(blocks[i].second);
    }

    LIS();

    return 0;
}