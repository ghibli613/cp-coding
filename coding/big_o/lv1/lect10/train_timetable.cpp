#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int convert(string time)
{
    int res = ((time[0] - '0') * 10 + time[1] - '0') * 60 + (time[3] - '0') * 10 + time[4] - '0';
    return res;
}

struct train
{
    int s;
    int e;
    bool f;
};

bool compare_train(train a, train b)
{
    if(b.s > a.s) return true;
    return false;
}

void solve(int c)
{
    int t; cin >> t;
    int na, nb; cin >> na >> nb;
    vector<train> all(na + nb);
    for(int i = 0; i < na; i++)
    {
        string s1, s2; cin >> s1 >> s2;
        all[i] = {convert(s1), convert(s2), 0};
    }
    for(int i = 0; i < nb; i++)
    {
        string s1, s2; cin >> s1 >> s2;
        all[i + na] = {convert(s1), convert(s2), 1};
    }
    sort(all.begin(), all.end(), compare_train);
    priority_queue<int, vector<int>, greater<int>> a, b;
    int ans1 = 0, ans2 = 0;
    for(int i = 0; i < na + nb; i++)
    {
        if(all[i].f)
        {
            if(a.empty() || a.top() > all[i].s)
                ans1++;
            else
                a.pop();
            b.push(all[i].e + t);
        }
        else
        {
            if(b.empty() || b.top() > all[i].s)
                ans2++;
            else
                b.pop();
            a.push(all[i].e + t);
        }
    }
    cout << "Case #" << c << ": " << ans2 << ' ' << ans1 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    for(int test_case = 0; test_case < t; test_case++)
        solve(test_case + 1);

    return 0;
}