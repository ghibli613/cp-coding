#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> f = {1, 2};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int nmax = 1e9;
    while (f.back() < nmax)
    {
        int n = f.size();
        f.push_back(f[n - 1] + f[n - 2]);
    }
    int t; cin >> t;

    while(t--)
    {
        int n; cin >> n;
        n++; 
        int m = f.size() - 1;
        bool printed = false;
        while (m > 0)
        {
            if(n <= f[m - 1])
            {
                if(printed)
                {
                    cout << 0;
                }
                m -= 1;
            }
            else
            {
                cout << 1;
                if(m >= 2) cout << 0;
                printed = 1;
                n -= f[m - 1];
                m -= 2;
            }
        }
        cout << '\n';
    }

    return 0;
}