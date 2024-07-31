#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#define dbg(...) cerr<<__func__<<":"<<__LINE__<<" [" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__);


void solve()
{
    int h, d; cin >> h >> d;
    vector<int> cnt(h);
    vector<vector<vector<int>>> sweep(9);
    for(int k = 2; k <= 10; k++)
    {
        sweep[k - 2] = vector<vector<int>> (k);
        for(int r = 0; r < k; r++)
        {
            if(r <= h % k)
            {
                sweep[k - 2][r] = vector<int> (h / k + 1);
            }
            else sweep[k - 2][r] = vector<int> (h / k);
        }
    }
    for(int i = 0; i < d; i++)
    {
        int s, k, p;
        cin >> s >> k >> p;
        int r = s % k;
        int L = s / k;
        int R = L + p - 1;
        // cout << L << endl;
        sweep[k - 2][r][L] += 1;
        if((int)sweep[k - 2][r].size() > R + 1)
            sweep[k - 2][r][R + 1] -= 1;
    }
    // dbg(sweep);
    for(int k = 2; k <= 10; k++)
    {
        for(int r = 0; r < k; r++)
        {
            int cur = 0; 
            for(int i = 0; i < (int)sweep[k - 2][r].size(); i++)
            {
                int index = i * k + r;
                cur += sweep[k - 2][r][i];
                if(index == 0) continue;
                cnt[index - 1] += cur;
            }
        }
    }
    // dbg(cnt);
    int ans = 0;
    for(int i = 0; i < h; i++)
    {
        if(cnt[i] > cnt[ans]) ans = i;
    }
    cout << "House " << ans + 1 << " should get the biggest and best gift next Christmas.\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while(t--)
        solve();

    return 0;
}