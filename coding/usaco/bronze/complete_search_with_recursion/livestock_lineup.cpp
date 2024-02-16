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
    int n; cin >> n;
    vector<pair<string, string>> constraint(n);
    for(int i = 0; i < n; i++)
    {
    	cin >> constraint[i].first;
    	string tmp;
    	for(int i = 0; i < 4; i++) cin >> tmp;
    	cin >> constraint[i].second;
    }
    vector<string> cows{"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
    
    do
    {
    	bool valid = true;
    	for(int j = 0; j < n; j++)
    	{
    		for(int i = 0; i < 8; i++)
            {
                if(cows[i] == constraint[j].first)
    			{
                    if(i == 0)
                    {
                        if(cows[i + 1] != constraint[j].second)
                        {
                            valid = false;
                            break;
                        }
                    }
                    else if(i == 7)
                    {
                        if(cows[i - 1] != constraint[j].second)
                        {
                            valid = false;
                            break;
                        }
                    }
                    else                     
                    {
                        if(cows[i-1] != constraint[j].second && cows[i+1] != constraint[j].second)
                        {
                            valid = false;
                            break;
                        }
                    }
    			}

            }
            if(!valid) break;
    	}

    	if(valid) 
    	{
    		for(int i = 0; i < 8; i++) cout << cows[i] << "\n";
    		break;
    	}

    		
    } while(next_permutation(cows.begin(), cows.end()));
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
