#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

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

struct Fraction
{
    ll a, b;

    Fraction(ll _a, ll _b)
    {
        a = _a;
        b = _b;
    }

    Fraction(string s)
    {
        a = b = 0;
        bool passed = 0;
        ll signA = 1, signB = 1;
        for(char c : s)
        {
            if(c == '/') passed = 1;
            else
            {
                if(!passed)
                {
                    if(c == '-') signA = -1;
                    else a = a * 10 + c - '0';
                }
                else
                {
                    if(c == '-') signB = -1;
                    else b = b * 10 + c - '0';
                }
            }
        }
        a *= signA; b *= signB;
    }

    void simplify()
    {
        ll g = __gcd(a, b);
        a /= g;
        b /= g;
    }

    Fraction operator + (Fraction other)
    {
        Fraction ans(0, 1);
        ans.a = a * other.b + b * other.a;
        ans.b = b * other.b;
        ans.simplify();
        return ans;
    }

    Fraction operator - (Fraction other)
    {
        Fraction ans(0, 1);
        ans.a = a * other.b - b * other.a;
        ans.b = b * other.b;
        ans.simplify();
        return ans;
    }

    Fraction operator * (Fraction other)
    {
        Fraction ans(0, 1);
        ans.a = a * other.a;
        ans.b = b * other.b;
        ans.simplify();
        return ans;
    }

    bool operator == (Fraction other)
    {
        simplify();
        other.simplify();
        return a == other.a && b == other.b;
    }
};

vector<Fraction> fractions;
Fraction result(0, 1);
string tmp_ans, ans;

void backtracking(int i, Fraction val, Fraction last)
{
    if(i >= (int)fractions.size())
    {
        if(val == result)
        {
            ans = tmp_ans;
        }
        return;
    }
    
    tmp_ans += "+";
    backtracking(i + 1, val + fractions[i], fractions[i]);
    tmp_ans.back() = '-';
    Fraction zero = Fraction(0, 1);
    backtracking(i + 1, val - fractions[i], zero - fractions[i]);

    tmp_ans.back() = 'X';
    Fraction k = fractions[i];
    backtracking(i + 1, val + (last * (k - Fraction(1, 1))), last * k);
    tmp_ans.pop_back();
}

void solve()
{
    tmp_ans = "";
    ans = "";
    string s;
    while(cin >> s)
        fractions.push_back(Fraction(s));

    result = fractions.back();
    fractions.pop_back();
    backtracking(1, fractions[0], fractions[0]);
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    solve();

    return 0;
}