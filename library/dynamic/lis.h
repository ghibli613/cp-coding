int LIS(vector<int>& A, vector<int>& dp, vector<int> & prev)
{
    int n = A.size();
    vector<int> lis, lis_index;
    dp.assign(n, 1);
    prev.assign(n, -1);
    
    for(int j, i = 0; i < n; i++)
    {
        j = upper_bound(lis.begin(), lis.end(), A[i]) - lis.begin();
        dp[i] = j + 1;
        if(j != 0)
        {
            prev[i] = lis_index[j - 1];
        }
        if(j == (int)lis.size())
        {
            lis.push_back(A[i]);
            lis_index.push_back(i);
        }
        else
        {
            lis[j] = A[i];
            lis_index[j] = i;
        }
    }

    return lis_index[(int)lis.size() - 1];
}

void trace(vector<int>& A, vector<int>>& prev, int pos)
{
    vector<int> b;
    int pos = lis_index[(int)lis.size() - 1];
    while(pos != -1)
    {
        b.push_back(A[pos]);
        pos = prev[pos];
    }

    for(int i = (int)b.size() - 1; i >= 0; i--)
        cout << b[i] << ' ';
    cout << '\n';
}