#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<int> a;

int LIS()
{
    vector<int> lis;

    for(int j, i = 0; i < n; i++)
    {
        j = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
        if(j == (int)lis.size())
        {
            lis.push_back(a[i]);
        }
        else
        {
            lis[j] = a[i];
        }
    }

    return (int)lis.size();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int tmp; cin >> tmp;
        a.push_back(tmp);
    }

    cout << LIS();

    return 0;
}