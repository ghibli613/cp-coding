#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_DIGIT = 256;

void countingSort(vector<int> &SA, vector<int> &RA, int k = 0)
{
    int n = SA.size();
    vector<int> cnt(max(MAX_DIGIT, n), 0);

    for (int i = 0; i < n; i++)
    {
        if (i + k < n)
            cnt[RA[i + k]]++;
        else
            cnt[0]++;
    }
    for (int i = 1; i < (int)cnt.size(); i++)
        cnt[i] += cnt[i - 1];
    vector<int> tempSA(n);
    for (int i = n - 1; i >= 0; i--)
        if (SA[i] + k < n)
            tempSA[--cnt[RA[SA[i] + k]]] = SA[i];
        else
            tempSA[--cnt[0]] = SA[i];
    SA = tempSA;
}

vector<int> constructSA(string s)
{
    int n = s.length();
    vector<int> SA(n);
    vector<int> RA(n);
    vector<int> tempRA(n);

    for (int i = 0; i < n; i++)
    {
        RA[i] = s[i];
        SA[i] = i;
    }

    for (int step = 1; step < n; step <<= 1)
    {
        countingSort(SA, RA, step);
        countingSort(SA, RA, 0);

        tempRA[SA[0]] = 0;
        for (int i = 1; i < n; i++)
        {
            if (RA[SA[i]] == RA[SA[i - 1]] && RA[SA[i] + step] == RA[SA[i - 1] + step])
                tempRA[SA[i]] = tempRA[SA[i - 1]];
            else
                tempRA[SA[i]] = tempRA[SA[i - 1]] + 1;
        }
        RA = tempRA;
        if (RA[SA[n - 1]] == n - 1)
            break;
    }
    return SA;
}

vector<int> computeLCP(const string &s, const vector<int> &SA)
{
    int n = SA.size();
    vector<int> LCP(n), PLCP(n), c(n, 0);

    for (int i = 0; i < n; i++)
        c[SA[i]] = i;
    int k = 0;
    for (int j, i = 0; i < n - 1; i++)
    {
        j = SA[c[i] - 1];
        k = max(k - 1, 0);
        while (s[i + k] == s[j + k])
            k++;
        PLCP[i] = k;
    }

    for (int i = 0; i < n; i++)
        LCP[i] = PLCP[SA[i]];

    return LCP;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    int k;
    cin >> k;
    int n = s.size();

    if (1LL * n * (n + 1) / 2 < k)
    {
        cout << "No such line." << endl;
        return 0;
    }
    s += '!';
    vector<int> p = constructSA(s);
    vector<int> lcp = computeLCP(s, p);

    vector<int> maxLen(n + 1, 0);
    for (int i = 0; i <= n; i++)
    {
        int len = n - p[i];
        for (int j = maxLen[i] + 1; j <= len; j++)
        {
            k--;
            if (k == 0)
            {
                cout << s.substr(p[i], j) << endl;
                return 0;
            }
            for (int x = i + 1; x <= n; x++)
            {
                if (lcp[x] < j)
                {
                    break;
                }
                maxLen[x] = max(maxLen[x], j);
                k--;
                if (k == 0)
                {
                    cout << s.substr(p[i], j) << endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}