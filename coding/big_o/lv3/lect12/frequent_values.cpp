#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1e5 + 10;
const int MAX_LOG = 20;
const int INF = 1e9;

pii poss[MAX];
int a[MAX];
int f[MAX][MAX_LOG];
int log_2[MAX];
int n, q;

void compute_spare_table()
{
    for(int i = 0; i < n; i++)
        f[i][0] = a[i];

    for(int j = 1; (1 << j) <= n; j++)
    {
        int step = 1 << (j - 1);
        for(int i = 0; i + 2 * step <= n; i++)
            f[i][j] = max(f[i][j - 1], f[i + step][j - 1]);
    }
}

int maxQuery(int l, int r)
{
    int k = log_2[r - l + 1];
    return max(f[l][k], f[r - (1 << k) + 1][k]);
}

void compute_log()
{
    log_2[1] = 0;
    for(int i = 2; i <= n; i++)
    {
        log_2[i] = log_2[i / 2] + 1;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> n, n != 0)
    {
        cin >> q;

        vector<int> A(n);
        for(int i = 0; i < n; i++) cin >> A[i];
        map<int, int> tmp_cnt;
        map<int, pii> tmp_poss;

        tmp_cnt[A[0]]++;
        tmp_poss[A[0]].first = 0; tmp_poss[A[0]].second = 0;
        for(int i = 1; i < n; i++)
        {
            tmp_cnt[A[i]]++;
            tmp_poss[A[i]].second = i;
            if(A[i] != A[i - 1]) tmp_poss[A[i]].first = i;
        }

        for(int i = 0; i < n; i++)
        {
            a[i] = tmp_cnt[A[i]];
            poss[i] = tmp_poss[A[i]];
        }

        compute_spare_table();
        compute_log();

        for(int i = 0; i < q; i++)
        {
            int start, end; cin >> start >> end;
            start--; end--;
            if(A[start] == A[end])
            {
                cout << end - start + 1 << '\n';
            }
            else 
            {
                if(poss[start].second == poss[end].first - 1)
                {
                    cout << max(poss[start].second - start + 1, end - poss[end].first + 1) << '\n';
                }
                else
                {
                    int ans = max(poss[start].second - start + 1, end - poss[end].first + 1);
                    ans = max(ans, maxQuery(poss[start].second + 1, poss[end].first - 1));
                    cout << ans << '\n';
                }
            }
        }
    }

    return 0;
}