#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, cntConsonant[N], cntVowel[N], f[N];

bool isVowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool isConsonant(char c)
{
    return !isVowel(c);
}

void compress()
{
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        v[i] = 2 * cntConsonant[i] - cntVowel[i];
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i <= n; i++)
    {
        int x = 2 * cntConsonant[i] - cntVowel[i];
        f[i] = lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
    }
}

struct BinaryIndexedTree
{
    int T[N];

    BinaryIndexedTree()
    {
        for (int i = 0; i < N; i++)
            T[i] = N;
    }

    void update(int k, int w)
    {
        for (; k <= n + 1; k += k & -k)
            T[k] = min(T[k], w);
    }

    int getMin(int k)
    {
        int res = n + 1;
        for (; k > 0; k -= k & -k)
            res = min(res, T[k]);
        return res;
    }
} BIT;

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    for (char &x : s)
        x = tolower(x);
    n = s.size();
    s = ' ' + s;

    for (int i = 1; i <= n; i++)
    {
        cntVowel[i] = cntVowel[i - 1] + isVowel(s[i]);
        cntConsonant[i] = cntConsonant[i - 1] + isConsonant(s[i]);
    }

    compress();

    int maxLen = 0, cntMax = 0;

    BIT.update(f[0], 0);
    for (int i = 1; i <= n; i++)
    {
        int Left = BIT.getMin(f[i]);
        if (maxLen < i - Left)
        {
            maxLen = i - Left;
            cntMax = 0;
        }
        if (maxLen == i - Left)
            cntMax++;
        BIT.update(f[i], i);
    }

    if (maxLen == 0)
        cout << "No solution\n";
    else
        cout << maxLen << ' ' << cntMax << '\n';

    return 0;
}