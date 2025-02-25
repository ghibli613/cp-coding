#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1000000007;
const int N = 100007;

ll cat[11];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cat[0] = 1;

    for(int i = 0; i < 10; i++) cat[i + 1] = cat[i] * (4 * i + 2) / (i + 2);

    while(cin >> n)
    {
        cout << cat[n] << "\n\n";
    }

    return 0;
}