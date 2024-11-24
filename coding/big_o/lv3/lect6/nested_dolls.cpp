#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n;
    cin >> n;
    vector<pii> dolls;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        dolls.push_back({a, b});
    }

    sort(dolls.begin(), dolls.end(), [](pair<int, int> &a, pair<int, int> &b)
         {
             // larger first - disallow nesting if x is same
             if(a.first==b.first) return a.second > b.second;
             return a.first < b.first; });
    // simulate doll nesting using a greedy approach
    // select the largest number that is smaller than y
    // replace with y
    deque<int> nestedY;
    for (int i = 0; i < n; i++)
    {
        int pos = lower_bound(nestedY.begin(), nestedY.end(), dolls[i].second) - nestedY.begin();
        // no smaller dolls
        if (pos == 0)
        {
            nestedY.push_front(dolls[i].second);
        }
        else
        {
            nestedY[pos - 1] = dolls[i].second;
        }
    }

    cout << (int)nestedY.size() << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--)
        solve();

    return 0;
}