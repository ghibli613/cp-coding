#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

struct cow
{
    int x, y;
    int id;
};

void solve()
{
    int n; cin >> n;
    vector<cow> n_cow, e_cow;
    for(int i = 0; i < n; i++)
    {
        char direct; cin >> direct;
        int x, y;
        cin >> x >> y;
        cow tmp = {x, y, i};
        if(direct == 'N') n_cow.push_back(tmp);
        else e_cow.push_back(tmp);
    }

    sort(e_cow.begin(), e_cow.end(), [&](const cow &a, const cow &b){return a.y < b.y;});
    sort(n_cow.begin(), n_cow.end(), [&](const cow &a, const cow &b){return a.x < b.x;});

    vector<int> result(n,-1);

    for(cow & eCow : e_cow)
    {
        for(cow & nCow : n_cow)
        {
            if(result[nCow.id] == -1 && nCow.x > eCow.x && eCow.y > nCow.y)
            {
                if(nCow.x - eCow.x < eCow.y - nCow.y)
                {
                    result[nCow.id] = eCow.y - nCow.y;
                }
                else if(nCow.x - eCow.x > eCow.y - nCow.y)
                {
                    result[eCow.id] = nCow.x - eCow.x;
                    break;
                }
            }
        }
    }

    for(int i = 0; i < (int)result.size(); i++)
        if(result[i] == -1) cout << "Infinity\n";
        else cout << result[i] << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while(t--)
        solve();

    return 0;
}