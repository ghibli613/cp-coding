#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
    string ques, out; cin >> ques >> out;
    sort(ques.begin(), ques.end());
    if(ques[0] == '0')
    {
        int idx = 0;
        for(int i = 0; i < int(ques.size()); i++)
            if(ques[i] != '0')
            {
                idx = i;
                break;
            }
        ques[0] = ques[idx];
        ques[idx] = '0';
    }
    if(int(ques.size()) != int(out.size()))
    {
        cout << "WRONG_ANSWER";
        return;
    }
    else
    {
        for(int i = 0; i < int(ques.size()); i++)
            if(ques[i] != out[i])
            {
                cout << "WRONG_ANSWER";
                return;
            }
    }
    cout << "OK";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;

    while(t--)
        solve();

    return 0;
}