#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> a, previous;

int LIS()
{
    int n = a.size();
    vector<int> lis, lis_index;
    previous.assign(n, -1);

    for(int j, i = 0; i < n; i++)
    {
        j = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();

        if(j != 0)
        {
            previous[i] = lis_index[j - 1];
        }
        if(j == (int)lis.size())
        {
            lis.push_back(a[i]);
            lis_index.push_back(i);
        }
        else
        {
            lis[j] = a[i];
            lis_index[j] = i;
        }
    }
    cout << (int)lis.size() << "\n-\n";
    return lis_index[(int)lis.size() - 1];
}

void trace(int pos)
{
    vector<int> b;
    while(pos != -1)
    {
        b.push_back(a[pos]);
        pos = previous[pos];
    }

    for(int i = (int)b.size() - 1; i >= 0; i--)
        cout << b[i] << '\n';
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tmp;

    while(cin >> tmp)
    {
        a.push_back(tmp);
    }

    int pos = LIS();
    trace(pos);

    return 0;
}