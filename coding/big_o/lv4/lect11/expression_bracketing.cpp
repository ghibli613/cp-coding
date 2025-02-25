#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1000000007;
const int N = 100007;

ll cat[26], supCat[27];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cat[0] = 1;
    for(int i = 0; i < 25; i++) cat[i + 1] = cat[i] * (4 * i + 2) / (i + 2);

    supCat[1] = 1;
    supCat[2] = 1;

    for(int i = 3; i < 27; i++) supCat[i] = ((6 * i - 9) * supCat[i - 1] - (i - 3) * supCat[i - 2]) / i;

    int n;

    while(cin >> n)
    {
        cout << supCat[n] - cat[n - 1] << '\n';
    }

    return 0;
}