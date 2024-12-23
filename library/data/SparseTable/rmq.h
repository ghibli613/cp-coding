
void compute_spare_table(const vector<T> &a)
{
    for (int i = 0; i < n; i++)
        f[i][0] = a[i];

    for (int j = 1; (1 << j) <= n; j++)
    {
        int step = 1 << (j - 1);
        for (int i = 0; i + 2 * step <= n; i++)
        {
            f[i][j] = min(f[i][j - 1], f[i + step][j - 1]);
        }
    }
}

T minQuery(int l, int r)
{
    int k = log_2[r - l + 1];
    return min(f[l][k], f[r - (1 << k) + 1][k]);
}

void compute_log()
{
    log_2[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        log_2[i] = log_2[i / 2] + 1;
    }
}
