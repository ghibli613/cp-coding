#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(int tc)
{
    int n; cin >> n; 
    vector<ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    vector<ll> first, second;
    
    for(int i = 0; i < n; i++)
    {
        if(i % 2 == 0)
            first.push_back(v[i]);
        else
            second.push_back(v[i]);
    }
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());

    vector<ll> trouble_sorted_v(n);
    for(int i = 0; i < (int)first.size(); i++)
    {
        trouble_sorted_v[i * 2] = first[i];
    }
    for(int i = 0; i < (int)second.size(); i++)
    {
        trouble_sorted_v[i * 2 + 1] = second[i];
    }

    for(int i = 0; i < n - 1; i++)
    {
        if(trouble_sorted_v[i] > trouble_sorted_v[i + 1])
        {
            cout << "Case #" << tc + 1 << ": " << i << '\n';
            return;
        }
    }
    cout << "Case #" << tc + 1 << ": OK\n"; 
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    for(int tc = 0; tc < t; tc++)
        solve(tc);

    return 0;
}