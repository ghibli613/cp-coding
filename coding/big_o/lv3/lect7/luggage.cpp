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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string st;
    getline(cin, st);
    int t = stoi(st);

    while(t--)
    {
        string in;
        getline(cin, in);
        vector<int> a;
        string num = "";
        for(int i = 0; i < (int)in.size(); i++)
        {
            if(in[i] == ' ')
            {
                a.push_back(stoi(num));
                num = "";
            }
            else
            {
                num += in[i];
            }
        }
        a.push_back(stoi(num));

        int sum = 0;
        for(int i = 0; i < (int)a.size(); i++) sum += a[i];

        if(sum % 2 != 0)
        {
            cout << "NO\n";
            continue;
        }

        int w = sum / 2;
        vector<int> weight;
        for(int i = 0; i < (int)a.size(); i++) 
            if(a[i] <= w) weight.push_back(a[i]);

        int n = (int)weight.size();

        vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j <= w; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if(j >= weight[i - 1])
                    dp[i][j] = dp[i][j] | (dp[i - 1][j - weight[i - 1]] & 1);
            }
        }

        if(dp[n][sum / 2]) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}