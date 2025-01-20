int findSubstring(const string& s, const vector<int>& SA, const string& p)
{
    int m, l = 0, r = s.length();

    while(l < r)
    {
        m = (l + r) >> 1;
        int cmp = s.compare(SA[m], p.length(), p);
        if(cmp == 0)
            return SA[m];
        if(cmp < 0)
            l = m + 1;
        else
            r = m;
    }

    return -1;
}