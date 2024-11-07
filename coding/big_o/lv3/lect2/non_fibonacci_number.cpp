#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

set<int> ms;

int nonfibo(int n)
{
    int prev1 = 1;
    int prev2 = 0;
    int res;
    int cnt = 0;
    while (cnt != n)
    {
        res = prev1 + prev2;
        for(int i = prev1 + 1; i < res; i++)
        {
            cnt++;
            if(cnt == n) return i;
        }
        prev2 = prev1;
        prev1 = res;
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    cout << nonfibo(n);

    return 0;
}