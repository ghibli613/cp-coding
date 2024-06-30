#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n = 0; cin >> n;
    vector<int> x(n), reach (n, 0), to(n, 0);
    for(int i = 0; i < n; i++) cin >> x[i];   
    sort(x.begin(), x.end());
    reach[1]++; reach[n - 2]++;
    to[0] = 1; to[n - 1] = n - 2;
    vector<int> gaps(n-1);
    for(int i = 0; i < n - 1; i++) gaps[i] = x[i + 1] - x[i];
    
    for(int i = 1; i < n-1; i++)
    {
        if(x[i] - x[i - 1] <= x[i + 1] - x[i])
        {
            reach[i - 1]++;
            to[i] = i - 1;
        }
        else
        {
            reach[i + 1]++;
            to[i] = i + 1;
        }
    }
    int num_islands = 0;
    if(reach[0] == 1 && reach[1] == 1 && to[2] != 1) num_islands++;
    if (reach[n - 1] == 1 && reach[n - 2] == 1 && to[n - 3] != n - 2)
        num_islands++;

    for (int i = 2; i < n - 3; i++) 
    {
        if (reach[i] == 1 && reach[i + 1] == 1 && to[i + 2] != i + 1 &&
            to[i - 1] != i) {
            num_islands++;
        }
    }

    cout << count(reach.begin(), reach.end(), 0) + num_islands << endl;
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