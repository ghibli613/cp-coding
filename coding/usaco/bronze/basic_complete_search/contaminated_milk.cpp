#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int N, M, D, S;
    cin >> N >> M >> D >> S;
    vector<int> p(D), m(D), t(D);
    vector<int> count(M, 0);
    for(int i = 0; i < D; i++)
        cin >> p[i] >> m[i] >> t[i];
    vector<int> p1(S), t1(S);
    for(int i = 0; i < S; i++)
        cin >> p1[i] >> t1[i];

    for(int i = 0; i < S; i++)
    {
        vector<bool> check(M, false);
        for(int j = 0; j < D; j++)
            if(p1[i] == p[j])
                if(t1[i] > t[j])
                    check[m[j] - 1] = true;

        for(int j = 0; j < M; j++)
            if(check[j]) count[j]++;
    }

    set<int> bad_milk;
    for(int i = 0; i < M; i++) if(count[i] == S) bad_milk.insert(i + 1);

    set<int> ill_people;
    for(int i = 0; i < D; i++)
        if(bad_milk.find(m[i]) != bad_milk.end() && ill_people.find(p[i]) == ill_people.end())
            ill_people.insert(p[i]);

    cout << ill_people.size();
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