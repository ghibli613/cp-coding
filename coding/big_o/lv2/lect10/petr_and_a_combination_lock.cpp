#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

void solve()
{
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = 0; i < (1 << n); i++)
    {
        int sum = 0;
        for(int j = 0; j < n; j++)
        {
           if((1 << j) & i) sum += a[j];
           else sum -= a[j];
        }
        if(sum % 360 == 0)
        {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";

    return 0;
}