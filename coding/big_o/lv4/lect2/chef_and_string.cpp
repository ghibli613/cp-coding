#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
vector<vector<int>> ncr(5001, vector<int>(5001, 0));

// Precalculating nCr values
void preCalculateNCR()
{
    for (int n = 1; n < 5001; n++)
    {
        for (int r = 0; r <= n; r++)
        {
            if (n == 0 || r == 0 || n == r)
            {
                ncr[n][r] = 1;
            }
            else
            {
                ncr[n][r] = (ncr[n - 1][r - 1] + ncr[n - 1][r]) % mod;
            }
        }
    }
}

vector<int> computeZFunction(const string &s)
{
    int size = s.size();
    vector<int> z(size, 0);
    int l = 0, r = 0;
    for (int j = 1; j < size; j++)
    {
        if (j < r)
        {
            z[j] = min(r - j, z[j - l]);
        }
        while (j + z[j] < size && s[z[j]] == s[j + z[j]])
        {
            z[j]++;
        }
        if (j + z[j] > r)
        {
            l = j;
            r = j + z[j];
        }
    }
    return z;
}

// Solve function
void solve()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    vector<int> maxZ(n, 0);
    vector<vector<int>> count(n + 1, vector<int>(n + 1, 0));

    // Process each starting indexex
    for (int i = 0; i < n; i++)
    {
        string temp = s.substr(i) + "#" + s;
        int size = temp.size();
        vector<int> z = computeZFunction(temp);

        // Count substring occurrences
        bool ok = false;
        int index = -1;
        for (int j = 0; j < size; j++)
        {
            if (ok)
            {
                count[i][0]++;
                count[i][z[j]]--;
                if (index > i)
                {
                    // here we have to update after considering the substring starting from i, because
                    // if we starting from substring i, we are not including one time also
                    maxZ[index] = max(maxZ[index], z[j]);
                }
                index++;
            }
            if (temp[j] == '?')
            {
                ok = true;
                index = 0;
            }
        }

        // Apply cumulative sum and handle overlaps
        int sum = 0;
        for (int len = 0; len <= n; len++)
        {
            int delta = count[i][len];
            count[i][len] = sum;
            sum += delta;

            // Remove overlaps based on maxZ[i]
            if (len <= maxZ[i])
            {
                count[i][len] = 0;
            }
        }
    }

    // Calculate final answers for each possible count
    vector<int> ans(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int len = 0; len <= n; len++)
        {
            int total = count[i][len];
            for (int r = 1; r <= total; r++)
            {
                ans[r] = (ans[r] + ncr[total][r]) % mod;
            }
        }
    }

    // Answer queries
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        if (x > n)
        {
            cout << "0\n";
        }
        else
        {
            cout << ans[x] << "\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    preCalculateNCR();
    while (t--)
    {
        solve();
    }

    return 0;
}