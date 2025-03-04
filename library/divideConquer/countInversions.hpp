int merge(vector<int> &a, int l, int m, int r)
{
    vector<int> b(a.begin() + l, a.begin() + m + 1);
    vector<int> c(a.begin() + m + 1, a.begin() + r + 1);
    int nB = m - l + 1, nC = r - m;
    int i = 0, j = 0, k = l;
    while(i < nB && j < nC)
    {
        if(b[i] > c[j])
        {
            a[k++] = c[j++];
        }
        else
        {
            a[k++] = b[i++];
            cnt += j;
        }
    }
    while(i < nB)
    {
        a[k++] = b[i++];
        cnt += j;
    }
    while(j < nC)
    {
        a[k++] = c[j++];
    }
    return cnt;
}

int countInversions(vector<int> &a, int l, int r)
{
    if(l >= r) return 0;
    int m = (l + r) / 2;
    // Chia va tri
    int countLeft = countInversions(a, l, m);
    int countRight = countInversions(a, m + 1, r);
    // Gop
    int countMid = merge(a, l, m, r);
    return countLeft + countRight + countMid;
}