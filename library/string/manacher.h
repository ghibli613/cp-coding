vector<int> manacher(string s)
{
    int n = s.length();
    vector<int> p(n);
    int l = 0, r = -1;
    for (int i = 0; i < n; i++)
    {
        int k = i > r ? 0 : min(p[l + r - i], r - i);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k])
            k++;
        p[i] = --k;
        if (i + k > r)
        {
            l = i - k;
            r = i + k;
        }
    }
    return p;
}

void test()
{
    string s;
    cin >> s;
    string t(2 * s.length() + 1, '#');
    for (int i = 0; i < s.length(); i++)
        t[2 * i + 1] = s[i];

    int ans = 0;
    vector<int> p = manacher(t);
    for (int i = 1; i < p.size() - 1; i++)
    {
        if(p[i] > 0)
            cout << p[i] << " " << s.substr((i - p[i]) / 2, p[i]) << "\n";
    }
}