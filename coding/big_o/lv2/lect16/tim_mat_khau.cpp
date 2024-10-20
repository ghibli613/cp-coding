#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<bool> isPrime;

void sieveOfEratosthenes(int n)
{
    isPrime.assign(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i * i <= n; i++)
        if(isPrime[i])
        {
            for(int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;
    vector<bool> isNum((int)s.size(), 0);
    for(int i = 0; i < (int)s.size(); i++)
    {
        if(s[i] >= '0' && s[i] <= '9') isNum[i] = 1;
    }

    vector<bool> isOdd((int)s.size(), 0);
    for(int i = 0; i < (int)s.size(); i++)
    {
        if(isNum[i] && ((s[i] - '0') % 2 == 1)) isOdd[i] = 1;
    }

    sieveOfEratosthenes(1e5);
    int ans = 0;
    for(int i = 0; i < (int)s.size(); i++)
    {
        if(isOdd[i])
        {
            int tmp = 0, cnt = 1;
            int j = i;
            while(j >= 0 && isNum[j])
            {
                tmp += (s[j] -'0') * cnt;
                cnt *= 10;
                
                j--;
                if(isPrime[tmp])
                {
                    if(tmp > ans) ans = tmp;
                }
                if(cnt >= 1e5) break;
            }
        }
        // cout << isOdd[i];
    }
    if(ans == 0) cout << 2;
    else cout << ans;
    return 0;
}