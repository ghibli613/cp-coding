#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1000000007;
const int N = 100007;

ll cat[1001][1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    for(int i = 0; i < 1001; i++)
        for(int j = 0; j <= i; j++)
        {
            if(j == 0) cat[i][j] = 1;
            else cat[i][j] = (cat[i][j - 1] + cat[i - 1][j]) % 1000000;
        }


    while(cin >> n, n != 0)
    {
        cout << cat[n][n] << "\n";
    }

    return 0;
}