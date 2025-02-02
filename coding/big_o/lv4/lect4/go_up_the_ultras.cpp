#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n)
    {
        vector<int> h(n), a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> h[i];
            a[i] = h[i];
        }

        stack<pair<int, int>> stk;
        for (int i = 0; i < n; i++)
        {
            while (!stk.empty() && stk.top().first <= h[i])
            {
                pair<int, int> p = stk.top();
                stk.pop();
                if (!stk.empty())
                    stk.top().second = min(stk.top().second, p.second);
            }
            if (!stk.empty())
                a[i] = min(a[i], h[i] - stk.top().second);
            
            stk.push(make_pair(h[i], h[i]));
        }

        while (!stk.empty())
            stk.pop();

        for (int i = n - 1; i >= 0; i--)
        {
            while (!stk.empty() && stk.top().first <= h[i])
            {
                pair<int, int> p = stk.top();
                stk.pop();
                if (!stk.empty())
                    stk.top().second = min(stk.top().second, p.second);
            }
            if (!stk.empty())
                a[i] = min(a[i], h[i] - stk.top().second);
            
            stk.push(make_pair(h[i], h[i]));
        }

        for (int i = 0; i < n; i++)
            if (a[i] >= 150000)
                cout << i + 1 << " ";
        cout << '\n';;
    }
    return 0;
}