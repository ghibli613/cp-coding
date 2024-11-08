#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double INF = 1e9;

bool cmpY(const pii &a, const pii &b)
{
    if (a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
}

double distance(pii a, pii b)
{
    return sqrt(1ll * (a.first - b.first) * (a.first - b.first) + 1ll * (a.second - b.second) * (a.second - b.second));
}

double Perimeter(pii a, pii b, pii c)
{
    return distance(a, b) + distance(a, c) + distance(b, c);
}

double findMin(vector<pii> &a, vector<pii> &b)
{
    int n = a.size();
    if (n < 3)
        return INF;

    int mid = n / 2;
    vector<pii> la, ra;
    for (pii point : a)
    {
        if (point <= a[mid])
            la.push_back(point);
        else
            ra.push_back(point);
    }

    vector<pii> lb, rb;
    for (pii point : b)
    {
        if (point <= a[mid])
            lb.push_back(point);
        else
            rb.push_back(point);
    }

    double p = min(findMin(la, lb), findMin(ra, rb));
    vector<pii> c;
    double xmid = a[mid].first;
    for (pii point : b)
        if (point.first >= xmid - p / 2 && point.first <= xmid + p / 2)
            c.push_back(point);

    for (int i = 0; i < (int)c.size() - 2; i++)
    {
        for (int j = i + 1; j < (int)c.size() - 1; j++)
        {
            if (c[j].second - c[i].second > p / 2)
                break;
            for (int k = j + 1; k < (int)c.size(); k++)
            {
                if (c[k].second - c[i].second > p / 2)
                    break;
                p = min(p, Perimeter(c[i], c[j], c[k]));
            }
        }
    }
    return p;
}

void solve()
{
    int n;
    cin >> n;
    vector<pii> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    vector<pii> b = a;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), cmpY);
    cout << findMin(a, b) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(6);
    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}