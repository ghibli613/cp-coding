#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
	vector<tuple<string, int, int>> seg;
    int n; cin >> n;
    for(int i = 0; i < n; i++)
    {
        string s; int a, b;
        cin >> s >> a >> b;
        seg.push_back(make_tuple(s, a, b));
    }
    int seg1_min = 0, seg1_max = 0;
    bool flag = false;
    for(int i = 0; i < n; i++)
    {
        if(!flag && get<0>(seg[i]) == "none") 
        {
            flag = true;
            seg1_min = get<1>(seg[i]);
            seg1_max = get<2>(seg[i]);
        }
        if(flag)
        {
            if(get<0>(seg[i]) == "none")
            {
                ckmax(seg1_min, get<1>(seg[i]));
                ckmin(seg1_max, get<2>(seg[i]));
            }
            else if(get<0>(seg[i]) == "on")
            {
                seg1_min += get<1>(seg[i]);
                seg1_max += get<2>(seg[i]);
            }
            else
            {
                seg1_min -= get<2>(seg[i]);
                seg1_max -= get<1>(seg[i]);
            }
        }
    }
    flag = false; int seg2_min = 0, seg2_max = 0;
    for(int i = n-1; i >= 0; i--)
    {
        if(!flag && get<0>(seg[i]) == "none") 
        {
            flag = true;
            seg2_min = get<1>(seg[i]);
            seg2_max = get<2>(seg[i]);
        }
        if(flag)
        {
            if(get<0>(seg[i]) == "none")
            {
                ckmax(seg2_min, get<1>(seg[i]));
                ckmin(seg2_max, get<2>(seg[i]));
            }
            else if(get<0>(seg[i]) == "on")
            {
                seg2_min -= get<2>(seg[i]);
                seg2_max -= get<1>(seg[i]);
            }
            else
            {
                seg2_min += get<1>(seg[i]);
                seg2_max += get<2>(seg[i]);
            }
        }
    }
    cout << max(0, seg2_min) << " " << seg2_max << "\n" << max(0, seg1_min) << " " << seg1_max;
    cout << '\n';
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
