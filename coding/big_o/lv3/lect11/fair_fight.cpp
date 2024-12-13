#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5 + 7;
int n, k;
int c[N], d[N], L[N], R[N];
int m[N][24];
int lg[N];

void RMQ_process()
{
    for (int i = 0; i < n; i++)
        for (int k = 0; k <= 20; k++)
            m[i][k] = 0;
    for (int i = 0; i < n; i++)
        m[i][0] = d[i];
    for (int k = 1; (1 << k) <= n; k++)
        for (int i = 0; i + (1 << k) - 1 < n; i++)
            m[i][k] = max(m[i][k - 1], m[i + (1 << (k - 1))][k - 1]);
}

int RMQ(int u, int v)
{
    int k = lg[v - u + 1];
    return max(m[u][k], m[v - (1 << k) + 1][k]);
}

int binary(int pos, int sign, int left, int right, int val)
{
    int res = -1;
    while (left < right)
    {
        int mid = (left + right) / 2;
        int bound = pos + mid * sign;
        int rmqVal = RMQ(min(bound, pos), max(bound, pos));
        if (rmqVal <= val)
        {
            left = mid + 1;
            res = mid;
        }
        else
        {
            right = mid;
        }
    }
    return res;
}

ll get(int i, int left, int right, int val)
{
    int l = binary(i, -1, 0, i - left + 1, val) + 1;
    int r = binary(i, 1, 0, right - i + 1, val) + 1;
    return 1LL * l * r;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    int test = 1;
    while (T--)
    {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> c[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> d[i];
        }
        for (int i = 2; i <= n; i++)
            lg[i] = lg[i / 2] + 1;
        RMQ_process();
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && c[st.top()] <= c[i])
            {
                st.pop();
            }
            if (st.empty())
                L[i] = 0;
            else
                L[i] = st.top() + 1;
            st.push(i);
        }
        while (!st.empty())
            st.pop();
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && c[st.top()] < c[i])
            {
                st.pop();
            }
            if (st.empty())
                R[i] = n - 1;
            else
                R[i] = st.top() - 1;
            st.push(i);
        }
        ll res = 0;
        for (int i = 0; i < n; i++)
        {
            res += get(i, L[i], R[i], c[i] + k) - get(i, L[i], R[i], c[i] - k - 1);
        }
        cout << "Case #" << test++ << ": " << res << endl;
    }
}
