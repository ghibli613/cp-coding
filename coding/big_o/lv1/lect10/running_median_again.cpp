#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n; cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        priority_queue<ll> max_heap;
        priority_queue<ll, vector<ll>, greater<ll>> min_heap;
        while (true)
        {
            ll t;
            cin >> t;
            if (t == 0)
                break;
            else if(t == -1)
            {
                cout << max_heap.top() << '\n';
                max_heap.pop();
                if (min_heap.size() > max_heap.size())
                {
                    max_heap.push(min_heap.top());
                    min_heap.pop();
                }
            }
            else
            {
                if (max_heap.empty())
                    max_heap.push(t);
                else if (max_heap.top() < t)
                    min_heap.push(t);
                else
                    max_heap.push(t);

                if (max_heap.size() > min_heap.size() + 1)
                {
                    min_heap.push(max_heap.top());
                    max_heap.pop();
                }
                else if (min_heap.size() > max_heap.size())
                {
                    max_heap.push(min_heap.top());
                    min_heap.pop();
                }
            }
            
        }
    }

    return 0;
}