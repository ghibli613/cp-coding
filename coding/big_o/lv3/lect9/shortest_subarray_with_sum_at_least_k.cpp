#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    deque<int> dq;
    ll sum = 0;
    for(int i = 0; i < n; i++)
    {
        int tmp; cin >> tmp;
        dq.push_back(tmp);
        sum += tmp;
    }
    
    int ans = -1;
    if(sum >= k) ans = (int)dq.size();

    while(!dq.empty())
    {
        if(dq.front() <= dq.back())
        {
            sum -= dq.front();
            dq.pop_front();
            if(sum >= k)
            {
                if(ans == -1) ans = (int)dq.size();
                else ans = min(ans, (int)dq.size());
            }
        }
        else if(dq.back() < dq.front())
        {
            sum -= dq.back();
            dq.pop_back();
            if(sum >= k)
            {
                if(ans == -1) ans = (int)dq.size();
                else ans = min(ans, (int)dq.size());
            }
        }
    }
    cout << ans;

    return 0;
}