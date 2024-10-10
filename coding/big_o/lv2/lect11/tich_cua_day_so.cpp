#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

int n;

void backtracking(int k, int i, ll pre, ll L, ll R)
{
    if(L > R) return;
    if(i == k)
    {
        if(L % (R - L) == 0)
        {
            cout << k;
            exit(0);
        }
        return;
    }

    ll j = pre;
    while(true)
    {
        ll newL = L * (j + 1);
        ll newR = R * j;
        int rem = k - i;
        while(rem)
        {
            newL *= (j + 1);
            newR *= j;
            rem--;
        }
        if(newL < newR) break;
        backtracking(k, i + 1, j, L * (j + 1), R * j);
        j++;;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int k = 1;
    while(true)
    {
        backtracking(k, 1, 1, 1, n);
        k++;
    }

    return 0;
}