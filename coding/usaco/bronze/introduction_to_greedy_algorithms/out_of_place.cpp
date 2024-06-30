#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<int> cows(n);
    for(int i = 0; i < n; i++) cin >> cows[i];

    int pos = -1;
    if(cows[0] > cows[1]) pos = 0;
    else if(cows[n - 1] < cows[n - 2]) pos = n - 1;
    else
    {
        for(int i = 1; i < n - 1; i++)
            if(cows[i] < cows[i - 1])
            {
                if(cows[i + 1] >= cows[i - 1]) pos = i;
                else pos = i - 1;
            }
    }
// cout << pos;
    if(pos == -1) cout << 0;
    else
    {
        unordered_set<int> my_set;
        if(pos == 0 || (cows[pos] > cows[pos - 1] && cows[pos] > cows[pos + 1]))
        {
            int right_pos = pos + 1;
            while(right_pos != n - 1 && (cows[pos] > cows[right_pos] && cows[pos] > cows[right_pos + 1]))
            {
                my_set.insert(cows[right_pos]);
                right_pos++;
            }
            my_set.insert(cows[right_pos]);
            cout << my_set.size();
        }
        else
        {
            // cout << 1;
            int right_pos = pos - 1;
            while(right_pos != 0 && (cows[pos] < cows[right_pos] && cows[pos] < cows[right_pos - 1]))
            {
                my_set.insert(cows[right_pos]);
                right_pos--;
            }
            my_set.insert(cows[right_pos]);
            cout << my_set.size();
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