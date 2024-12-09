#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD1 = 1e9 + 9;
const ll MOD2 = 1e9 + 7;
const int N = 1e6 + 7;
const int base1 = 31;
const int base2 = 51;

ll hashReverse[N], POW[N];
ll hashReverse2[N], POW2[N];

int getLongestPalindrome(string &s)
{
    int result = 0;
    ll hash1 = 0, hash2 = 0;
    ll hashReverse1 = 0, hashReverse2 = 0;
    ll POW1 = 1, POW2 = 1;
    for (int i = 0; i < (int)s.size(); i++)
    {
        hash1 = (hash1 * base1 + s[i] - 'a' + 1) % MOD1;
        hashReverse1 = (hashReverse1 + (s[i] - 'a' + 1) * POW1) % MOD1;
        POW1 = (POW1 * base1) % MOD1;

        hash2 = (hash2 * base2 + s[i] - 'a' + 1) % MOD2;
        hashReverse2 = (hashReverse2 + (s[i] - 'a' + 1) * POW2) % MOD2;
        POW2 = (POW2 * base2) % MOD2;
        if (hash1 == hashReverse1 && hash2 == hashReverse2)
        {
            result = i + 1;
        }
    }
    return result;
}

string getLongestLeftRight(string &s)
{
    int lenLeft = getLongestPalindrome(s);
    string t = s;
    reverse(t.begin(), t.end());
    int lenRight = getLongestPalindrome(t);
    if (lenLeft >= lenRight)
    {
        return s.substr(0, lenLeft);
    }
    return s.substr(s.length() - lenRight, lenRight);
}

string solve(string &s)
{
    int n = s.size();
    s = " " + s;
    int l = 1, r = n;
    while (s[l] == s[r] && l < r)
    {
        l++;
        r--;
    }
    string t = s.substr(l, r - l + 1);
    return s.substr(1, l - 1) + getLongestLeftRight(t) + s.substr(r + 1, l - 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
}