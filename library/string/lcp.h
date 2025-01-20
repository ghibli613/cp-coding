vector<int> computeLCP(const string& s, const vector<int>& SA)
{
    int n = SA.size();
    vector<int> LCP(n), PLCP(n), c(n, 0);

    for(int i = 0; i < n; i++)
        c[SA[i]] = i;
    int k = 0;
    for(int j, i = 0; i < n - 1; i++)
    {
        j = SA[c[i] - 1];
        k = max(k - 1, 0);
        while (s[i + k] == s[j + k]) k++;
        PLCP[i] = k;
    }

    for(int i = 0; i < n; i++)
        LCP[i] = PLCP[SA[i]];

    return LCP;
}