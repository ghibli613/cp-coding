#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<int> a;

int merge(int l, int m, int r)
{
    
    vector<int> b(a.begin() + l, a.begin() + m + 1);
    vector<int> c(a.begin() + m + 1, a.begin() + r + 1);
    
    int nB = m - l + 1, nC = r - m;
    int i = 0, j = 0, k = l;
    int cnt = 0;
    
    while(i < nB && j < nC)
    {
        if(b[i] > c[j])
            a[k++] = c[j++];
        else
        {
            a[k++] = b[i++];
            cnt += j;
        }
    }
    
    while(i < nB)
    {
        a[k++] = b[i++];
        cnt += j;
    }
    while(j < nC)
        a[k++] = c[j++];
    return cnt;
}

int countInversions(int l, int r)
{
    
    if(l >= r) return 0;
    int m = (l + r) / 2;

    int countLeft = countInversions(l, m);
    int countRight = countInversions(m + 1, r);
    
    int countMid = merge(l, m, r);
    return countLeft + countRight + countMid;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    a.assign(n, 0);

    for(int i = 0; i < n; i++) cin >> a[i];

    cout << countInversions(0, n - 1);

    return 0;
}