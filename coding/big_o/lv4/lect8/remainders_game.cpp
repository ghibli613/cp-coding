#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 10;

int isPrime[N], cntP[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    for (int i = 2; i < N; i++)
        if (!isPrime[i])
            for (int j = i; j < N; j += i)
                isPrime[j] = i;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        // cout << isPrime[x] << ' ';
        while(x > 1)
        {
        	int p = isPrime[x];
        	int cnt = 0;
        	while(x % p == 0)
        	{
        		cnt++;
        		x /= p;
                // cout << 1;
        	}
        	cntP[p] = max(cntP[p], cnt);
            // cout << 1;
        }
    }

    while(k > 1)
    {
    	if(cntP[isPrime[k]] <= 0)
        {
            cout << "NO";
            return 0;
        }
    	cntP[isPrime[k]]--;
    	k /= isPrime[k];
    }
    cout << "Yes";

    return 0;
}