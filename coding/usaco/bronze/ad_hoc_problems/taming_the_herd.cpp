#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<int> logs(n);
    int max_stay = -1, cnt_stay = 0, pos = -1, min_break = 1, tmp = 0;
    bool check = true;
    for(int i = 0; i < n; i++)
    {
        cin >> logs[i];
        if(logs[i] != -1)
        {
            max_stay++;
            if(logs[i] > max_stay) 
            {
                cout << -1;
                return;
            }
            else if(logs[i] == max_stay)
            {
                if(check)
                {
                    check = false;
                    tmp = max_stay;
                    cnt_stay += tmp;;
                }
                cnt_stay -= tmp;
                tmp = max_stay = logs[i];
                cnt_stay += tmp;
                pos = i;
            }
            else
            {
                if(i - pos <= logs[i])
                {
                    cout << -1;
                    return;
                }
                tmp = max_stay = logs[i];
                cnt_stay += tmp;
                pos = i;
                min_break++;
            }
        }
        else max_stay++;
    }
    cout << min_break << " " << n - cnt_stay;
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