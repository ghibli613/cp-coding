#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, M; 
vector<array<int,3>> cows;
vector<array<int,4>> air_conditioners;
vector<bool> uses;
int min_cost = INT_MAX;

void update()
{
    bool is_feasible = true;
    for(int i = 1; i <= 100; i++)
    {
        int cooling = 0;
        for(int j = 0; j < M; j++)
        {
            if(!uses[j]) continue;
            int a = air_conditioners[j][0], b = air_conditioners[j][1], p = air_conditioners[j][2], m = air_conditioners[j][3];
            if(a <= i && i <= b) cooling += p;
        }

        int cow_requirement = 0;
        for(int j = 0; j < N; j++)
        {
            int s = cows[j][0], t = cows[j][1], c = cows[j][2];
            if(s <= i && i <= t)
            {
                cow_requirement = c;
                break;
            }
        }

        if(cooling < cow_requirement)
        {
            is_feasible = false;
            break;
        }
    }

    if(is_feasible)
    {
        int cost = 0;
        for(int i = 0; i < M; i++)
            if(uses[i]) cost += air_conditioners[i][3];
        min_cost = min(min_cost, cost);
    }
}

void search(int i)
{
    if(i == M) update();
    else
    {
        uses[i] = false;
        search(i + 1);
        uses[i] = true;
        search(i + 1);
    }
}

void solve()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++) 
    {
        int s, t, c;
        cin >> s >> t >> c;
        cows.push_back({s, t, c});
    }

    for (int i = 0; i < M; i++) 
    {
        int a, b, p, m;
        cin >> a >> b >> p >> m;
        air_conditioners.push_back({a, b, p, m});
    }
    uses.assign(M, false);
    search(0);
    cout << min_cost;
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