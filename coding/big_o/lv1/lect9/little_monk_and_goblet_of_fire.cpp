#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    queue<int> q[4];
    queue<int> tour;
    
    for(int i = 0; i < n; i++)
    {
        char t; cin >> t;
        if(t == 'E')
        {
            int x, y; cin >> x >> y;
            q[x - 1].push(y);
            queue<int> tmp;
            bool check = false;
            while(!tour.empty())
            {
                tmp.push(tour.front());
                if(x - 1 == tour.front()) check = true;
                tour.pop();
            }
            tour = tmp;
            if(!check) tour.push(x - 1);
        }
        else
        {
            cout << tour.front() + 1 << ' ' << q[tour.front()].front() << '\n';
            q[tour.front()].pop();
            if(q[tour.front()].empty()) tour.pop();
        }
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