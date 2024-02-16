#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int fastest_time(int k, int max_speed)
{
    int speed_up_dist = 0;
    int slow_down_dist = 0;
    int time = 0;

    for(int curr_speed = 1;; curr_speed++)
    {
        speed_up_dist += curr_speed;
        time++;
        if(speed_up_dist + slow_down_dist >= k) return time;
        if(curr_speed >= max_speed)
        {
            slow_down_dist += curr_speed;
            time++;
            if(speed_up_dist + slow_down_dist >= k) return time; 
        }
    }
}

void solve()
{
    int n, k; cin >> k >> n;
    for(int i = 0; i < n; i++)
    {
        int max_speed;
        cin >> max_speed;
        cout << fastest_time(k, max_speed) << '\n';
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
