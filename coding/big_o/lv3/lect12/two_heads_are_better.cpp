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

    int n, l, r; cin >> n >> l >> r;

    vector<char> left, right;
    deque<char> mid;
    for(int i = 0; i < l - 1; i++) 
    {
        char tmp; cin >> tmp;
        left.push_back(tmp);
    }

    for(int i = l - 1; i < r; i++)
    {
        char tmp; cin >> tmp;
        mid.push_back(tmp);
    }

    for(int i = r; i < n; i++)
    {
        char tmp; cin >> tmp;
        right.push_back(tmp);
    }

    reverse(right.begin(), right.end());

    int m; cin >> m;
    bool is_reverse = 0;

    // for(int i = 0; i < left.size(); i++) cout << left[i];
    // cout << ' ';
    // if(is_reverse) for(int i = mid.size() - 1; i >= 0; i--) cout << mid[i];
    // else for(int i = 0; i < mid.size(); i++) cout << mid[i];
    // cout << ' ';
    // for(int i = right.size() - 1; i >= 0; i--) cout << right[i];
    // cout << '\n';
    while(m--)
    {
        char operate; cin >> operate;
        if(operate == 'S')
        {
            char x, y; cin >> x >> y;
            if(is_reverse)
            {
                if(x == 'L')
                {
                    if(y == 'L')
                    {
                        mid.push_back(left.back());
                        left.pop_back();
                    }
                    else
                    {
                        left.push_back(mid.back());
                        mid.pop_back();
                    }
                }
                else
                {
                    if(y == 'L')
                    {
                        right.push_back(mid.front());
                        mid.pop_front();
                    }
                    else
                    {
                        mid.push_front(right.back());
                        right.pop_back();
                    }
                }
            }
            else
            {
                if(x == 'L')
                {
                    if(y == 'L')
                    {
                        mid.push_front(left.back());
                        left.pop_back();
                    }
                    else
                    {
                        left.push_back(mid.front());
                        mid.pop_front();
                    }
                }
                else
                {
                    if(y == 'L')
                    {
                        right.push_back(mid.back());
                        mid.pop_back();
                    }
                    else
                    {
                        mid.push_back(right.back());
                        right.pop_back();
                    }
                }
            }

            // for(int i = 0; i < left.size(); i++) cout << left[i];
            // cout << ' ';
            // if(is_reverse) for(int i = mid.size() - 1; i >= 0; i--) cout << mid[i];
            // else for(int i = 0; i < mid.size(); i++) cout << mid[i];
            // cout << ' ';
            // for(int i = right.size() - 1; i >= 0; i--) cout << right[i];
            // cout << '\n';
        }
        else if(operate == 'R')
        {
            if(is_reverse) is_reverse = 0;
            else is_reverse = 1;

            // for(int i = 0; i < left.size(); i++) cout << left[i];
            // cout << ' ';
            // if(is_reverse) for(int i = mid.size() - 1; i >= 0; i--) cout << mid[i];
            // else for(int i = 0; i < mid.size(); i++) cout << mid[i];
            // cout << ' ';
            // for(int i = right.size() - 1; i >= 0; i--) cout << right[i];
            // cout << '\n';
        }
        else
        {
            char x; cin >> x;
            // cout << x << ' ';
            if(is_reverse)
            { 
                if(x == 'L')
                    cout << mid.back();
                else
                    cout << mid.front();
            }
            else
            {
                if(x == 'L')
                    cout << mid.front();
                else
                    cout << mid.back();
            }
        }
    }

    return 0;
}