#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int base = 31;
const int MOD = 1e9 + 3;
#define MAXN 1005

int Pow[MAXN];

void initPow()
{
    Pow[0] = 1;
    for (int i = 1; i <= 1000; i++)
        Pow[i] = (Pow[i - 1] * base);
}

class Hash
{
public:
    int hash[MAXN];
    int get(int i, int j)
    {
        return (hash[j] - hash[i - 1] * Pow[j - i + 1]);
    }
    void init(string s)
    {
        for (int i = 1; i < s.size(); i++)
        {
            hash[i] = hash[i - 1] * base + (s[i] - 'a' + 1);
            // hash[i] %= MOD;
        }
    }
};

class stringMatching
{
public:
    int lps[MAXN];
    vector<int> pat;
    int N;
    void computeLPS()
    {
        int len = 0;
        lps[0] = 0;

        int i = 1;
        while (i < N)
        {
            if (pat[i] == pat[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else // (pat[i] != pat[len])
            {
                if (len != 0)
                {
                    len = lps[len - 1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    int KMPSearch(vector<int> txt)
    {
        int M = txt.size();
        int i = 0; // index for txt[]
        int j = 0; // index for pat[]
        int cnt = 0;
        while (i < M)
        {
            if (pat[j] == txt[i])
            {
                j++;
                i++;
            }

            if (j == N)
            {
                cnt += 1;
                j = lps[j - 1];
            }

            // mismatch after j matches
            else if (i < M && pat[j] != txt[i])
            {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i = i + 1;
            }
        }
        return cnt;
    }

    void init(vector<int> pat)
    {
        this->N = pat.size();
        this->pat = pat;
        computeLPS();
    }
};

string a[MAXN], b[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    initPow();
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            a[i] = ' ' + a[i];
        }
        int x, y;
        cin >> x >> y;
        for (int i = 1; i <= x; i++)
        {
            cin >> b[i];
            b[i] = ' ' + b[i];
        }

        vector<Hash> hashA(n + 1);
        vector<Hash> hashB(x + 1);
        // initialize
        for (int i = 1; i <= n; i++)
        {
            hashA[i].init(a[i]);
        }
        vector<int> hashPat;
        for (int i = 1; i <= x; i++)
        {
            hashB[i].init(b[i]);
            hashPat.push_back(hashB[i].hash[y]);
        }
        stringMatching kmp;
        kmp.init(hashPat);
        int res = 0;
        for (int j = 1; j <= m - y + 1; j++)
        {
            vector<int> hashTxt;
            for (int i = 1; i <= n; i++)
            {
                hashTxt.push_back(hashA[i].get(j, j + y - 1));
            }
            res += kmp.KMPSearch(hashTxt);
        }
        cout << res << '\n';
    }
}

/*
Test case:

*/