#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int pow_10(int n)
{
    int ans = 1;
    for(int i = 0; i < n; i++)
    {
        ans *= 10;
    }
    return ans;
}

void solve(int tc)
{
    int a, b; cin >> a >> b;
    int numDigit = 0;
    for(int i = 0; i < 7; i++)
    {
        if(a / pow_10(i + 1) == 0)
        {
            numDigit = i + 1;
            break;
        }
    }
    
    int ans = 0;
    if(numDigit == 1) ans = 0;
    else 
    {
        for(int i = a; i < b; i++)
        {
            int m = i;
            do
            {
                m = (m / 10) + (m % 10) * pow_10(numDigit - 1);
                if(i < m && m <= b) ans++;
            } while (m != i);
        }
    }
    cout << "Case #" << tc + 1 << ": " << ans << "\n";
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