#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void LIS(vector<int>& A)
{
    int n = A.size();
    vector<int> lis, lis_index;
    vector<int> dp;
    vector<int> prev;
    dp.assign(n, 1);
    prev.assign(n, -1);
    
    for(int j, i = 0; i < n; i++)
    {
        j = lower_bound(lis.begin(), lis.end(), A[i]) - lis.begin();
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

    vector<int> b;
    int pos = lis_index[(int)lis.size() - 1];
    while(pos != -1)
    {
        b.push_back(A[pos]);
        pos = prev[pos];
    }
    
    cout << "Max hits: " << (int)lis.size() << '\n';
    for(int i = (int)b.size() - 1; i >= 0; i--)
        cout << b[i] << '\n';
    cout << '\n';

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    getline(cin, s);
    int t = stoi(s);
    getline(cin, s);

    for(int i = 0; i < t; i++)
    {
        vector<int> a;
        while (true)
        {
            getline(cin, s);
            if(s == "") break;
            a.push_back(stoi(s));
        }
        
        LIS(a);
    }

    return 0;
}