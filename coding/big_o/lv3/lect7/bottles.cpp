// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n;
//     cin >> n;
//     vector<int> a(n + 1), b(n + 1);
//     int s = 0;

//     for (int i = 1; i <= n; i++)
//     {
//         cin >> a[i];
//         s += a[i];
//     }

//     for (int i = 1; i <= n; i++)
//         cin >> b[i];

//     vector<vector<int>> dp(s + 1, vector<int>(n + 1, -1e6));
//     dp[0][0] = 0;

//     for (int i = 1; i <= n; i++)
//         for (int k = s; k >= 0; k--)
//             for (int j = i; j > 0; j--)
//                 if (dp[k][j - 1] >= 0)
//                     dp[min(s, k + b[i])][j] = max(dp[min(s, k + b[i])][j], dp[k][j - 1] + a[i]);
                    
//     for (int i = 1; i <= n; i++)
//         if (dp[s][i] >= 0)
//         {
//             cout << i << " " << s - dp[s][i];
//             break;
//         }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 101;
int a[N], b[N], dp[N][N * N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int s = 0, sumAi = 0;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
        cin >> b[i];

    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        s += b[i];
        sumAi += a[i];
        for (int j = i; j > 0; j--)
            for (int sumB = b[i]; sumB <= s; sumB++)
                if (dp[j - 1][sumB - b[i]] != -1)
                    dp[j][sumB] = max(dp[j][sumB], dp[j - 1][sumB - b[i]] + a[i]);
    }

    int j = 0, sum = 0;
    bool exist = false;            
    while (true)
    {
        for (int sumB = sumAi; sumB <= s; sumB++)
        {
            if(dp[j][sumB] != -1)
            {
                exist = 1;
                sum = max(sum, dp[j][sumB]);
            }
        }
        if(exist)
        {
            cout << j << ' ' << sumAi - sum;
            break;
        }
        j++;
    }

    return 0;
}