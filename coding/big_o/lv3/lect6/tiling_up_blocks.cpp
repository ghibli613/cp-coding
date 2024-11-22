#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> pii;
vector<int> A;

int LIS()
{
    int n = A.size();
    vector<int> lis;

    for(int j, i = 0; i < n; i++)
    {
        j = upper_bound(lis.begin(), lis.end(), A[i]) - lis.begin();

        if(j == (int)lis.size())
        {
            lis.push_back(A[i]);
        }
        else
        {
            lis[j] = A[i];
        }
    }

    return (int)lis.size();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    while(true)
    {
        cin >> n;
        if(n == 0) break;
        vector<pii> a;
        for(int i = 0; i < n; i++)
        {
            int l, m; cin >> l >> m;
            a.push_back({l, m});
        }
        sort(a.begin(), a.end());
        
        A.clear();
        for(int i = 0; i < n; i++)
            A.push_back(a[i].second);
        
        cout << LIS() << '\n';
    }
    cout << '*';

    return 0;
}