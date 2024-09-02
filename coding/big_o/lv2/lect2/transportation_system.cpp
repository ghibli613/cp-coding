#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

vector<int> parent;

int findSet(int u)
{
    if (parent[u] != u) parent[u] = findSet(parent[u]);
    return parent[u];
}

void solve(int tc)
{
    int n, r; cin >> n >> r;
    vector<pii> cities;
    parent.assign(n, 0);
    for(int i = 0; i < n; i++)
    {
        pii tmp; cin >> tmp.first >> tmp.second;
        cities.push_back(tmp);
        parent[i] = i;
    }
    
    vector< pair< int, pair<int, double> > > distances;

    for(int i = 0; i < n - 1; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            int x = cities[i].first - cities[j].first;
            int y = cities[i].second - cities[j].second;
            x *= x;
            y *= y;
            distances.push_back(make_pair(x + y, make_pair(i, j)));
        }
    }

    sort(distances.begin(), distances.end());

    int states = 1;
    double minRail = 0;
    double minRoad = 0;
    int components = 0;

    for(int i = 0; i < (int)distances.size(); ++i)
    {
        pair< int, pair<int, double> > front = distances[i];
        
        int u = findSet(front.second.first);
        int v = findSet(front.second.second);

        if(u != v)
        {
            parent[u] = v;

            if(front.first <= r * r)
                minRoad += sqrt(front.first);
            else
            {
                ++states;
                minRail += sqrt(front.first);
            }

            if(++components == n - 1)
                break;
        }
    }
    cout << "Case #" << tc << ": " << states << " " << (int)round(minRoad) << " " << (int)round(minRail) << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    for(int tc = 1; tc <= t; tc++)
        solve(tc);

    return 0;
}
