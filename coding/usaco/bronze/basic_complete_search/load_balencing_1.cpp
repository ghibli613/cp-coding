#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int min_partition(int x_line, const vector<pair<int, int>> &cows)
{
    vector<pair<int, int>> left;
    vector<pair<int, int>> right;
    for(const pair<int, int> &c : cows)
        if(c.first < x_line) left.push_back(c);
        else if(c.first > x_line) right.push_back(c);

    int most_balanced = INT32_MAX, left_at = 0, right_at = 0;
    while(left_at + right_at < (int)cows.size())
    {
        int y_line = cows[left_at + right_at].second + 1;
        while(left_at < left.size() &&  y_line > left[left_at].second) left_at++;
        while(right_at < right.size() && y_line > right[right_at].second) right_at++;
        int below_max = max(left_at, right_at);
        int above_max = max((int)left.size() -left_at, (int)right.size() - right_at);
        most_balanced = min(most_balanced, max(below_max, above_max));
    }
    return most_balanced;
}

void solve()
{
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end(), [&](const pair<int, int> &p1, const pair<int, int> &p2) {return p1.first < p2.first; });
    vector<pair<int, int>> b(a);
    sort(b.begin(), b.end(), [&](const pair<int, int> &p1, const pair<int, int> &p2) {return p1.second < p2.second; });

    int most_balanced = INT32_MAX;
    int x_line_at = 0;
    while(x_line_at < (int)a.size())
    {
        int x_line = a[x_line_at].first + 1;
        most_balanced = min(most_balanced, min_partition(x_line, b));
        while(x_line_at < n && x_line > a[x_line_at].first) x_line_at++;
    }
    cout << most_balanced;
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