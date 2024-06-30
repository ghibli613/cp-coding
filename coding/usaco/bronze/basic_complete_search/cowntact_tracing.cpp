#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool compar_tuple(tuple<int, int, int> a, tuple<int, int ,int> b)
{
    return get<0>(a) < get<0>(b);
}

void solve()
{
    int N, T; cin >> N >> T;
    string s; cin >> s;
    vector<tuple<int, int, int>> a(T);
    for(int i = 0; i < T; i++)
    {
        int t, x, y; cin >> t >> x >> y;
        get<0>(a[i]) = t - 1;
        get<1>(a[i]) = x - 1;
        get<2>(a[i]) = y - 1;
    }
    sort(a.begin(), a.end(), compar_tuple);

    function<bool(int, int)> is_consistent = [&](int patient_zero, int k) 
    {
        vector<bool> tmp_infected(N);
        vector<int> num_shakes(N);
        tmp_infected[patient_zero] = true;
        for (tuple<int, int, int> sh : a) 
        {
            if (tmp_infected[get<1>(sh)]) { num_shakes[get<1>(sh)]++; }
            if (tmp_infected[get<2>(sh)]) { num_shakes[get<2>(sh)]++; }
            if (num_shakes[get<1>(sh)] <= k && tmp_infected[get<1>(sh)]) {
                tmp_infected[get<2>(sh)] = true;
            }
            if (num_shakes[get<2>(sh)] <= k && tmp_infected[get<2>(sh)]) {
                tmp_infected[get<1>(sh)] = true;
            }
        }
        for (int i = 0; i < N; i++) 
			if ((tmp_infected[i] && s[i] == '0') || (!tmp_infected[i] && s[i] == '1'))
                return false; 
        return true;
    };

    int min_k = T, max_k = -1;
    set<int> possible_patient;
    for(int patient_zero = 0; patient_zero < N; patient_zero++)
        for(int k = 0; k <= T; k++)
            if(is_consistent(patient_zero, k))
            {
                possible_patient.insert(patient_zero);
                min_k = min(min_k, k);
                max_k = max(max_k, k);
            }
    if(max_k == T)
        cout << possible_patient.size() << ' ' << min_k << " Infinity";
    else cout << possible_patient.size() << ' ' << min_k << ' ' << max_k;
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