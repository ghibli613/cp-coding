#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(int tc)
{
    int n; cin >> n;
    vector<int> s(n);
    int x = 0;
    for(int &i : s)
    { 
        cin >> i;
        x += i;
    }

    function<bool(double, int)> f = [&](double p, int i) {
        double score = (double)s[i] + (double)x * p;
        double sum = p;
        for(int j = 0; j < n; j++)
        {
            if(j == i) continue;
            else
            {
                if(s[j] >= score) continue;
                else
                {
                    sum += (score - s[j]) / x;
                }
            }
            if(sum > 1) return false;
        }
        return true;
    };

    cout << "Case #" << tc << ": ";
    
    for(int i = 0; i < n; i++)
    {
        double left = 0, right = 1, _esp = 1e-9, ans = 0;
        while(left + _esp < right)
        {
            double mid = (left + right) / 2.0;
            
            if(f(mid, i))
            {
                ans = mid;
                left = mid;
            }
            else
            {
                right = mid;
            }
        }
        ans *= 100;
        cout << fixed << setprecision(6) << ans << ' ';
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    for(int tc = 1; tc <= t; tc++)
        solve(tc);

    return 0;
}