#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

void solve()
{
    int n; cin >> n;
    vector<pair<ll, ll>> segments(n);
    for(int i = 0; i < n; i++)
        cin >> segments[i].second >> segments[i].first;
    sort(segments.begin(), segments.end());
    ordered_set st;
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans += st.size() - st.order_of_key(segments[i].second);
        st.insert(segments[i].second);
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while(t--)
        solve();

    return 0;
}