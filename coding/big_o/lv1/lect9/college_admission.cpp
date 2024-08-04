#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n, x = 0, pre = 0; cin >> n;
    stack<int> missed;
    vector<bool> available(n + 1);
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        if(pre < x)
        {
            cout << x << ' ';
            while(++pre < x)
            {
                missed.push(pre);
            }
        }
        available[x] = true;
        while(!missed.empty() && available[missed.top()])
        {
            cout << missed.top() << ' ';
            missed.pop();
        }
    }
    while (!missed.empty())
    {
        cout << missed.top() << " ";
        missed.pop();
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