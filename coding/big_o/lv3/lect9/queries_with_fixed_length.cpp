#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, q, k;
vector<int> a;

int maxKSubarray()
{
    int res = 1e9;
    deque<int> dp;
    
    for(int i = 0; i < n; i++)
    {
        if(!dp.empty() && dp.front() <= i - k)
            dp.pop_front();
        while (!dp.empty() && a[dp.back()] <= a[i])
            dp.pop_back();
        
        dp.push_back(i);
        if(i >= k - 1)
            if (a[dp.front()] < res) res = a[dp.front()];
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    a.assign(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < q; i++)
    {
        cin >> k;
        cout << maxKSubarray() << '\n';
    }

    return 0;
}